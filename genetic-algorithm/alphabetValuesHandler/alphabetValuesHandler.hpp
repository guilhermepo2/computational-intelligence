#ifndef ALPHABET_VALUES_HEADER
#define ALPHABET_VALUES_HEADER
#define ALPHABET_LETTERS 26

#include <stdio.h>
#include <iostream>

class AlphabetValues
{
private:
  int * values;
public:
  AlphabetValues();
  int getValueForLetter(char letter);
  void setValueForLetter(char letter, int value);
  void printTheShitOut();
};

#endif
