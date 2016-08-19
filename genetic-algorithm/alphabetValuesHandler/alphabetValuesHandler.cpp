#include "alphabetValuesHandler.hpp"

int AlphabetValues::getValueForLetter(char letter)
{
  return this->values[letter-65];
}

void AlphabetValues::setValueForLetter(char letter, int value)
{
  this->values[letter-65] = value;
}

void AlphabetValues::printTheShitOut()
{
  for(int i = 0; i < ALPHABET_LETTERS; i++)
    {
      std::cout << "Letter: " << (char)(i+65) << " value: " << this->values[i] << std::endl;
    }
}
