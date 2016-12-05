from graph import Graph
from ant import Ant
from math import ceil
from random import randint
from random import seed

INITIAL_PHEROMONE = 1         # feromonio inicial
ALPHA = 1                     # alfa
BETA = 1                      # beta
ATTEMPTS = 50                 # maximo de tentativas
SECRETED_PHEROMONE = 1        # Q
EVAPORATION_COEFFICIENT = 0.5 # p

class ACO():
    def __init__(self, file):
        self.graph = Graph(file)
        self.ants = [Ant() for x in range(self.graph.get_cities())]
        self.pheromone_matrix = [[INITIAL_PHEROMONE for x in range(self.graph.get_cities())] for y in range(self.graph.get_cities()) ]
        for i in range(self.graph.get_cities()):
            self.pheromone_matrix[i][i] = 0

    def show_ant_walks(self):
        for each in self.ants:
            print each.get_walk()

    def show_pheromone_matrix(self):
        for each in self.pheromone_matrix:
            print each



    def roulette(self, probability_vector):
        # print "im on roulette function!"
        v = [1000 for x in range(len(probability_vector))]
        v[0] = ceil(v[0] * probability_vector[0])

        for i in range(1, len(probability_vector)):
            v[i] = ceil(v[i-1] + (v[i] * probability_vector[i]))

        seed()
        x = randint(0, v[len(v)-1])

        chosen_number = -1
        for i in range(len(v)):
            if v[i] > x:
                chosen_number = i
                break

        # print "chosen number: " + str(chosen_number)
        # print str(v)
        return chosen_number

    def build_walk(self):

        # for each ant...
        for ant in self.ants:
            # getting possible ants to add to walk
            possible_cities = [x for x in range(self.graph.get_cities())]
            walk = ant.get_walk()
            # print walk
            for each in walk:
                possible_cities.remove(each)
            # print possible_cities
            # possible_cities -> have the cities that the ant can go.

            while(len(possible_cities) > 0):
                # getting the distances to each possible city
                distances = []
                # calculating transition probabilities
                pij = []
                pheromone_trail = []

                for each in possible_cities:
                    distances.append(self.graph.visit_city(ant.get_current_city(), each))

                for i in possible_cities:
                    pheromone_trail.append(self.pheromone_matrix[ant.get_current_city()][i])

                for i in possible_cities:
                    # print str(self.pheromone_matrix[ant.get_current_city()][i]) + "^" + str(ALPHA) + " * " + str(float(1)/float((self.graph.visit_city(ant.get_current_city(),i)))) + " ^ " + str(BETA)
                    upper_part = (pow(self.pheromone_matrix[ant.get_current_city()][i] , ALPHA) * pow( (float(1)/float(self.graph.visit_city(ant.get_current_city(), i))) , BETA))
                    exp_phe = [x ** ALPHA for x in pheromone_trail]
                    inverse_dist = [(float(1)/float(x)) for x in distances]
                    exp_inv_dist = [x ** BETA for x in inverse_dist]
                    # print "EXP PHE: " + str(exp_phe)
                    bottom_part = 0
                    #calculate bototm part
                    for i in range(len(exp_phe)):
                        bottom_part = bottom_part + (exp_phe[i] * exp_inv_dist[i])

                    # print "upper part: " + str(upper_part)
                    # print "bottom part: " + str(bottom_part)
                    pij.append(upper_part/bottom_part)
                # AT THIS POINT I HAVE THE PROBABILITY OF GOING TO EACH POSSIBLE CITY
                # print "transition probability: " + str(pij)
                # print "sum of probabilities: " + str(sum(pij))

                # I have pij a vector with the probabilities of going from i to j.
                # i = ant current city
                # j = city
                # if k is an index pij[k] is the probability of going to the city possible_cities[k]

                # getting a position given the probability vector
                chosen_pos = self.roulette(pij)
                # print "possible cities: " + str(possible_cities)
                # print "chosen_pos: " + str(possible_cities[chosen_pos])
                ant.add_city(possible_cities[chosen_pos])
                possible_cities.remove(possible_cities[chosen_pos])

    def calculate_results(self):
        best = 999999999999999
        # see for each ant what is the path and calculate its cost
        for ant in self.ants:
            walk = ant.get_walk()
            cost = 0
            cost = cost + self.graph.visit_city(walk[0], walk[1])
            for i in range(1, len(walk)):
                cost = cost + self.graph.visit_city(walk[i-1], walk[i])
            cost = cost + self.graph.visit_city(walk[len(walk)-1], walk[0])

            ant.set_cost(cost)
            if cost < best:
                best = cost

        return best

    def update_pheromones(self):
        #print "update"

        # evaporating...
        # print self.pheromone_matrix
        for origin in range(len(self.pheromone_matrix)):
            for destiny in range(len(self.pheromone_matrix)):
                if origin != destiny:
                    self.pheromone_matrix[origin][destiny] = self.pheromone_matrix[origin][destiny] * EVAPORATION_COEFFICIENT


        # adding excreted pheromones
        for ant in self.ants:
            walk = ant.get_walk()
            delta_ph = float(SECRETED_PHEROMONE) / float(ant.get_cost())
            self.pheromone_matrix[walk[0]][walk[1]] += delta_ph
            for i in range(1, len(walk)):
                self.pheromone_matrix[walk[i-1]][walk[i]] += delta_ph
            self.pheromone_matrix[walk[len(walk)-1]][0] += delta_ph

        # setting diagonals to 0 (just in case...)
        for i in range(len(self.pheromone_matrix)):
            self.pheromone_matrix[i][i] = 0

        #for each in self.pheromone_matrix:
        #    print each

    def restart_ants(self):
        for each in self.ants:
            each.reinitiate()


    def initialize_ACO(self):
        best_walks = []

        print "Initializing ACO"
        for k in range(ATTEMPTS):
            # puts all ants on a starting city
            for i in range(len(self.ants)):
                self.ants[i].add_city(i)

            # build the path for each ant
            self.build_walk()                   # WALK IS CALCULATED CORRECTLY!
            # show walks
            # self.show_ant_walks()

            # store best result
            best_walks.append(self.calculate_results())
            # update pheromones
            self.update_pheromones()
            # restart ants to do it all again
            self.restart_ants()

        print "ACO Done."
        print "Best walk for each iteration:"
        print str(best_walks)
        print "Best Walk overwall: " + str(min(best_walks))


def tests():
    print "Executing Tests."
    aco = ACO("instances/m6.txt")
    aco.initialize_ACO()
    aco.show_pheromone_matrix()
    #aco.show_ant_walks()
    print "Testing Done."

def execute_aco():
    aco = ACO("instances/m6.txt")
    aco.initialize_ACO()
    aco.show_pheromone_matrix()

if __name__ == '__main__':
    execute_aco()
