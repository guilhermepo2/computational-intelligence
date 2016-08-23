#include "population.hpp"

Population::Population(std::string op1,
		       std::string op2,
		       std::string result,
		       int populationSize,
		       int problemSize)
{
  this->op1 = op1;
  this->op2 = op2;
  this->result = result;
 
  this->populationSize = populationSize;
  this->problemSize = problemSize;
  this->inicialized = false;
}

void Population::createPopulation()
{
  if(!this->inicialized)
  {
    for(int i = 0; i < this->populationSize; i++)
    {
      candidates.push_back(Candidate(10,this->op1,this->op2,this->result));
    }
    
    for(int i = 0; i < this->populationSize; i++)
      {
	candidates[i].createRandomCandidate();
      }
    this->inicialized = true;
  }
}

void Population::calculatePopulationFitness()
{
  for(int i = 0; i < this->candidates.size(); i++)
    {
      candidates[i].calcFitness();
    }
}

void Population::bubbleSort()
{
  Candidate c(this->problemSize, this->op1, this->op2, this->result);
  for(int i = 0; i < this->candidates.size(); i++)
    {
      for(int j = 0; j < this->candidates.size(); j++)
	{
	  if(candidates[i].getFitness() > candidates[j].getFitness())
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
  for(int i = 0; i < this->candidates.size(); i++)
    {
      std::cout << "Candidate " << i
		<< " Fitness: " << candidates[i].getFitness()
		<< std::endl;
    }
}

void Population::printEverything()
{
  for(int i = 0; i < this->candidates.size(); i++)
    {
      candidates[i].printCandidate();
    }
}

void Population::printBestCandidate()
{
  candidates[0].printCandidate();
}

void Population::insertCandidate(Candidate candidate)
{
  if(this->candidates.size() < this->populationSize)
    this->candidates.push_back(candidate);
}

int Population::tournamentSelection()
{
  int first = rand() % this->populationSize;
  int second = rand() % this->populationSize;
  int third = rand() % this->populationSize;

  #if DEBUG

  std::cout << "First One fitness: " << this->candidates[first].getFitness()
	    << std::endl;

  std::cout << "Second One fitness: " << this->candidates[second].getFitness()
	    << std::endl;

  std::cout << "Third One fitness: " << this->candidates[third].getFitness()
	    << std::endl;

  std::cout << "Let them fight!" << std::endl;

  #endif

  // let them fight
  int winner;
  if(this->candidates[first].getFitness() > this->candidates[second].getFitness())
    winner = first;
  else winner = second;

  if(this->candidates[winner].getFitness() < this->candidates[third].getFitness())
    winner = third;

  #if DEBUG
  std::cout << "Winner is: " << this->candidates[winner].getFitness() << std::endl;
  #endif
  
  return winner;
}

void Population::crossover(Population * children)
{
  int parent1 = tournamentSelection();
  int parent2 = tournamentSelection();

  // GETTING THE CYCLE THING

  int crossoverPoint = rand() % this->problemSize;
  std::vector<int> cycle;

  // get crossover point value from parent1 and push on cycle
  // also get crossover point value from parent2 and push on the cycle
  cycle.push_back(this->candidates[parent1].getValue(crossoverPoint));
  cycle.push_back(this->candidates[parent2].getValue(crossoverPoint));

  #if DEBUG
  std::cout << "CYCLE: " << std::endl;
  std::cout << "============================" << std::endl;
  for(int i = 0; i < cycle.size(); i++)
    {
      std::cout << cycle[i] << " ";
    }
  std::cout << std::endl;
  std::cout << "============================" << std::endl;
  #endif
  
  // while cycle is not closed...
  while(cycle[0] != cycle[cycle.size()-1])
    // search for parent 1 position which has the same value for the parent 2 crossover point, push to the cycle the parent 2 value for the position found
  {
    crossoverPoint = this->candidates[parent1].
      getPositionForValue(cycle[cycle.size()-1]);
    
    cycle.push_back(this->candidates[parent2].getValue(crossoverPoint));
  }

#if DEBUG
  std::cout << "CYCLE: " << std::endl;
  std::cout << "============================" << std::endl;
  for(int i = 0; i < cycle.size(); i++)
    {
      std::cout << cycle[i] << " ";
    }
  std::cout << std::endl;
  std::cout << "============================" << std::endl;
  #endif
  
  #if DEBUG
  std::cout << "============================" << std::endl;
  std::cout << "Parent 1 INFO" << std::endl;
  this->candidates[parent1].printCandidate();
  std::cout << "============================" << std::endl;
  #endif

  // CYCLE IS FINISHED

  // trade parent 1 position with parent 2 position for each value on the cycle
  // search position in parent 1 for a value in the cycle
  // trade the values on this position between parent 1 and parent 2
  // dont do that for the last cycle value

  // childrens should be created by manually copying them, not by = operator
  // creating children
  Candidate children1(this->candidates[parent1].getSize(),
		      this->candidates[parent1].getWord1(),
		      this->candidates[parent1].getWord2(),
		      this->candidates[parent1].getResultWord());
  Candidate children2(this->candidates[parent2].getSize(),
		      this->candidates[parent2].getWord1(),
		      this->candidates[parent2].getWord2(),
		      this->candidates[parent2].getResultWord());

  //copying
  for(int i = 0; i < children1.getSize(); i++)
    {
      int valueForC1 = this->candidates[parent1].getValue(i);
      int valueForC2 = this->candidates[parent2].getValue(i);
      children1.setValueForPosition(i, valueForC1);
      children2.setValueForPosition(i, valueForC2);
    }
  
  // actually doing the crossover
  for(int i = 0; i < cycle.size()-1; i++)
    {
      int position = this->candidates[parent1].getPositionForValue(cycle[i]);
      // trade the position on the children

      // getting the values for the position
      int valueChildren1 = children1.getValue(position);
      int valueChildren2 = children2.getValue(position);

      // PLEASE TRADE THEM
      // children 2 on position should be value children 1
      children2.setValueForPosition(position, valueChildren1);
      // children 1 on position should be value children 2
      children1.setValueForPosition(position, valueChildren2);
    }

  children1.calcFitness();
  children2.calcFitness();
  // HERE IT SHOULD BE WORKING..

  #if DEBUG
  std::cout << "============================" << std::endl;
  std::cout << "CROSSOVER RESULT" << std::endl;

  std::cout << "CYCLE: " << std::endl;
  for(int i = 0; i < cycle.size(); i++)
    {
      std::cout << cycle[i] << " ";
    }
  std::cout << "\n" << std::endl;
  std::cout << "PARENT 1" << std::endl;
  this->candidates[parent1].printLettersAndValues();
  std::cout << "PARENT 2" << std::endl;
  this->candidates[parent2].printLettersAndValues();
  std::cout << "CHILDREN 1" << std::endl;
  children1.printLettersAndValues();
  std::cout << "CHILDREN 2" << std::endl;
  children2.printLettersAndValues();
  std::cout << "============================" << std::endl;
  #endif

  // here I have two children, what to do now?
  // push them to the beta population!
  children->insertCandidate(children1);
  children->insertCandidate(children2);
}

void Population::mutateOneRandom()
{
  int chosen = rand() % this->populationSize;
  this->candidates[chosen].mutate();
}

void Population::elitism(Population * children)
{
  this->bubbleSort();
  children->bubbleSort();

  for(int i = 0; i < children->getSize(); i++)
    {
      if(children->candidates[i].getFitness() >
	 this->candidates[this->populationSize - 1].getFitness())
	{
	  for(int j = 0;
	      j < this->candidates[this->populationSize - 1].getSize();
	      j++)
	    {
	      this->candidates[this->populationSize - 1].setValueForPosition(j,
									     children->candidates[i].getValue(j));

	      this->candidates[this->populationSize-1].calcFitness();
	    }

	  this->bubbleSort();
	}
    }
  
}

int Population::getSize()
{
  return this->populationSize;
}
