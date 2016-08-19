#include "population.hpp"
#include <time.h>

int main()
{
  srand(time(NULL));
  
  Population pop("SEND", "MORE", "MONEY", 100, 1, 10, 0.6, 0.01);
  pop.createPopulation();
  pop.calculatePopulationFitness();

  // crossover (tournament selection)
  // mutation
  
  pop.bubbleSort();
  pop.printAllFitness();
  pop.printBestFitness();

  std::cout << "ok!" << std::endl;
  return 0;
}
