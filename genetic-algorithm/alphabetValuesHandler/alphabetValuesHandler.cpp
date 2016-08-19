#include "alphabetValuesHandler.hpp"

AlphabetValues::AlphabetValues()
{
  values = new int[ALPHABET_LETTERS];
  for(int i = 0; i < ALPHABET_LETTERS; i++) values[i] = 0;
}

int AlphabetValues::getValueForLetter(char letter)
{
  int position = letter-65;
  return this->values[position];
}

void AlphabetValues::setValueForLetter(char letter, int value)
{
  int position = (int)letter-65;
  this->values[position] = value;
}

void AlphabetValues::printTheShitOut()
{
  for(int i = 0; i < ALPHABET_LETTERS; i++)
    {
      std::cout << "Letter: " << (char)(i+65) << " value: " << this->values[i] << std::endl;
    }
}
