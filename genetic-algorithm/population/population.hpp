#ifndef POPULATION_HEADER
#define POPULATION_HEADER
#include "../candidate/candidate.hpp"

class Population
{
private:
  // words
  std::string op1;
  std::string op2;
  std::string result;
  
  // population data (get by command line)
  int populationSize;
  //int generations;
  int problemSize;
  //float crossoverRate;
  //float mutationRate;

  // internal data
  bool inicialized;
  std::vector<Candidate> candidates;
  #if ROULETTE
  int biggestWheelValue;
  #endif
  
public:
  inline int getPopulationSize() const { return this->populationSize; }
  inline int getCandidatesCount() const { return this->candidates.size(); }
  Population(std::string op1,
	     std::string op2,
	     std::string result,
	     int populationSize,
	     int problemSize);

  bool verifyNotRepeated(int pos);
    
  void createPopulation();
  void printAllFitness();
  void calculatePopulationFitness();
  
  void bubbleSort();
  void quickSort(int l, int r);
  
  void printBestCandidate();
  void printEverything();
  void insertCandidate(Candidate candidate);
  void killEveryone();
  int getSize();
  
  #if ROULETTE
  int rouletteSelection();
  void setWheelValues();
  #endif
  
  int tournamentSelection();
  
  void cyclic_crossover(Population * children);
  void pmx_crossover(Population * children);
  
  void mutateOneRandom();
  void reinsertion(Population * children);
  void elitism(Population * children);
  void saveData(std::string url);
  int getBestFitness();
};

#endif
