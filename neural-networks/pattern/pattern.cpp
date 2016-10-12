#include "pattern.hpp"
#include <fstream>

Pattern::Pattern(std::string file_ref, int number_equivalent)
{
  this->file_ref = file_ref;
  this->number_equivalent = number_equivalent;

  // open the file and pass it to the char vector
  std::ifstream file(file_ref);
  if(!file.good())
    {
      std::cout << "Error opening the file." << std::endl;
      exit(0);
    }
  else
    {
      std::string line;
      int column = 0;
      int to_write = 0;
      while(getline(file, line))
	{
	  for(int i = 0; i < line.size(); i++)
	    {
	      if(line[i] == '0') to_write = 0;
	      else to_write = 1;
	      this->pattern_vector[(column*(PATTERN_COLUMN - 1))+i] = to_write;
	    }
	  column++;
	}
    }
  file.close();

  #if DEBUG
  std::cout << "printing the pattern so you can see it!" << std::endl;
  for(int i = 0; i < PATTERN_COLUMN; i++)
    {
      for(int j = 0; j < PATTERN_ROW; j++)
	{ 
	  std::cout << (int)this->pattern_vector[(i*(PATTERN_COLUMN - 1))+j];
	}
      std::cout << std::endl;
    }
  #endif
}

void Pattern::print_pattern()
{
  for(int i = 0; i < PATTERN_COLUMN; i++)
    {
      for(int j = 0; j < PATTERN_ROW; j++)
	{ 
	  std::cout << (int)this->pattern_vector[(i*(PATTERN_COLUMN - 1))+j];
	}
      std::cout << std::endl;
    }
}
