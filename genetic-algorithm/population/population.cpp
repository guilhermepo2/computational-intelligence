#include "population.hpp"

Population::Population(std::string op1,
		       std::string op2,
		       std::string result,
		       int populationSize,
		       int generations,
		       int problemSize,
		       float crossoverRate,
		       float mutationRate)
{
  this->op1 = op1;
  this->op2 = op2;
  this->result = result;
 
  this->populationSize = populationSize;
  this->generations = generations;
  this->problemSize = problemSize;
  this->crossoverRate = crossoverRate;
  this->mutationRate = mutationRate;
  this->inicialized = false;

  for(int i = 0; i < populationSize; i++)
    {
      candidates.push_back(Candidate(10,this->op1,this->op2,this->result));
    }
}

void Population::createPopulation()
{
  if(!this->inicialized)
  {
    for(int i = 0; i < this->populationSize; i++)
      {
	candidates[i].createRandomCandidate();
      }
    this->inicialized = true;
  }
}

void Population::calculatePopulationFitness()
{
  for(int i = 0; i < this->populationSize; i++)
    {
      candidates[i].calcFitness();
    }
}

void Population::bubbleSort()
{
  Candidate c(10, "SEND", "MORE", "MONEY");
  
  for(int i = 0; i < this->populationSize; i++)
    {
      for(int j = 0; j < this->populationSize; j++)
	{
	  if(candidates[i].getFitness() < candidates[j].getFitness())
	    {
	      c = candidates[i];
	      candidates[i] = candidates[j];
	      candidates[j] = c;
	    }
	}
    }
}

void Population::printAllFitness()
{
  for(int i = 0; i < this->populationSize; i++)
    {
      std::cout << "Candidate " << i
		<< " Fitness: " << candidates[i].getFitness()
		<< std::endl;
    }
}

void Population::printEverything()
{
  for(int i = 0; i < this->populationSize; i++)
    {
      candidates[i].printCandidate();
    }
}

void Population::printBestFitness()
{
  std::cout << "Best Fitness: " << candidates[0].getFitness()
	    << std::endl;
}
