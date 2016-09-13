#include "executionHandler.hpp"

ExecutionHandler::ExecutionHandler(std::string op1,
				   std::string op2,
				   std::string result,
				   std::string populationSize,
				   std::string generations,
				   std::string problemSize,
				   std::string crossoverRate,
				   std::string mutationRate)
{
  this->op1   = op1;
  this->op2   = op2;
  this->result = result;

  this->populationSize = stoi(populationSize);
  this->generations    = stoi(generations);
  this->problemSize    = stoi(problemSize);
  this->crossoverRate  = stof(crossoverRate);
  this->mutationRate   = stof(mutationRate);

  // printing info on config
  std::cout << "================================" << std::endl;
  #if DEBUG
  std::cout << "Debug mode activated." << std::endl;
  #else
  std::cout << "Debug mode deactivated." << std::endl;
  #endif

  #if SAVE
  std::cout << "Saving ON, url: " << SAVE_URL << std::endl;
  #endif

  #if ROULETTE
  std::cout << "Selection method: Roulette" << std::endl;
  #elif TOURNAMENT
  std::cout << "Selection method: Tournament" << std::endl;
  #else
  std::cout << "No Selection method, please edit the config file" << std::endl;
  exit(0);
  #endif

  #if CYCLIC
  std::cout << "Crossover method: Cyclic" << std::endl;
  #elif PMX
  std::cout << "Crossover method: PMX" << std::endl;
  #else
  std::cout << "No crossover method selected, please edit the config file" << std::endl;
  exit(0);
  #endif

  #if REINSERTION
  std::cout << "Survival Method: Reinsertion" << std::endl;
  #elif ELITISM
  std::cout << "Survival Method: Elitism" << std::endl;
  #else
  std::cout << "No survival method selected, please edit the config file" << std::endl;
  exit(0);
  #endif

  #if SLEEP
  std::cout << "Program will asleep after one execution" << std::endl;
  #endif
  std::cout << "================================" << std::endl;
}

void ExecutionHandler::execute()
{ 
  Population pop(this->op1,
		 this->op2,
		 this->result,
		 this->populationSize,
		 this->problemSize);
  
  Population children(this->op1,
		      this->op2,
		      this->result,
		      (this->populationSize * this->crossoverRate),
		      this->problemSize);

  srand(time(NULL));
  pop.createPopulation();
  pop.bubbleSort();
  
#if SAVE
  std::ofstream file;
  file.open(SAVE_URL, std::ios::app);
  file << "=================================\nNEW TEST\n\n";
  file << "GENERATION 0\n";
  file.close();
  pop.saveData(SAVE_URL);
#endif

  int gen;
  for(gen = 0; gen < this->generations; gen++)
    {
      std::cout << "Generation: " << gen+1 << std::endl;
      
      for(int i = 0; i < (children.getSize() / 2); i++)
	{
	  pop.crossover(&children);
	}
      
      for(int i = 0; i < (pop.getPopulationSize() * this->mutationRate); i++)
	children.mutateOneRandom();
      
      #if DEBUG
      std::cout << "=====================" << std::endl;
      std::cout << "Parent: " << std::endl;
      pop.printEverything();
      std::cout << "=====================" << std::endl;
      std::cout << "Children" << std::endl;
      children.printEverything();
      std::cout << "=====================" << std::endl;
      #endif
      
      // Natural Selection is a bitch, kill the least fittest

      #if REINSERTION
      pop.reinsertion(&children);
      #elif ELITISM
      pop.elitism(&children);
      #endif
      
      children.killEveryone();
    }
  pop.printBestCandidate();
  
#if SAVE
  file.open(SAVE_URL, std::ios::app);
  file << "\nAFTER " << gen << " GENERATIONS:\n";
  file.close();
  pop.saveData(SAVE_URL);
  file.open(SAVE_URL, std::ios::app);
  file << "\nTEST ENDED\n=================================\n\n";
  file.close();
#endif

  if(pop.getBestFitness() == 100000)
    {
      std::ofstream ok;
      ok.open("bingo.txt", std::ios::app);
      ok << "got the 100000 fitness\n";
      ok.close();
    }
  
  // final judgment is here (end of this test)
  pop.killEveryone();
  children.killEveryone();

  #if SLEEP
  //sleep a little bit... so the clock can work a bit
  std::cout << "Sleeping..." << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  #endif
}
