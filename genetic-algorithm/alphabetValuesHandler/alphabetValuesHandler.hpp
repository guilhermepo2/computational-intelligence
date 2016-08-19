#ifndef ALPHABET_VALUES_HEADER
#define ALPHABET_VALUES_HEADER
#define ALPHABET_LETTERS 26

#include <stdio.h>
#include <iostream>

class AlphabetValues
{
private:
  int values[ALPHABET_LETTERS];
public:
  AlphabetValues()
  {
    for(int i = 0; i < ALPHABET_LETTERS; i++) values[i] = 0;
  }
  
  int getValueForLetter(char letter);
  void setValueForLetter(char letter, int value);
  void printTheShitOut();
};

#endif
