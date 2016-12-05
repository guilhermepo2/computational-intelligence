class Ant():
    def __init__(self):
        self.walk = []    # cities that the ant will go on
        self.cost = 0     # walk cost
        # print "ant initiated!"

    def get_walk(self):
        return self.walk

    def add_city(self, city):
        self.walk.append(city)

    def get_current_city(self):
        return self.walk[len(self.walk)-1]

    def set_cost(self, cost):
        self.cost = cost
        
    def get_cost(self):
        return self.cost

    def reinitiate(self):
        self.walk = []
        self.cost = 0

def tests():
    a = Ant()
    print "Current walk: " + str(a.get_walk())
    print "Adding the city 2"
    a.add_city(2)
    print "Current city: " + str(a.get_current_city())
    print "Adding the city 3 and 1"
    a.add_city(3)
    a.add_city(1)
    print "Current city: " + str(a.get_current_city())
    print "Current walk: " + str(a.get_walk())

if __name__ == '__main__':
    tests()
