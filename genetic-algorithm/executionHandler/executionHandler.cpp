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
      pop.elitism(&children);
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
  
  //sleep a little bit... so the clock can work a bit
  std::cout << "Sleeping..." << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "안년하세요" << std::endl;
}
