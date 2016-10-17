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
  bool changed = false;

  do
    {
      
    }while(changed);
  
}

void Perceptron::input(Pattern input)
{
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
