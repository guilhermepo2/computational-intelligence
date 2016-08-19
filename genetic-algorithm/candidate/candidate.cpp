#include "candidate.hpp"

Candidate::Candidate(int valuesSize)
{
  this->values = new int[valuesSize];
  for(int i = 0; i < valuesSize; i++) this->values[i] = 0;
  this->fitness = 0;
  this->size = valuesSize;
}

void Candidate::createRandomCandidate()
{
  
}

int Candidate::getFitness()
{
  return 0;
}

void Candidate::calcFitness()
{
  
}

void Candidate::printCandidate()
{
  std::cout << "Candidate: ";
  
  for(int i = 0; i < this->size; i++)
    {
      std::cout << this->values[i] << " ";
    }
  std::cout << std::endl;
  std::cout << "Fitness: " << this->fitness << std::endl;
}

int Candidate::getSize()
{
  return this->size;
}

