#include "spperceptron.hpp"
#include <iostream>

int main()
{
  SPPerceptron rec0, rec1, rec2, rec3, rec4, rec5;
  Pattern * p0 = new Pattern("numbers/0.txt", 0);
  Pattern * p1 = new Pattern("numbers/1.txt", 1);
  Pattern * p2 = new Pattern("numbers/2.txt", 2);
  Pattern * p3 = new Pattern("numbers/3.txt", 3);
  Pattern * p4 = new Pattern("numbers/4.txt", 4);
  Pattern * p5 = new Pattern("numbers/5.txt", 5);

  // Perceptron que reconhece 0
  rec0.add_pattern(p0);
  rec0.add_pattern(p1);
  rec0.add_pattern(p2);
  rec0.add_pattern(p3);
  rec0.add_pattern(p4);
  rec0.add_pattern(p5);

  // Perceptron que reconhece 1
  rec1.add_pattern(p1);
  rec1.add_pattern(p0);
  rec1.add_pattern(p2);
  rec1.add_pattern(p3);
  rec1.add_pattern(p4);
  rec1.add_pattern(p5);

  // Perceptron que reconhece 2
  rec2.add_pattern(p2);
  rec2.add_pattern(p0);
  rec2.add_pattern(p1);
  rec2.add_pattern(p3);
  rec2.add_pattern(p4);
  rec2.add_pattern(p5);

  // Perceptron que reconhece 3
  rec3.add_pattern(p3);
  rec3.add_pattern(p0);
  rec3.add_pattern(p1);
  rec3.add_pattern(p2);
  rec3.add_pattern(p4);
  rec3.add_pattern(p5);

  // Perceptron que reconhece 4
  rec4.add_pattern(p4);
  rec4.add_pattern(p0);
  rec4.add_pattern(p1);
  rec4.add_pattern(p2);
  rec4.add_pattern(p3);
  rec4.add_pattern(p5);

  // Perceptron que reconhece 5
  rec5.add_pattern(p5);
  rec5.add_pattern(p0);
  rec5.add_pattern(p1);
  rec5.add_pattern(p2);
  rec5.add_pattern(p3);
  rec5.add_pattern(p4);

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
  std::cout << "Treinamento Perceptron - Para Padrao 2" << std::endl;
  std::cout << "a) e b)" << std::endl;
  rec2.trainment();
  std::cout << "Bias: " << rec2.get_bias() << std::endl;
  rec2.print_weights();
  std::cout << "===============================================" << std::endl;
  std::cout << "Treinamento Perceptron - Para Padrao 3" << std::endl;
  std::cout << "a) e b)" << std::endl;
  rec3.trainment();
  std::cout << "Bias: " << rec3.get_bias() << std::endl;
  rec3.print_weights();
  std::cout << "===============================================" << std::endl;
  std::cout << "Treinamento Perceptron - Para Padrao 4" << std::endl;
  std::cout << "a) e b)" << std::endl;
  rec4.trainment();
  std::cout << "Bias: " << rec4.get_bias() << std::endl;
  rec4.print_weights();
  std::cout << "===============================================" << std::endl;
  std::cout << "Treinamento Perceptron - Para Padrao 5" << std::endl;
  std::cout << "a) e b)" << std::endl;
  rec5.trainment();
  std::cout << "Bias: " << rec5.get_bias() << std::endl;
  rec5.print_weights();
  std::cout << "===============================================" << std::endl;
  
}
