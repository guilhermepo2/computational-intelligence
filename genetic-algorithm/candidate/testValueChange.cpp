#include <iostream>
#include <time.h>
#include <vector>
#include "candidate.hpp"

int main(int argc, char * argv[])
{
  srand(time(NULL));
  Candidate c1(10, "SEND", "MORE", "MONEY");
  Candidate c2(10, "SEND", "MORE", "MONEY");

  std::cout << "Raw Candidates" << std::endl;
  c1.printLettersAndValues();
  c2.printLettersAndValues();
  std::cout << "================================================" << std::endl;
  std::cout << "Creating Random Candidates..." << std::endl;
  c1.createRandomCandidate();
  c2.createRandomCandidate();

  std::cout << "Printing the generated Random Candidates" << std::endl;
  c1.printLettersAndValues();
  c2.printLettersAndValues();

  std::cout << "================================================" << std::endl;
  std::cout << "Creating the cycle on both candidates..." << std::endl;
  std::vector<int> cycle;
  int crossoverPoint = rand() % c1.getSize();
  std::cout << "Random point to create the cycle: " << crossoverPoint << std::endl;
  std::cout << "Creating Cycle" << std::endl;
  std::cout << "1. Pushing crossover point value from Candidate 1 and 2 to the cycle" << std::endl;
  cycle.push_back(c1.getValue(crossoverPoint));
  cycle.push_back(c2.getValue(crossoverPoint));
  std::cout << "Cycle: ";
  for(int i = 0; i < cycle.size(); i++)
    {
      std::cout << cycle[i] << " ";
    }
  std::cout << std::endl;
  std::cout << "2. While cycle is not closed: search for parent 1 position which has the same value for parent 2 crossover point, push to the cycle the parent 2 value for the position found" << std::endl;
  while(cycle[0] != cycle[cycle.size()-1])
    {
      crossoverPoint = c1.getPositionForValue(cycle[cycle.size()-1]);
      cycle.push_back(c2.getValue(crossoverPoint));
    }
  std::cout << "Cycle should be finished (first == last)" << std::endl;
  std::cout << "Cycle: ";
  for(int i = 0; i < cycle.size(); i++)
    {
      std::cout << cycle[i] << " ";
    }
  std::cout << std::endl;
  std::cout << "================================================" << std::endl;
  std::cout << "Now: trade parent 1 position with parent 2 position for each value on the cycle" << std::endl;
  std::cout << "1 - Search position in parent 1 for the cycle value" << std::endl;
  std::cout << "2 - Trade the values on this positions" << std::endl;
  std::cout << "3 - Don't do this for the last cycle value." << std::endl;
  std::cout << "================================================" << std::endl;
  std::cout << "Creating the childrens" << std::endl;
  Candidate children1 = c1;
  Candidate children2 = c2;
  std::cout << "================================================" << std::endl;
  std::cout << "Printing Everyone" << std::endl;
  c1.printLettersAndValues();
  c2.printLettersAndValues();
  children1.printLettersAndValues();
  children2.printLettersAndValues();
  std::cout << "================================================" << std::endl;
  std::cout << "Creating a sample children to see if parent and children are not linked by reference" << std::endl;
  Candidate sample = c1;
  std::cout << "Parent: " << std::endl;
  c1.printLettersAndValues();
  std::cout << "Children: " << std::endl;
  sample.printLettersAndValues();

  std::cout << "Changing a value on children (will be invalid)" << std::endl;
  std::cout << "Setting the position 0 for value 11, the parent should not be changed" << std::endl;

  int backupValue = sample.getValue(0);
  sample.setValueForPosition(0,11);

  std::cout << "Parent: " << std::endl;
  c1.printLettersAndValues();
  std::cout << "Children: " << std::endl;
  sample.printLettersAndValues();

  std::cout << "But the parent actually changes. So, let's undo" << std::endl;
  sample.setValueForPosition(0,backupValue);

  std::cout << "Parent: " << std::endl;
  c1.printLettersAndValues();
  std::cout << "Children: " << std::endl;
  sample.printLettersAndValues();
  std::cout << "================================================" << std::endl;
  std::cout << "So let's do it manually, create the children and copy all positions, without using directly any attribution" << std::endl;
  Candidate newChildren1(c1.getSize(), c1.getWord1(), c1.getWord2(), c1.getResultWord());
  Candidate newChildren2(c2.getSize(), c2.getWord1(), c2.getWord2(), c2.getResultWord());
  std::cout << "================================================" << std::endl;
  std::cout << "Printing Everyone" << std::endl;
  c1.printLettersAndValues();
  c2.printLettersAndValues();
  newChildren1.printLettersAndValues();
  newChildren2.printLettersAndValues();
  std::cout << "================================================" << std::endl;
  std::cout << "Copying the positions" << std::endl;
  for(int i = 0; i < c1.getSize(); i++)
    {
      int valueForC1 = c1.getValue(i);
      int valueForC2 = c2.getValue(i);
      newChildren1.setValueForPosition(i, valueForC1);
      newChildren2.setValueForPosition(i, valueForC2);
    }
  std::cout << "================================================" << std::endl;
  std::cout << "Printing Everyone" << std::endl;
  c1.printLettersAndValues();
  c2.printLettersAndValues();
  newChildren1.printLettersAndValues();
  newChildren2.printLettersAndValues();
  std::cout << "================================================" << std::endl;
  std::cout << "Changing Children 1 to see if it does not changes Parent 1" << std::endl;
  backupValue = newChildren1.getValue(0);
  newChildren1.setValueForPosition(0,11);

  std::cout << "Parent: " << std::endl;
  c1.printLettersAndValues();
  std::cout << "Children: " << std::endl;
  newChildren1.printLettersAndValues();

  newChildren1.setValueForPosition(0,backupValue);
  std::cout << "================================================" << std::endl;
  std::cout << "It does not change!" << std::endl;
  std::cout << "Now we have to do the cycles change!" << std::endl;
  std::cout << "Remember how to do it?" << std::endl;
  std::cout << "================================================" << std::endl;
  std::cout << "Now: trade parent 1 position with parent 2 position for each value on the cycle" << std::endl;
  std::cout << "1 - Search position in parent 1 for the cycle value" << std::endl;
  std::cout << "2 - Trade the values on this positions" << std::endl;
  std::cout << "3 - Don't do this for the last cycle value." << std::endl;
  std::cout << "================================================" << std::endl;

  for(int i = 0; i < cycle.size()-1; i++)
    {
      int position = c1.getPositionForValue(cycle[i]);
      int valueChildren1 = newChildren1.getValue(position);
      int valueChildren2 = newChildren2.getValue(position);

      newChildren2.setValueForPosition(position,valueChildren1);
      newChildren1.setValueForPosition(position,valueChildren2);
    }
  newChildren1.calcFitness();
  newChildren2.calcFitness();
  std::cout << "================================================" << std::endl;
  std::cout << "Phew... It's done! It should be working." << std::endl;
  std::cout << "Crossover result: " << std::endl;
  std::cout << 
  std::cout << "================================================" << std::endl;
  std::cout << "Cycle: ";
  for(int i = 0; i < cycle.size(); i++)
    {
      std::cout << cycle[i] << " ";
    }
  std::cout << std::endl;
  std::cout << "================================================" << std::endl;
  std::cout << "Printing Everyone" << std::endl;
  std::cout << "PARENT 1:" << std::endl;
  c1.printLettersAndValues();
  std::cout << "PARENT 2:" << std::endl;
  c2.printLettersAndValues();
  std::cout << "CHILDREN 1:" << std::endl;
  newChildren1.printLettersAndValues();
  std::cout << "CHILDREN 2:" << std::endl;
  newChildren2.printLettersAndValues();
  std::cout << "================================================" << std::endl;
  std::cout << "If both parents are untouched and both children are valid solutions, congratulations on getting the crossover right!" << std::endl;
  std::cout << "You can also do it in hand to verify if the cycle were changed correctly." << std::endl;
  return 0;
}
