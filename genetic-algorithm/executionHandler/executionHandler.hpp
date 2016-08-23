#include "../population/population.hpp"

/*
  WORD1 + WORD2 = RESULT

  THIS SHOULD BE ONLY ON THIS CLASS
  the three words are also on Population class and candidate class

  this is a VERY bad redundance, fix somehow please
  (singleton with the three words?)
 */

class ExecutionHandler
{
private:
  std::string op1;
  std::string op2;
  std::string result;

  int populationSize;
  int generations;
  int problemSize;
  float crossoverRate;
  float mutationRate;
  
public:
  ExecutionHandler(std::string op1,
		   std::string op2,
		   std::string result,
		   std::string populationSize,
		   std::string generations,
		   std::string problemSize,
		   std::string crossoverRate,
		   std::string mutationRate);
  void execute();
};
