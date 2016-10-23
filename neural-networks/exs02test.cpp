#include "spperceptron.hpp"
#include <iostream>

int main()
{
  SPPerceptron rec0, rec1;

  Pattern * p0 = new Pattern("numbers/0.txt", 0);
  Pattern * p1 = new Pattern("numbers/1.txt", 1);
  rec0.add_pattern(p0);
  rec0.add_pattern(p1);

  rec1.add_pattern(p1);
  rec1.add_pattern(p0);
  
  std::cout << "===============================================" << std::endl;
  std::cout << "Treinamento Perceptron - Para Padrao 0" << std::endl;
  std::cout << "a) e b)" << std::endl;
  rec0.trainment();
  std::cout << "Bias: " << rec0.get_bias() << std::endl;
  rec0.print_weights();
  std::cout << "===============================================" << std::endl;
  std::cout << "Treinamento Perceptron - Para Padrao 1" << std::endl;
  std::cout << "a) e b)" << std::endl;
  rec1.trainment();
  std::cout << "Bias: " << rec1.get_bias() << std::endl;
  rec1.print_weights();
  std::cout << "===============================================" << std::endl;

  std::cout << "Testando o reconhecimento" << std::endl;
  std::cout << "Padrao 0: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p0) <<
    " Perceptron 1: " << rec1.input(*p0) << std::endl;
  std::cout << std::endl;
  std::cout << "Padrao 1: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p1) <<
    " Perceptron 1: " << rec1.input(*p1) << std::endl;
  std::cout << "===============================================" << std::endl;

  std::cout << "c) Testando Padroes danificados" << std::endl;
  std::cout << "Padroes de 0: " << std::endl;
  Pattern * p0d1 = new Pattern("numbers/exs01_damaged/0_d1.txt", 0);
  Pattern * p0d2 = new Pattern("numbers/exs01_damaged/0_d2.txt", 0);
  Pattern * p0d3 = new Pattern("numbers/exs01_damaged/0_d3.txt", 0);
  Pattern * p0d4 = new Pattern("numbers/exs01_damaged/0_d4.txt", 0);
  Pattern * p0d5 = new Pattern("numbers/exs01_damaged/0_d5.txt", 0);
  Pattern * p0d6 = new Pattern("numbers/exs01_damaged/0_d6.txt", 0);
  Pattern * p0d7 = new Pattern("numbers/exs01_damaged/0_d7.txt", 0);
  Pattern * p0d8 = new Pattern("numbers/exs01_damaged/0_d8.txt", 0);
  Pattern * p0d9 = new Pattern("numbers/exs01_damaged/0_d9.txt", 0);
  Pattern * p0d10 = new Pattern("numbers/exs01_damaged/0_d10.txt", 0);

  std::cout << "1 distorcao: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p0d1)
	    << " Perceptron 1: " << rec1.input(*p0d1) << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p0d2)
	    << " Perceptron 1: " << rec1.input(*p0d2) << std::endl;
  
  std::cout << "2 distorcoes: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p0d3)
	    << " Perceptron 1: " << rec1.input(*p0d3) << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p0d4)
	    << " Perceptron 1: " << rec1.input(*p0d4) << std::endl;
  
  std::cout << "3 distorcoes: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p0d5)
	    << " Perceptron 1: " << rec1.input(*p0d5) << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p0d6)
	    << " Perceptron 1: " << rec1.input(*p0d6) << std::endl;
  
  std::cout << "4 distorcoes: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p0d7)
	    << " Perceptron 1: " << rec1.input(*p0d7) << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p0d8)
	    << " Perceptron 1: " << rec1.input(*p0d8) << std::endl;
 
  std::cout << "5 distorcoes: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p0d9)
	    << " Perceptron 1: " << rec1.input(*p0d9) << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p0d10)
	    << " Perceptron 1: " << rec1.input(*p0d10) << std::endl;

  std::cout << std::endl;
  std::cout << "Padroes de 1: " << std::endl;
  Pattern * p1d1 = new Pattern("numbers/exs01_damaged/1_d1.txt", 1);
  Pattern * p1d2 = new Pattern("numbers/exs01_damaged/1_d2.txt", 1);
  Pattern * p1d3 = new Pattern("numbers/exs01_damaged/1_d3.txt", 1);
  Pattern * p1d4 = new Pattern("numbers/exs01_damaged/1_d4.txt", 1);
  Pattern * p1d5 = new Pattern("numbers/exs01_damaged/1_d5.txt", 1);
  Pattern * p1d6 = new Pattern("numbers/exs01_damaged/1_d6.txt", 1);
  Pattern * p1d7 = new Pattern("numbers/exs01_damaged/1_d7.txt", 1);
  Pattern * p1d8 = new Pattern("numbers/exs01_damaged/1_d8.txt", 1);
  Pattern * p1d9 = new Pattern("numbers/exs01_damaged/1_d9.txt", 1);
  Pattern * p1d10 = new Pattern("numbers/exs01_damaged/1_d10.txt", 1);

  std::cout << "1 distorcao: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p1d1)
	    << " Perceptron 1: " << rec1.input(*p1d1) << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p1d2)
	    << " Perceptron 1: " << rec1.input(*p1d2) << std::endl;
  
  std::cout << "2 distorcoes: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p1d3)
	    << " Perceptron 1: " << rec1.input(*p1d3) << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p1d4)
	    << " Perceptron 1: " << rec1.input(*p1d4) << std::endl;
  
  std::cout << "3 distorcoes: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p1d5)
	    << " Perceptron 1: " << rec1.input(*p1d5) << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p1d6)
	    << " Perceptron 1: " << rec1.input(*p1d6) << std::endl;
  
  std::cout << "4 distorcoes: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p1d7)
	    << " Perceptron 1: " << rec1.input(*p1d7) << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p1d8)
	    << " Perceptron 1: " << rec1.input(*p1d8) << std::endl;
 
  std::cout << "5 distorcoes: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p1d9)
	    << " Perceptron 1: " << rec1.input(*p1d9) << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p1d10)
	    << " Perceptron 1: " << rec1.input(*p1d10) << std::endl;

  std::cout << "===============================================" << std::endl;
  std::cout << "d) Vendo a saida para os padroes" << std::endl;
  Pattern * p_zero = new Pattern("numbers/0.txt", 0);
  std::cout << "Padrao de 0: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p_zero)
	    << " Perceptron 1: " << rec1.input(*p_zero) << std::endl;
  Pattern * p_one = new Pattern("numbers/1.txt", 1);
  std::cout << "Padrao de 1: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p_one)
	    << " Perceptron 1: " << rec1.input(*p_one) << std::endl;
  Pattern * p_two = new Pattern("numbers/2.txt", 2);
  std::cout << "Padrao de 2: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p_two)
	    << " Perceptron 1: " << rec1.input(*p_two) << std::endl;
  Pattern * p_three = new Pattern("numbers/3.txt", 3);
  std::cout << "Padrao de 3: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p_three)
	    << " Perceptron 1: " << rec1.input(*p_three) << std::endl;
  Pattern * p_four = new Pattern("numbers/4.txt", 4);
  std::cout << "Padrao de 4: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p_four)
	    << " Perceptron 1: " << rec1.input(*p_four) << std::endl;
  Pattern * p_five = new Pattern("numbers/5.txt", 5);
  std::cout << "Padrao de 5: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p_five)
	    << " Perceptron 1: " << rec1.input(*p_five) << std::endl;
  std::cout << "===============================================" << std::endl;
  
  return 0;
}
