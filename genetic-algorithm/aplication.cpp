#include "executionHandler/executionHandler.hpp"
/*
  Aplication for Genetic Algorithm to solve Cryptoarithmetic problems

  COMMAND LINE ARGUMENTS:
  1 - First Word
  2 - Second Word
  3 - Result Word
  4 - Population Size
  5 - Generations
  6 - Problem Size
  7 - Crossover Rate
  8 - Mutation Rate
 */


int main(int argc, char * argv[])
{ 
  if(argc < 9)
    {
      std::cout << "Please execute with the arguments" << std::endl;
      std::cout << "1 - First Word"                    << std::endl;
      std::cout << "2 - Second Word"                   << std::endl;
      std::cout << "3 - Result Word"                   << std::endl;
      std::cout << "4 - Population Size"               << std::endl;
      std::cout << "5 - Generations"                   << std::endl;
      std::cout << "6 - Problem Size"                  << std::endl;
      std::cout << "7 - Crossover Rate"                << std::endl;
      std::cout << "8 - Mutation Rate"                 << std::endl;
      exit(0);
    }

  ExecutionHandler executionHandler(argv[1],
				    argv[2],
				    argv[3],
				    argv[4],
				    argv[5],
				    argv[6],
				    argv[7],
				    argv[8]);

  std::cout << "Problem:\t\t"
	    << argv[1] << " + "
	    << argv[2] << " = "
	    << argv[3] << std::endl;
  std::cout << "Population Size:\t" << argv[4] << std::endl;
  std::cout << "Generations:\t\t"     << argv[5] << std::endl;
  std::cout << "Problem Size:\t\t"    << argv[6] << std::endl;
  std::cout << "Crossover Rate:\t\t"  << argv[7] << std::endl;
  std::cout << "Mutation Rate:\t\t"   << argv[8] << std::endl;
  if(SAVE)
    {
      std::cout << "Output file:\t\t"   << SAVE_URL << std::endl;
    }

  std::cout << "=======================================" << std::endl;
  std::cout << "Executing Algorithm..." << std::endl;
  executionHandler.execute();
  return 0;
}
