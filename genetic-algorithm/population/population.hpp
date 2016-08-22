#ifndef POPULATION_HEADER
#define POPULATION_HEADER
#include "../candidate/candidate.hpp"
#include <vector>

class Population
{
private:
  // words
  std::string op1;
  std::string op2;
  std::string result;
  
  // population data (get by command line)
  int populationSize;
  int generations;
  int problemSize;
  float crossoverRate;
  float mutationRate;

  // internal data
  bool inicialized;
  std::vector<Candidate> candidates;
  
public:
  Population(std::string op1,
	     std::string op2,
	     std::string result,
	     int populationSize,
	     int generations,
	     int problemSize,
	     float crossoverRate,
	     float mutationRate);
  void createPopulation();
  void printAllFitness();
  void calculatePopulationFitness();
  void bubbleSort();
  void printBestCandidate();
  void printEverything();
  void insertCandidate(Candidate candidate);
  int getSize();
  int tournamentSelection();
  void crossover(Population * children);
  void mutateOneRandom();
  void elitism(Population * children);
};

#endif
