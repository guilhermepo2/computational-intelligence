#include "perceptron.hpp"

Perceptron::Perceptron()
{
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

void Perceptron::trainment()
{
  bool changed = false;

  do
    {
      // train it
      // 30 or 60 weights?
    }while(changed);
  
}

void Perceptron::print_weights()
{
  std::cout << "Printing Weights: " << std::endl;
  std::cout << "w = [ ";
  for(int i = 0; i < this->size; i++)
    {
      std::cout << this->weights[i] << " ";
    }
  std::cout << "]" << std::endl;
}
