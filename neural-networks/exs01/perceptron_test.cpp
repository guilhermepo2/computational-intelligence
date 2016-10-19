#include "perceptron.hpp"

int main()
{
  Perceptron p;
  std::cout << "===============================================" << std::endl;
  std::cout << "Treinamento Perceptron" << std::endl;
  std::cout << "a) e b)" << std::endl;
  p.trainment();
  std::cout << "Bias: " << p.get_bias() << std::endl;
  p.print_weights();
  std::cout << "===============================================" << std::endl;
  std::cout << "c) Testando Padroes danificados" << std::endl;
  std::cout << "Padroes de 0: " << std::endl;
  Pattern * p0d1 = new Pattern("../numbers/exs01_damaged/0_d1.txt", 0);
  Pattern * p0d2 = new Pattern("../numbers/exs01_damaged/0_d2.txt", 0);
  Pattern * p0d3 = new Pattern("../numbers/exs01_damaged/0_d3.txt", 0);
  Pattern * p0d4 = new Pattern("../numbers/exs01_damaged/0_d4.txt", 0);
  Pattern * p0d5 = new Pattern("../numbers/exs01_damaged/0_d5.txt", 0);
  Pattern * p0d6 = new Pattern("../numbers/exs01_damaged/0_d6.txt", 0);
  Pattern * p0d7 = new Pattern("../numbers/exs01_damaged/0_d7.txt", 0);
  Pattern * p0d8 = new Pattern("../numbers/exs01_damaged/0_d8.txt", 0);
  Pattern * p0d9 = new Pattern("../numbers/exs01_damaged/0_d9.txt", 0);
  Pattern * p0d10 = new Pattern("../numbers/exs01_damaged/0_d10.txt", 0);
  
  std::cout << "1 distorcao: " << std::endl;
  if(p.input(*p0d1) == 0) std::cout << "Reconhecido!" << std::endl;
  else std::cout << "Nao Reconhecido :(" << std::endl;
  if(p.input(*p0d2) == 0) std::cout << "Reconhecido!" << std::endl;
  else std::cout << "Nao Reconhecido :(" << std::endl;
  
  std::cout << "2 distorcoes: " << std::endl;
  if(p.input(*p0d3) == 0) std::cout << "Reconhecido!" << std::endl;
  else std::cout << "Nao Reconhecido :(" << std::endl;
  if(p.input(*p0d4) == 0) std::cout << "Reconhecido!" << std::endl;
  else std::cout << "Nao Reconhecido :(" << std::endl;
  
  std::cout << "3 distorcoes: " << std::endl;
  if(p.input(*p0d5) == 0) std::cout << "Reconhecido!" << std::endl;
  else std::cout << "Nao Reconhecido :(" << std::endl;
  if(p.input(*p0d6) == 0) std::cout << "Reconhecido!" << std::endl;
  else std::cout << "Nao Reconhecido :(" << std::endl;
  
  std::cout << "4 distorcoes: " << std::endl;
  if(p.input(*p0d7) == 0) std::cout << "Reconhecido!" << std::endl;
  else std::cout << "Nao Reconhecido :(" << std::endl;
  if(p.input(*p0d8) == 0) std::cout << "Reconhecido!" << std::endl;
  else std::cout << "Nao Reconhecido :(" << std::endl;
  
  std::cout << "5 distorcoes: " << std::endl;
  if(p.input(*p0d9) == 0) std::cout << "Reconhecido!" << std::endl;
  else std::cout << "Nao Reconhecido :(" << std::endl;
  if(p.input(*p0d10) == 0) std::cout << "Reconhecido!" << std::endl;
  else std::cout << "Nao Reconhecido :(" << std::endl;

  std::cout << std::endl;
  std::cout << "Padroes de 1: " << std::endl;
  Pattern * p1d1 = new Pattern("../numbers/exs01_damaged/1_d1.txt", 1);
  Pattern * p1d2 = new Pattern("../numbers/exs01_damaged/1_d2.txt", 1);
  Pattern * p1d3 = new Pattern("../numbers/exs01_damaged/1_d3.txt", 1);
  Pattern * p1d4 = new Pattern("../numbers/exs01_damaged/1_d4.txt", 1);
  Pattern * p1d5 = new Pattern("../numbers/exs01_damaged/1_d5.txt", 1);
  Pattern * p1d6 = new Pattern("../numbers/exs01_damaged/1_d6.txt", 1);
  Pattern * p1d7 = new Pattern("../numbers/exs01_damaged/1_d7.txt", 1);
  Pattern * p1d8 = new Pattern("../numbers/exs01_damaged/1_d8.txt", 1);
  Pattern * p1d9 = new Pattern("../numbers/exs01_damaged/1_d9.txt", 1);
  Pattern * p1d10 = new Pattern("../numbers/exs01_damaged/1_d10.txt", 1);
  std::cout << "1 distorcao: " << std::endl;
  if(p.input(*p1d1) == 1) std::cout << "Reconhecido!" << std::endl;
  else std::cout << "Nao Reconhecido :(" << std::endl;
  if(p.input(*p1d2) == 1) std::cout << "Reconhecido!" << std::endl;
  else std::cout << "Nao Reconhecido :(" << std::endl;
  
  std::cout << "2 distorcoes: " << std::endl;
  if(p.input(*p1d3) == 1) std::cout << "Reconhecido!" << std::endl;
  else std::cout << "Nao Reconhecido :(" << std::endl;
  if(p.input(*p1d4) == 1) std::cout << "Reconhecido!" << std::endl;
  else std::cout << "Nao Reconhecido :(" << std::endl;
  
  std::cout << "3 distorcoes: " << std::endl;
  if(p.input(*p1d5) == 1) std::cout << "Reconhecido!" << std::endl;
  else std::cout << "Nao Reconhecido :(" << std::endl;
  if(p.input(*p1d6) == 1) std::cout << "Reconhecido!" << std::endl;
  else std::cout << "Nao Reconhecido :(" << std::endl;
  
  std::cout << "4 distorcoes: " << std::endl;
  if(p.input(*p1d7) == 1) std::cout << "Reconhecido!" << std::endl;
  else std::cout << "Nao Reconhecido :(" << std::endl;
  if(p.input(*p1d8) == 1) std::cout << "Reconhecido!" << std::endl;
  else std::cout << "Nao Reconhecido :(" << std::endl;
  
  std::cout << "5 distorcoes: " << std::endl;
  if(p.input(*p1d9) == 1) std::cout << "Reconhecido!" << std::endl;
  else std::cout << "Nao Reconhecido :(" << std::endl;
  if(p.input(*p1d10) == 1) std::cout << "Reconhecido!" << std::endl;
  else std::cout << "Nao Reconhecido :(" << std::endl;
  std::cout << "===============================================" << std::endl;
  std::cout << "d) Vendo a saida para os padroes" << std::endl;
  Pattern * p_zero = new Pattern("../numbers/0.txt", 0);
  std::cout << "Padrao de 0: " << p.input(*p_zero) << std::endl;
  Pattern * p_one = new Pattern("../numbers/1.txt", 1);
  std::cout << "Padrao de 1: " << p.input(*p_one) << std::endl;
  Pattern * p_two = new Pattern("../numbers/2.txt", 2);
  std::cout << "Padrao de 2: " << p.input(*p_two) << std::endl;
  Pattern * p_three = new Pattern("../numbers/3.txt", 3);
  std::cout << "Padrao de 3: " << p.input(*p_three) << std::endl;
  Pattern * p_four = new Pattern("../numbers/4.txt", 4);
  std::cout << "Padrao de 4: " << p.input(*p_four) << std::endl;
  Pattern * p_five = new Pattern("../numbers/5.txt", 5);
  std::cout << "Padrao de 5: " << p.input(*p_five) << std::endl;


  
  return 0;
}
