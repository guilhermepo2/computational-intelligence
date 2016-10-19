#include "perceptron.hpp"

Perceptron::Perceptron(int learning_rate)
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

/*
  Algoritmo de Treinamento da Perceptron

  xi = i-esimo padrao de treinamento
  yi = resposta da perceptron para xi
  di = valor desejado como resposta

  se di = yi -> nao faz nada

  senao:
  se di = 1 e yi = 0 -> w = w + (n * xi)
  se di = 0 e yi = 1 -> w = w - (n * xi)

  caso compacto:
  e = di - yi
  w = w + e * n * xi
*/

void Perceptron::trainment()
{
  int steps = 0;
  bool changed = false;

  int input, yi, erro;
  //w = w + e * this->learning_rate + input[i]

  do
    {
      changed = false;
      
      // train for 0 (bias + 30 weights)
      input = 0;
      input += 1 * this->bias;
      for(int i = 0; i < this->size; i++)
	{
	  input += (this->p_zero->get_pattern_position(i) * this->weights[i]);
	}
      yi = step_function(input);
      erro = 0 - yi;
      if(erro != 0)
	{
	  std::cout << "erro no 0!" << std::endl;
	  changed = true;
	  this->bias = this->bias + erro * this->learning_rate;
	  for(int i = 0; i < this->size; i++)
	    {
	      this->weights[i] = this->weights[i] + erro * this->learning_rate * p_zero->get_pattern_position(i);
	    }
	}

      // train for 1 (bias + 30 weights)
      input = 0;
      input += 1 * this->bias;
      for(int i = 0; i < this->size; i++)
	{
	  input += (this->p_one->get_pattern_position(i) * this->weights[i]);
	}
      yi = step_function(input);
      erro = 1 - yi;
      if(erro != 0)
	{
	  std::cout << "erro no 1!" << std::endl;
	  changed = true;
	  this->bias = this->bias + erro * this->learning_rate;
	  for(int i = 0; i < this->size; i++)
	    {
	      this->weights[i] = this->weights[i] + erro * this->learning_rate * p_one->get_pattern_position(i);
	    }
	}

      steps++;
    }while(changed);
  std::cout << "Trainment: " << steps << " steps." << std::endl;
  
}

int Perceptron::input(Pattern& pattern)
{
  int input = 0;
  input += 1 * this->bias;
  for(int i = 0; i < this->size; i++)
    {
      input += input + (this->weights[i] * pattern.get_pattern_position(i));
    }
  return step_function(input);
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
