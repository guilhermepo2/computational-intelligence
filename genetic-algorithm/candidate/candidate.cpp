#include "candidate.hpp"

Candidate::Candidate(int valuesSize, std::string op1,
		     std::string op2, std::string result)
{
  this->fitness = 0;
  this->size = valuesSize;

  this->op1 = op1;
  this->op2 = op2;
  this->result = result;
  this->letters = "";
  values = new AlphabetValues();
  
  std::string tempLetters = this->op1 + this->op2 + this->result;

  size_t found;
  for(int i = 0; i < tempLetters.size(); i++)
    {
      found = this->letters.find(tempLetters[i]);
      if(found == std::string::npos)
	{
	  this->letters += tempLetters[i];
	}
    }

  // created string with no repetition; now we must check if letters size equals the problem size
  if(this->letters.size() != this->size)
    {
      // insert random letters (NOT REPEATED) until letters.size() == size
      std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      while(this->letters.size() != this->size)
	{
	  int value = rand() % alphabet.size();
	  found = this->letters.find(alphabet[value]);
	  if(found == std::string::npos)
	    {
	      this->letters += alphabet[value];
	    }
	}
    }
}

void Candidate::createRandomCandidate()
{
  int * myVet = new int[this->size];
  for(int i = 0; i < this->size; i++) myVet[i] = 0;
  
  for(int i = 0; i < this->size; i++)
    {
      int choice = rand() % this->size; 
      if(myVet[choice] == 0)
	{
	  myVet[choice] = 1;
	  this->values->setValueForLetter(this->letters[i],
					  choice);
	}
      else i--;
    }
}

int Candidate::getFitness()
{
  return this->fitness;
}

void Candidate::calcFitness()
{
  int fitness;
  
  int word1 = 0;
  for(int i = 0; i < this->op1.size(); i++)
    {
      word1 += (this->values->getValueForLetter(this->op1[i]) *
		pow(10,(this->op1.size() - (i+1))));
    }

  int word2 = 0;
  for(int i = 0; i < this->op2.size(); i++)
    {
      word2 += (this->values->getValueForLetter(this->op2[i]) *
		pow(10,(this->op2.size() - (i+1))));
    }
  
  int result = 0;
  for(int i = 0; i < this->result.size(); i++)
    {
      result += (this->values->getValueForLetter(this->result[i]) *
		pow(10,(this->result.size() - (i+1))));
    }

  this->fitness = (100000 - labs(word1+word2 - result));
  //this->fitness = labs(word1 + word2 - result);
}

void Candidate::printCandidate()
{
  std::cout << "Candidate: ";
  std::cout << std::endl;
  std::cout << "Fitness: " << this->fitness << std::endl;

  std::cout << "First word: " << this->op1 << std::endl;
  std::cout << "Second word: " << this->op2 << std::endl;
  std::cout << "Result word: " << this->result << std::endl;
  std::cout << "All Letters: " << this->letters << std::endl;

  std::cout << "Values for Letters" << std::endl;


  // PROBLEM LETTERS ( NO REPETION)
  for(int i = 0; i < this->letters.size(); i++)
    {
      std::cout << this->letters[i] << " ";
    }
  std::cout << std::endl;

  for(int i = 0; i < this->letters.size(); i++)
    {
      std::cout << this->values->getValueForLetter(this->letters[i]) << " ";
    }
  std::cout << "\n\n";

  // WORD 1
  for(int i = 0; i < this->op1.size(); i++)
    {
      std::cout << this->op1[i] << " ";
    }
  std::cout << std::endl;
  
  for(int i = 0; i < this->op1.size(); i++)
    {
      std::cout << this->values->getValueForLetter(this->op1[i]) << " ";
    }
  std::cout << "\n\n";
  
  // WORD 2
  for(int i = 0; i < this->op2.size(); i++)
    {
      std::cout << this->op2[i] << " ";
    }
  std::cout << std::endl;
  
  for(int i = 0; i < this->op2.size(); i++)
    {
      std::cout << this->values->getValueForLetter(this->op2[i]) << " ";
    }
  std::cout << "\n\n";
  
  // RESULT WORD
  for(int i = 0; i < this->result.size(); i++)
    {
      std::cout << this->result[i] << " ";
    }
  std::cout << std::endl;
  
  for(int i = 0; i < this->result.size(); i++)
    {
      std::cout << this->values->getValueForLetter(this->result[i]) << " ";
    }
  std::cout << std::endl;
}

int Candidate::getSize()
{
  return this->size;
}


int Candidate::getValue(int pos)
{
  return this->values->getValueForLetter(this->letters[pos]);
}

int Candidate::getPositionForValue(int value)
{
  // search which letter has the value
  char letter = this->values->getLetterFromValue(value);
  
  #if DEBUG
  std::cout << "Value: " << value << " Letter: " << letter << std::endl;
  #endif

  // I HAVE THE LETTER
  
  // return the letter position on the LETTERS vector

  for(int i = 0; i < this->letters.size(); i++)
    {
      if(this->letters[i] == letter)
	{
	  return i;
	}
    }

  return 0;
}

void Candidate::printLettersAndValues()
{
  for(int i = 0; i < this->letters.size(); i++)
    {
      std::cout << this->letters[i] << " ";
    }
  std::cout << std::endl;
  
  for(int i = 0; i < this->letters.size(); i++)
    {
      std::cout << this->values->getValueForLetter(this->letters[i]) << " ";
    }
  std::cout << "\n\n";
}

void Candidate::setValueForPosition(int position, int value)
{
  char letter = this->letters[position];
  this->values->setValueForLetter(letter, value);
}

std::string Candidate::getWord1()
{
  return this->op1;
}

std::string Candidate::getWord2()
{
  return this->op2;
}

std::string Candidate::getResultWord()
{
  return this->result;
}

std::string Candidate::getLettersWord()
{
  return this->letters;
}

void Candidate::mutate()
{
  int pos1 = rand() % this->letters.size();
  int pos2 = rand() % this->letters.size();
  int valueP1 = this->values->getValueForLetter(this->letters[pos1]);
  int valueP2 = this->values->getValueForLetter(this->letters[pos2]);
  this->values->setValueForLetter(this->letters[pos1], valueP2);
  this->values->setValueForLetter(this->letters[pos2], valueP1);
}
