#include "population.hpp"
#include <time.h>

int main()
{
  srand(time(NULL));
  
  Population pop("SEND", "MORE", "MONEY", 100, 1, 10, 0.6, 0.01);
  Population children("SEND", "MORE", "MONEY", 60, 1, 10, 0.0, 0.01);
  pop.createPopulation();
  pop.calculatePopulationFitness();

  // crossover (tournament selection)
  // mutation
  
  pop.bubbleSort();
  pop.printAllFitness();

  pop.crossover(&children);

  std::cout << "\nBest Candidate: " << std::endl;
  pop.printBestCandidate();

  std::cout << "\nok!" << std::endl;
  return 0;
}
