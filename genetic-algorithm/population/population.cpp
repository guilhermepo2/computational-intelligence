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
#if ROULETTE
  this->biggestWheelValue = 0;
#endif
}

bool Population::verifyNotRepeated(int pos)
{
  bool repeated = false;
  for(int i = 0; i < pos; i++)
    {
      repeated = true;
      for(int j = 0; j < this->problemSize; j++)
	{
	  
	  if(candidates[i].getValue(j) != candidates[pos].getValue(j))
	    repeated = false;
	}

      if(repeated)
	break;
    }

  return repeated;
}

void Population::createPopulation()
{
  if(!this->inicialized)
  {
    for(int i = 0; i < this->populationSize; i++)
    {
      candidates.push_back(Candidate(this->problemSize,this->op1,this->op2,this->result));
    }
    
    for(int i = 0; i < this->populationSize; i++)
      {
	candidates[i].createRandomCandidate();
	if(this->verifyNotRepeated(i))
	  i--;
      }
    this->inicialized = true;
  }

  this->calculatePopulationFitness();
}

void Population::calculatePopulationFitness()
{
  for(int i = 0; i < this->candidates.size(); i++)
    {
      candidates[i].calcFitness();
    }
}

/*
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
    } */

void Population::quickSort(int l, int r)
{
  int i, j;
  i = l;
  j = r;

  Candidate c(this->problemSize, this->op1, this->op2, this->result);
  Candidate c2(this->problemSize, this->op1, this->op2, this->result);

  c = this->candidates[(l+r)/2];

  while(i <= j)
    {
      while(this->candidates[i].getFitness() > c.getFitness() && i < r)
	i++;

      while(this->candidates[j].getFitness() < c.getFitness() && j > l)
	j--;

      if(i <= j)
	{
	  c2 = this->candidates[i];
	  this->candidates[i] = this->candidates[j];
	  this->candidates[j] = c2;
	  i++;
	  j--;
	}
    }

  if(j > l)
    {
      this->quickSort(l, j);
    }
  if(i < r)
    {
      this->quickSort(i, r);
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

void Population::killEveryone()
{
#if DEBUG
  std::cout << "before cleaning Candidates count: " << this->candidates.size() << std::endl;
#endif
  this->candidates.clear();
#if DEBUG
  std::cout << "after cleaning Candidates count: " << this->candidates.size() << std::endl;
#endif
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

#if ROULETTE
int Population::rouletteSelection()
{
#if DEBUG
  std::cout << "Selecionando pela roleta!" << std::endl;
#endif

#if DEBUG
      std::cout << "biggest wheel value: " << this->biggestWheelValue << std::endl;
#endif
  
  int wheelPocket = rand() % this->biggestWheelValue;
  int chosenOne = 0;
  int i = 0;
  
#if DEBUG
  std::cout << "WheelPocket: " << wheelPocket << std::endl;
#endif
  
  while(this->candidates[i].getRouletteValue() < wheelPocket)
    {
      chosenOne = i;
      i++;
    }

  return chosenOne;
}

void Population::setWheelValues()
{
#if DEBUG
  std::cout << "Colocando os valores de roleta!" << std::endl;
#endif
  
  this->candidates[0].setRouletteValue(this->candidates[0].getFitness());
  
  for(int i = 1; i < this->populationSize; i++)
    {
      this->candidates[i].setRouletteValue(this->candidates[i-1].getRouletteValue() + this->candidates[i].getFitness());
#if DEBUG
      std::cout << "candidate fitness: " << this->candidates[i].getFitness() << std::endl;
      std::cout << "wheel pocket value: " << this->candidates[i].getRouletteValue() << std::endl;
#endif
    }
  
  this->biggestWheelValue = this->candidates[this->populationSize - 1].getRouletteValue();
}
#endif


void Population::pmx_crossover(Population * children)
{
  #if DEBUG_PMX
  std::cout << "=============================================================" << std::endl;
  #endif
  int parent1, parent2;
  #if ROULETTE
  #if DEBUG
  std::cout << "Selecao por roleta!" << std::endl;
  #endif
  this->setWheelValues();
  parent1 = rouletteSelection();
  parent2 = rouletteSelection();
  #else
  #if DEBUG
  std::cout << "Selecao por torneio!" << std::endl;
  #endif
  parent1 = tournamentSelection();
  parent2 = tournamentSelection();
  #endif

  // Primeiro seleciona-se uma seção no cromossomo (através de 2 Pontos de Crossover), onde o material genético dos 2 pais será integralmente trocado.

#if DEBUG
  std::cout << "Selecionei! Agora PMX!" << std::endl;
#endif
  
  int crossoverPoint1 = rand() % this->problemSize;
  int crossoverPoint2 = rand() % this->problemSize;

  if(crossoverPoint1 > crossoverPoint2)
    {
      int aux = crossoverPoint1;
      crossoverPoint1 = crossoverPoint2;
      crossoverPoint2 = aux;
    }

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

  #if DEBUG_PMX
  std::cout << "crossover point 1: " << crossoverPoint1 << " crossover point 2: " << crossoverPoint2 << std::endl;
  #endif

  for(int i = crossoverPoint1; i < crossoverPoint2; i++)
    {
      #if DEBUG_PMX
      std::cout << "iteracao i = " << i << std::endl;
      children1.printCandidate();
      children2.printCandidate();
      #endif
      // get the values
      int valueChildren1 = children1.getValue(i);
      int valueChildren2 = children2.getValue(i);

        #if DEBUG_PMX
  std::cout << "value children 1: " << valueChildren1 << " value children 2: " << valueChildren2 << std::endl;
  #endif

      // antes de trocar eu verifico onde esta o valor do children2 no children1 e troco pelo valor do children1 que esta dentro do crossover
      int collisionPositionChildren1 = this->candidates[parent1].getPositionForValue(valueChildren2);
      int collisionPositionChildren2 = this->candidates[parent2].getPositionForValue(valueChildren1);
      
#if DEBUG_PMX
      std::cout << "collision point 1: " << collisionPositionChildren1 << " collision point 2: " << collisionPositionChildren2 << std::endl;
#endif

      children1.setValueForPosition(collisionPositionChildren1, valueChildren1);
      children2.setValueForPosition(collisionPositionChildren2, valueChildren2);

      // now trade them
      children2.setValueForPosition(i, valueChildren1);
      children1.setValueForPosition(i, valueChildren2);
    }
  
  children1.calcFitness();
  children2.calcFitness();
  // HERE IT SHOULD BE WORKING...

   #if DEBUG
  std::cout << "============================" << std::endl;
  std::cout << "PMX CROSSOVER RESULT" << std::endl;
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
  #if CROSSOVER_ONLY_BETTER
  if(children1.getFitness() >= this->candidates[parent1].getFitness() &&
     children1.getFitness() >= this->candidates[parent2].getFitness())
    children->insertCandidate(children1);

  if(children2.getFitness() >= this->candidates[parent1].getFitness() &&
     children2.getFitness() >= this->candidates[parent2].getFitness())
    children->insertCandidate(children2);
  
  #else
  children->insertCandidate(children1);
  children->insertCandidate(children2);
  #endif
}

void Population::cyclic_crossover(Population * children)
{
  int parent1, parent2;
  #if ROULETTE
  #if DEBUG
  std::cout << "Selecao por roleta!" << std::endl;
  #endif
  this->setWheelValues();
  parent1 = rouletteSelection();
  parent2 = rouletteSelection();
  #else
  #if DEBUG
  std::cout << "Selecao por torneio!" << std::endl;
  #endif
  parent1 = tournamentSelection();
  parent2 = tournamentSelection();
  #endif

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
#if DEBUG
  std::cout << "=================================" << std::endl;
  std::cout << "POPULATION FITNESS BEFORE ELITISM" << std::endl;
  this->printAllFitness();
  std::cout << "=================================" << std::endl;
#endif
  
  children->quickSort(0, children->getPopulationSize()-1);

  int elite;
  
  if(children->getPopulationSize() > this->populationSize)
    elite = 0;
  else
    elite = (this->populationSize - children->getPopulationSize());

  int childrenIndex = 0;
  for(int i = elite; i < this->populationSize; i++)
    {
      for(int j = 0; j < this->candidates[i].getSize(); j++)
	{
	  this->candidates[i].setValueForPosition(j,
						  children->candidates[childrenIndex].getValue(j));
	}
      this->candidates[i].calcFitness();
      childrenIndex++;
    }
  
#if DEBUG
  std::cout << "=================================" << std::endl;
  std::cout << "POPULATION FITNESS AFTER ELITISM" << std::endl;
  this->printAllFitness();
  std::cout << "=================================" << std::endl;
#endif
  
}

void Population::reinsertion(Population * children)
{
  #if DEBUG
  std::cout << "=================================" << std::endl;
  std::cout << "POPULATION FITNESS BEFORE ELITISM" << std::endl;
  this->printAllFitness();
  std::cout << "=================================" << std::endl;
  #endif
  
  children->quickSort(0,children->getPopulationSize()-1);

  for(int i = 0; i < children->getSize(); i++)
    {
      if(children->candidates[i].getFitness() >
	 this->candidates[this->populationSize - (i+1)].getFitness())
	{
	  for(int j = 0;
	      j < this->candidates[this->populationSize - (i+1)].getSize();
	      j++)
	    {
	      this->candidates[this->populationSize - (i+1)].setValueForPosition(j,
										 children->candidates[i].getValue(j));
	    }
	  this->candidates[this->populationSize-(i+1)].calcFitness();
	}
    }
  
#if DEBUG
  std::cout << "=================================" << std::endl;
  std::cout << "POPULATION FITNESS AFTER ELITISM" << std::endl;
  this->printAllFitness();
  std::cout << "=================================" << std::endl;
#endif
  
}

int Population::getSize()
{
  return this->populationSize;
}

void Population::saveData(std::string url)
{
  std::ofstream file;
  
  file.open(SAVE_URL, std::ios::app);
  //melhor individuo
  file << "BEST CANDIDATE:\n";
  file << "Fitness: " << this->candidates[0].getFitness() << "\n";
  
  for(int i = 0; i < this->candidates[0].getLettersWord().size(); i++)
    {
      file << this->candidates[0].getLettersWord()[i] << " ";
    }
  file << "\n";
  for(int i = 0; i < this->candidates[0].getLettersWord().size(); i++)
    {
      file << this->candidates[0].getValue(i) << " ";
    }
  file << "\n";
  
  //individuos com fitness < 100
  int _count = 0;
  int allFitnessSum = 0;
  int fitnessSum = 0;
  for(int i = 0; i < this->populationSize; i++)
    {
      if(this->candidates[i].getFitness() > 99900)
	{
	  _count++;
	  fitnessSum += this->candidates[i].getFitness();
	}
      allFitnessSum += this->candidates[i].getFitness();
    }

  file << "Candidates with fitness < 100: " << _count << "\n";

  if(_count > 0)
    file << "Mean fitness of candidates with fitness < 100: " << (float)(fitnessSum/_count) << "\n";
  
  file << "Populations' mean fitnes: " << (float)(allFitnessSum/this->populationSize) << "\n";

  
  file.close();
}

int Population::getBestFitness()
{
  return this->candidates[0].getFitness();
}
