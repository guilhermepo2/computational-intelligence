#ifndef CANDIDATE_HEADER
#define CANDIDATE_HEADER
#include <iostream>
#include <stdio.h>

class Candidate
{
private:
  int * values;
  int fitness;
  int size;
public:
  Candidate(int valuesSize);
  void createRandomCandidate();    // TO DO
  int getFitness();
  void calcFitness();              // TO DO
  void printCandidate();
  int getSize();
};

#endif
