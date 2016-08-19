#include "alphabetValuesHandler.hpp"

int main()
{
  AlphabetValues myAlphabetValues;

  std::cout << "Setting the value 1 for A" << std::endl;
  myAlphabetValues.setValueForLetter('A',1);
  std::cout << "Setting the value 2 for C" << std::endl;
  myAlphabetValues.setValueForLetter('C',2);
  std::cout << "Setting the value 3 for G" << std::endl;
  myAlphabetValues.setValueForLetter('G',3);
  std::cout << "Setting the value 4 for K" << std::endl;
  myAlphabetValues.setValueForLetter('K',4);
  std::cout << "Setting the value 5 for P" << std::endl;
  myAlphabetValues.setValueForLetter('P',5);
  std::cout << "Setting the value 9 for Z" << std::endl;
  myAlphabetValues.setValueForLetter('Z',9);

  myAlphabetValues.printTheShitOut();

  std::cout << "OK!" << std::endl;
  return 0;
}
