#include <iostream>
#include "pattern.hpp"

int main()
{
  std::cout << "Creating the Pattern for 0 for testing" << std::endl;
  Pattern pattern("../numbers/0.txt", 0);

  std::cout << "Printing positions one by one" << std::endl;
  for(int i = 0; i < pattern.get_column_size(); i++)
    {
      for(int j = 0; j < pattern.get_row_size(); j++)
	{
	  std::cout << pattern.get_pattern_position(((i*(pattern.get_column_size() -1))+j));
	}
      std::cout << std::endl;
    }

  std::cout << "Calling the print function" << std::endl;
  pattern.print_pattern();

  std::cout << "Printing all info: " << std::endl;
  std::cout << "Number represented: " << pattern.get_number_equivalent() << std::endl;
  std::cout << "Total size: " << pattern.get_total_size() << std::endl;
  std::cout << "row size: " << pattern.get_row_size() << std::endl;
  std::cout << "column size: " << pattern.get_column_size() << std::endl;
  
  return 0;
}
