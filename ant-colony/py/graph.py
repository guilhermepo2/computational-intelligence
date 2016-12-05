# Formato de um arquivo de instancia do problema do caixeiro viajante
# Primeira Linha: Tipo de informacao (matriz completa, triangulo superior, coordenadas...)
# Segunda Linha: Numero de Cidades
# Terceira Linha: Informacao
#

# Classe Grafo
#
# Atributos:
# Quantidade de Cidades
# Matriz de Adjacencias
#

from math import sqrt

def distance(x1, y1, x2, y2):
    x = ((x2 - x1) ** 2)
    y = ((y2 - y1) ** 2)
    d = sqrt(x+y)

    return d


class Graph(object):

    def __init__(self, file):
        f = open(file, 'r')
        lines = f.readlines()

        self.cities = int(lines[1])
        self.adj_list = [[0 for x in range(self.cities)] for y in range(self.cities)]

        if lines[0].rstrip('\n') == "superior_triangle":
            # print "superior triangle!"

            splitted = lines[2].split()
            splitted_index = 0

            for i in range(self.cities):
                for j in range((i+1), self.cities):
                    self.adj_list[i][j] = int(splitted[splitted_index])
                    self.adj_list[j][i] = int(splitted[splitted_index])
                    splitted_index = splitted_index + 1

        elif lines[0].rstrip('\n') == "coordenates":
            cities = []
            # print "coordinates!"
            for i in range(2, len(lines)):
                l = lines[i].rstrip('\n').split()
                cities.append((float(l[0]), float(l[1])))
            # print cities

            for i in range(self.cities):
                for j in range((i+1), self.cities):
                    self.adj_list[i][j] = distance(cities[i][0], cities[i][1], cities[j][0], cities[j][1])
                    self.adj_list[j][i] = distance(cities[i][0], cities[i][1], cities[j][0], cities[j][1])

    def print_adj_matrix(self):
        for i in range(self.cities):
            print self.adj_list[i]

    def get_cities(self):
        return self.cities

    def visit_city(self, x, y):
        return self.adj_list[x][y]


def tests():
    print "Executing tests."
    g = Graph("instances/m38.txt")

    print "Cities in the graph: " + str(g.get_cities())
    print "Adjascency List:"
    print g.print_adj_matrix()

    print "visiting Faro from Aveiro: " + str(g.visit_city(0, 2))

    print "Testing Done."

if __name__ == '__main__':
    tests()
