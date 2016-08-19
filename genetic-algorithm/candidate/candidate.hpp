#ifndef CANDIDATE_HEADER
#define CANDIDATE_HEADER
#include <iostream>
#include <stdio.h>
#include "../alphabetValuesHandler/alphabetValuesHandler.hpp"

class Candidate
{
private:
  // strings for words, where op1+op2=result
  // THIS IS BAD PLEASE FIX ME
  std::string op1;
  std::string op2;
  std::string result;
  std::string letters;

  AlphabetValues * values;
  int fitness;
  int size;
public:
  Candidate(int valuesSize, std::string op1,
	    std::string op2, std::string result);
  void createRandomCandidate();    // TO DO
  int getFitness();
  void calcFitness();
  void printCandidate();
  int getSize();
};

#endif
