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
  #if ROULETTE
  this->roulette = 0;
  #endif
  
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

#if REGULAR_FITNESS
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
  
  // this candidate is so awful that i made me treat him as an exception on my code
  
  if(this->fitness < 0)
    this->fitness = 1;
  //this->fitness = labs(word1 + word2 - result);
}
#else
//fitness must be:
// 1 - an integer
// 2 - the higher the better
// lets try: subtract individual numbers and sum them
void Candidate::calcFitness()
{
  int fitSize = this->result.size();
  int * fitness_vector = new int[fitSize];

  // should always be true but anyway
  if(this->op1.size() == this->op2.size())
    {
      int operands_actual = this->op1.size() - 1;
      int result_actual = fitSize - 1;
      int one_up = 0;

      int left_side;
      int right_side;
      
      for(int i = 0; i < fitSize; i++) fitness_vector[i] = 0;
      
      for(int i = 0; i < (this->op1.size() - 1); i++)
	{
	  left_side = (this->values->getValueForLetter(this->result[result_actual]));
	  right_side =
	    ((this->values->getValueForLetter(this->op1[operands_actual]))
	     +(this->values->getValueForLetter(this->op2[operands_actual]))+one_up);

	  if(right_side >= 10)
	    {
	      right_side -= 10;
	      one_up = 1;
	    }
	  else
	    one_up = 0;
	  
	  fitness_vector[result_actual] = labs(left_side - right_side);

	  result_actual--;
	  operands_actual--;
	}

      left_side = ((this->values->getValueForLetter(this->result[result_actual-1]) * 10) + this->values->getValueForLetter(this->result[result_actual]));
      
      right_side =
	((this->values->getValueForLetter(this->op1[operands_actual]))
	 +(this->values->getValueForLetter(this->op2[operands_actual]))+one_up);
      
      fitness_vector[result_actual] = labs(left_side - right_side);

      // now i have my fitness vector
      // fitness will be sum multiplied by 10 ^ (0 counts)
      int zeros = 0;
      int sum = 0;
      for(int i = 1; i < fitSize; i++)
	{
	  if(fitness_vector[i] == 0) zeros++;
	  else sum += fitness_vector[i];
	}

#if DEBUG
      std::cout << "fitness vector: " << std::endl;
      for(int i = 0; i < fitSize; i++)
	{
	  std::cout << fitness_vector[i] << " ";
	}
      std::cout << "\nzeros: " << zeros << std::endl;
      std::cout << "sum: " << sum << std::endl;
#endif

      this->fitness = ((100 * (pow(10,zeros)) - sum));

      #if DEBUG
      std::cout << "fitness: " << this->fitness << std::endl;
      #endif
    }
  else
    {
      std::cout << "Error." << std::endl;
      exit(1);
    }
}
#endif

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
  #if MUTATE_ONLY_IF_BETTER
  int oldfitness = this->fitness;
  #endif
  
  int pos1 = rand() % this->letters.size();
  int pos2 = rand() % this->letters.size();
  int valueP1 = this->values->getValueForLetter(this->letters[pos1]);
  int valueP2 = this->values->getValueForLetter(this->letters[pos2]);
  this->values->setValueForLetter(this->letters[pos1], valueP2);
  this->values->setValueForLetter(this->letters[pos2], valueP1);

  this->calcFitness();

  #if MUTATE_ONLY_IF_BETTER
  if(this->fitness < oldfitness)
    {
      this->values->setValueForLetter(this->letters[pos1], valueP1);
      this->values->setValueForLetter(this->letters[pos2], valueP2);

      this->calcFitness();
    }
  #endif
}

#if ROULETTE
void Candidate::setRouletteValue(int roulette)
{
  this->roulette = roulette;
}

int Candidate::getRouletteValue()
{
  return this->roulette;
}
#endif
