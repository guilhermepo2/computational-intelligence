#include "population.hpp"
#include <time.h>

int main()
{
  srand(time(NULL));
  
  Population pop("SEND", "MORE", "MONEY", 100, 1, 10, 0.6, 0.01);
  Population children("SEND", "MORE", "MONEY", 60, 1, 10, 0.0, 0.01);
  pop.createPopulation();               // OK
  pop.calculatePopulationFitness();     // OK
  pop.bubbleSort();
  pop.printAllFitness();
  
  for(int i = 0; i < (children.getSize() / 2); i++)
    {
      pop.crossover(&children);         // OK
    }
  children.mutateOneRandom();           // OK
  pop.elitism(&children);               // OK
  pop.printAllFitness();                

  std::cout << "\nBest Candidate: " << std::endl;
  pop.printBestCandidate();

  std::cout << "One iteration done!" << std::endl;
  return 0;
}
