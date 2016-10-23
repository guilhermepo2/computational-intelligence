#include "spperceptron.hpp"

SPPerceptron::SPPerceptron(int learning_rate)
{
  this->learning_rate = learning_rate;
  for(int i = 0; i < this->size; i++)
    {
      this->weights[i] = 0;
    }
}

int step_function(int v)
{
  if(v > 0) return 1;
  else return 0;
}

void SPPerceptron::trainment()
{
  int steps = 0;
  bool changed;
  int input, yi, error;

  do
    {
      changed = false;
      // train for the first pattern, that is a expected 1
      input = this->bias;
      for(int i = 0; i < this->size; i++)
	{
	  input += (this->patterns[0]->get_pattern_position(i) * this->weights[i]);
	}
      yi = step_function(input);
      error = 1 - yi;
      if(error != 0)
	{
	  changed = true;
	  this->bias += (error * this->learning_rate);
	  for(int i = 0; i < this->size; i++)
	    {
	      this->weights[i] += (error * this->learning_rate *
				   this->patterns[0]->get_pattern_position(i));
	    }
	}

      // the other patterns are expected to be 0
      for(int i = 1; i < this->patterns.size(); i++)
	{
	  input = this->bias;
	  for(int j = 0; j < this->size; j++)
	    {
	      input += (this->patterns[i]->get_pattern_position(j) * this->weights[j]);
	    }
	  yi = step_function(input);
	  error = 0 - yi;
	  if(error != 0)
	    {
	      changed = true;
	      this->bias += (error * this->learning_rate);
	      for(int j = 0; j < this->size; j++)
		{
		  this->weights[j] += (error * this->learning_rate *
				       this->patterns[i]->get_pattern_position(j));
		}
	    }
	}
      steps++;
    }while(changed);
  std::cout << "Trainment: " << steps << " steps. " << std::endl;
  
}

int SPPerceptron::input(Pattern& pattern)
{
  int input = this->bias;
  for(int i = 0; i < this->size; i++)
    {
      input += (this->weights[i] * pattern.get_pattern_position(i));
    }
  return step_function(input);
}

void SPPerceptron::print_weights()
{
  std::cout << "Printing Weights: " << std::endl;
  std::cout << "w = [ ";
  for(int i = 0; i < this->size; i++)
    {
      std::cout << this->weights[i] << " ";
    }
  std::cout << "]" << std::endl;
}

void SPPerceptron::add_pattern(Pattern * p)
{
  this->patterns.push_back(p);
}
