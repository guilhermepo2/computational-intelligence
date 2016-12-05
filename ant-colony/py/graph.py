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
            print "coordinates!"

    def print_adj_matrix(self):
        for i in range(self.cities):
            print self.adj_list[i]

    def get_cities(self):
        return self.cities

    def visit_city(self, x, y):
        return self.adj_list[x][y]


def tests():
    print "Executing tests."
    g = Graph("instances/m6.txt")

    print "Cities in the graph: " + str(g.get_cities())
    print "Adjascency List:"
    print g.print_adj_matrix()

    print "visiting Faro from Aveiro: " + str(g.visit_city(0, 2))

    print "Testing Done."

if __name__ == '__main__':
    tests()
