#include "candidate.hpp"
#include <time.h>


int main()
{
  srand(time(NULL));

  std::cout << "CREATING AND PRINTING CANDIDATE OF SIZE 10 ON PROBLEM SEND+MORE=MONEY" << std::endl;
  Candidate candidate(10, "SEND", "MORE", "MONEY");

  std::cout << "GENERATING CANDIDATE WITH RANDOM VALUES" << std::endl;
  candidate.createRandomCandidate();
  
  std::cout << "CALCULATING FITNESS" << std::endl;
  candidate.calcFitness();
  std:: cout << "Fitness: " << candidate.getFitness() << std::endl;

  std::cout << "PRINTING SO YOU CAN SEE IT" << std::endl;
  candidate.printCandidate();

  std::cout << "CANDIDATE OK!" << std::endl;
  return 0;
}
