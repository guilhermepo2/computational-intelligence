#ifndef CANDIDATE_HEADER
#define CANDIDATE_HEADER
#include <iostream>
#include <stdio.h>
#include "../alphabetValuesHandler/alphabetValuesHandler.hpp"
#include "../common/config.hpp"

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
  void createRandomCandidate();
  int getFitness();
  void calcFitness();
  void printCandidate();
  int getSize();
  void printLettersAndValues();
  std::string getWord1();
  std::string getWord2();
  std::string getResultWord();

  // methods to help the population class
  int getValue(int pos);
  int getPositionForValue(int value);
  void setValueForPosition(int position, int value);

  // for mutation
  void mutate();
};

#endif
