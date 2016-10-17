#include "perceptron.hpp"

int main()
{
  Perceptron p;
  p.print_weights();
  p.trainment();
  p.print_weights();
  
  return 0;
}
