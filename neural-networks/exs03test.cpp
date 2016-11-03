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
  /*
  std::cout << "===============================================" << std::endl;
  std::cout << "Testando o reconhecimento" << std::endl;
  std::cout << "Padrao 0: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p0) << std::endl
	    << "Perceptron 1: " << rec1.input(*p0) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p0) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p0) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p0) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p0) << std::endl;
  std::cout << std::endl;
  std::cout << "Padrao 1: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p1) << std::endl
	    << "Perceptron 1: " << rec1.input(*p1) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p1) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p1) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p1) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p1) << std::endl;
  std::cout << std::endl;
  std::cout << "Padrao 2: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p2) << std::endl
	    << "Perceptron 1: " << rec1.input(*p2) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p2) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p2) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p2) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p2) << std::endl;
  std::cout << std::endl;
  std::cout << "Padrao 3: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p3) << std::endl
	    << "Perceptron 1: " << rec1.input(*p3) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p3) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p3) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p3) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p3) << std::endl;
  std::cout << std::endl;
  std::cout << "Padrao 4: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p4) << std::endl
	    << "Perceptron 1: " << rec1.input(*p4) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p4) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p4) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p4) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p4) << std::endl;
  std::cout << std::endl;
  std::cout << "Padrao 5: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p5) << std::endl
	    << "Perceptron 1: " << rec1.input(*p5) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p5) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p5) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p5) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p5) << std::endl;
  std::cout << std::endl;
  std::cout << "===============================================" << std::endl;
  */
  std::cout << "===============================================" << std::endl;
  std::cout << "Padroes de 0" << std::endl;
  Pattern * p0d1 = new Pattern("numbers/damaged/0_d1.txt", 0);
  Pattern * p0d2 = new Pattern("numbers/damaged/0_d2.txt", 0);
  Pattern * p0d3 = new Pattern("numbers/damaged/0_d3.txt", 0);
  Pattern * p0d4 = new Pattern("numbers/damaged/0_d4.txt", 0);
  Pattern * p0d5 = new Pattern("numbers/damaged/0_d5.txt", 0);
  Pattern * p0d6 = new Pattern("numbers/damaged/0_d6.txt", 0);
  Pattern * p0d7 = new Pattern("numbers/damaged/0_d7.txt", 0);
  Pattern * p0d8 = new Pattern("numbers/damaged/0_d8.txt", 0);
  Pattern * p0d9 = new Pattern("numbers/damaged/0_d9.txt", 0);
  Pattern * p0d10 = new Pattern("numbers/damaged/0_d10.txt", 0);

  std::cout << "Danificado 1: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p0d1) << std::endl
	    << "Perceptron 1: " << rec1.input(*p0d1) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p0d1) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p0d1) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p0d1) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p0d1) << std::endl;

  std::cout << "Danificado 2: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p0d2) << std::endl
	    << "Perceptron 1: " << rec1.input(*p0d2) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p0d2) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p0d2) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p0d2) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p0d2) << std::endl;

  std::cout << "Danificado 3: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p0d3) << std::endl
	    << "Perceptron 1: " << rec1.input(*p0d3) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p0d3) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p0d3) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p0d3) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p0d3) << std::endl;

  std::cout << "Danificado 4: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p0d4) << std::endl
	    << "Perceptron 1: " << rec1.input(*p0d4) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p0d4) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p0d4) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p0d4) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p0d4) << std::endl;

  std::cout << "Danificado 5: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p0d5) << std::endl
	    << "Perceptron 1: " << rec1.input(*p0d5) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p0d5) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p0d5) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p0d5) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p0d5) << std::endl;

  std::cout << "Danificado 6: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p0d6) << std::endl
	    << "Perceptron 1: " << rec1.input(*p0d6) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p0d6) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p0d6) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p0d6) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p0d6) << std::endl;

  std::cout << "Danificado 7: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p0d7) << std::endl
	    << "Perceptron 1: " << rec1.input(*p0d7) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p0d7) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p0d7) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p0d7) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p0d7) << std::endl;

  std::cout << "Danificado 8: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p0d8) << std::endl
	    << "Perceptron 1: " << rec1.input(*p0d8) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p0d8) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p0d8) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p0d8) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p0d8) << std::endl;

  std::cout << "Danificado 9: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p0d9) << std::endl
	    << "Perceptron 1: " << rec1.input(*p0d9) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p0d9) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p0d9) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p0d9) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p0d9) << std::endl;

  std::cout << "Danificado 10: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p0d10) << std::endl
	    << "Perceptron 1: " << rec1.input(*p0d10) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p0d10) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p0d10) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p0d10) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p0d10) << std::endl;
  std::cout << "===============================================" << std::endl;
  std::cout << "===============================================" << std::endl;
  std::cout << "Padroes de 1" << std::endl;
  Pattern * p1d1 = new Pattern("numbers/damaged/1_d1.txt", 0);
  Pattern * p1d2 = new Pattern("numbers/damaged/1_d2.txt", 0);
  Pattern * p1d3 = new Pattern("numbers/damaged/1_d3.txt", 0);
  Pattern * p1d4 = new Pattern("numbers/damaged/1_d4.txt", 0);
  Pattern * p1d5 = new Pattern("numbers/damaged/1_d5.txt", 0);
  Pattern * p1d6 = new Pattern("numbers/damaged/1_d6.txt", 0);
  Pattern * p1d7 = new Pattern("numbers/damaged/1_d7.txt", 0);
  Pattern * p1d8 = new Pattern("numbers/damaged/1_d8.txt", 0);
  Pattern * p1d9 = new Pattern("numbers/damaged/1_d9.txt", 0);
  Pattern * p1d10 = new Pattern("numbers/damaged/1_d10.txt", 0);

  std::cout << "Danificado 1: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p1d1) << std::endl
	    << "Perceptron 1: " << rec1.input(*p1d1) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p1d1) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p1d1) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p1d1) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p1d1) << std::endl;

  std::cout << "Danificado 2: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p1d2) << std::endl
	    << "Perceptron 1: " << rec1.input(*p1d2) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p1d2) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p1d2) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p1d2) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p1d2) << std::endl;

  std::cout << "Danificado 3: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p1d3) << std::endl
	    << "Perceptron 1: " << rec1.input(*p1d3) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p1d3) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p1d3) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p1d3) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p1d3) << std::endl;

  std::cout << "Danificado 4: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p1d4) << std::endl
	    << "Perceptron 1: " << rec1.input(*p1d4) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p1d4) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p1d4) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p1d4) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p1d4) << std::endl;

  std::cout << "Danificado 5: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p1d5) << std::endl
	    << "Perceptron 1: " << rec1.input(*p1d5) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p1d5) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p1d5) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p1d5) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p1d5) << std::endl;

  std::cout << "Danificado 6: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p1d6) << std::endl
	    << "Perceptron 1: " << rec1.input(*p1d6) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p1d6) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p1d6) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p1d6) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p1d6) << std::endl;

  std::cout << "Danificado 7: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p1d7) << std::endl
	    << "Perceptron 1: " << rec1.input(*p1d7) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p1d7) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p1d7) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p1d7) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p1d7) << std::endl;

  std::cout << "Danificado 8: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p1d8) << std::endl
	    << "Perceptron 1: " << rec1.input(*p1d8) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p1d8) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p1d8) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p1d8) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p1d8) << std::endl;

  std::cout << "Danificado 9: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p1d9) << std::endl
	    << "Perceptron 1: " << rec1.input(*p1d9) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p1d9) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p1d9) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p1d9) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p1d9) << std::endl;

  std::cout << "Danificado 10: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p1d10) << std::endl
	    << "Perceptron 1: " << rec1.input(*p1d10) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p1d10) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p1d10) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p1d10) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p1d10) << std::endl;
  std::cout << "===============================================" << std::endl;

  std::cout << "===============================================" << std::endl;
  std::cout << "Padroes de 2" << std::endl;
  Pattern * p2d1 = new Pattern("numbers/damaged/2_d1.txt", 0);
  Pattern * p2d2 = new Pattern("numbers/damaged/2_d2.txt", 0);
  Pattern * p2d3 = new Pattern("numbers/damaged/2_d3.txt", 0);
  Pattern * p2d4 = new Pattern("numbers/damaged/2_d4.txt", 0);
  Pattern * p2d5 = new Pattern("numbers/damaged/2_d5.txt", 0);
  Pattern * p2d6 = new Pattern("numbers/damaged/2_d6.txt", 0);
  Pattern * p2d7 = new Pattern("numbers/damaged/2_d7.txt", 0);
  Pattern * p2d8 = new Pattern("numbers/damaged/2_d8.txt", 0);
  Pattern * p2d9 = new Pattern("numbers/damaged/2_d9.txt", 0);
  Pattern * p2d10 = new Pattern("numbers/damaged/2_d10.txt", 0);

  std::cout << "Danificado 1: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p2d1) << std::endl
	    << "Perceptron 1: " << rec1.input(*p2d1) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p2d1) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p2d1) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p2d1) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p2d1) << std::endl;

  std::cout << "Danificado 2: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p2d2) << std::endl
	    << "Perceptron 1: " << rec1.input(*p2d2) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p2d2) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p2d2) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p2d2) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p2d2) << std::endl;

  std::cout << "Danificado 3: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p2d3) << std::endl
	    << "Perceptron 1: " << rec1.input(*p2d3) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p2d3) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p2d3) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p2d3) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p2d3) << std::endl;

  std::cout << "Danificado 4: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p2d4) << std::endl
	    << "Perceptron 1: " << rec1.input(*p2d4) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p2d4) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p2d4) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p2d4) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p2d4) << std::endl;

  std::cout << "Danificado 5: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p2d5) << std::endl
	    << "Perceptron 1: " << rec1.input(*p2d5) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p2d5) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p2d5) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p2d5) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p2d5) << std::endl;

  std::cout << "Danificado 6: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p2d6) << std::endl
	    << "Perceptron 1: " << rec1.input(*p2d6) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p2d6) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p2d6) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p2d6) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p2d6) << std::endl;

  std::cout << "Danificado 7: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p2d7) << std::endl
	    << "Perceptron 1: " << rec1.input(*p2d7) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p2d7) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p2d7) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p2d7) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p2d7) << std::endl;

  std::cout << "Danificado 8: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p2d8) << std::endl
	    << "Perceptron 1: " << rec1.input(*p2d8) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p2d8) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p2d8) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p2d8) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p2d8) << std::endl;

  std::cout << "Danificado 9: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p2d9) << std::endl
	    << "Perceptron 1: " << rec1.input(*p2d9) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p2d9) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p2d9) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p2d9) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p2d9) << std::endl;

  std::cout << "Danificado 10: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p2d10) << std::endl
	    << "Perceptron 1: " << rec1.input(*p2d10) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p2d10) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p2d10) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p2d10) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p2d10) << std::endl;
  std::cout << "===============================================" << std::endl;

  std::cout << "===============================================" << std::endl;
  std::cout << "Padroes de 3" << std::endl;
  Pattern * p3d1 = new Pattern("numbers/damaged/3_d1.txt", 0);
  Pattern * p3d2 = new Pattern("numbers/damaged/3_d2.txt", 0);
  Pattern * p3d3 = new Pattern("numbers/damaged/3_d3.txt", 0);
  Pattern * p3d4 = new Pattern("numbers/damaged/3_d4.txt", 0);
  Pattern * p3d5 = new Pattern("numbers/damaged/3_d5.txt", 0);
  Pattern * p3d6 = new Pattern("numbers/damaged/3_d6.txt", 0);
  Pattern * p3d7 = new Pattern("numbers/damaged/3_d7.txt", 0);
  Pattern * p3d8 = new Pattern("numbers/damaged/3_d8.txt", 0);
  Pattern * p3d9 = new Pattern("numbers/damaged/3_d9.txt", 0);
  Pattern * p3d10 = new Pattern("numbers/damaged/3_d10.txt", 0);

  std::cout << "Danificado 1: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p3d1) << std::endl
	    << "Perceptron 1: " << rec1.input(*p3d1) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p3d1) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p3d1) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p3d1) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p3d1) << std::endl;

  std::cout << "Danificado 2: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p3d2) << std::endl
	    << "Perceptron 1: " << rec1.input(*p3d2) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p3d2) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p3d2) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p3d2) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p3d2) << std::endl;

  std::cout << "Danificado 3: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p3d3) << std::endl
	    << "Perceptron 1: " << rec1.input(*p3d3) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p3d3) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p3d3) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p3d3) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p3d3) << std::endl;

  std::cout << "Danificado 4: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p3d4) << std::endl
	    << "Perceptron 1: " << rec1.input(*p3d4) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p3d4) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p3d4) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p3d4) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p3d4) << std::endl;

  std::cout << "Danificado 5: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p3d5) << std::endl
	    << "Perceptron 1: " << rec1.input(*p3d5) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p3d5) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p3d5) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p3d5) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p3d5) << std::endl;

  std::cout << "Danificado 6: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p3d6) << std::endl
	    << "Perceptron 1: " << rec1.input(*p3d6) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p3d6) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p3d6) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p3d6) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p3d6) << std::endl;

  std::cout << "Danificado 7: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p3d7) << std::endl
	    << "Perceptron 1: " << rec1.input(*p3d7) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p3d7) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p3d7) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p3d7) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p3d7) << std::endl;

  std::cout << "Danificado 8: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p3d8) << std::endl
	    << "Perceptron 1: " << rec1.input(*p3d8) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p3d8) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p3d8) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p3d8) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p3d8) << std::endl;

  std::cout << "Danificado 9: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p3d9) << std::endl
	    << "Perceptron 1: " << rec1.input(*p3d9) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p3d9) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p3d9) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p3d9) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p3d9) << std::endl;

  std::cout << "Danificado 10: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p3d10) << std::endl
	    << "Perceptron 1: " << rec1.input(*p3d10) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p3d10) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p3d10) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p3d10) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p3d10) << std::endl;
  std::cout << "===============================================" << std::endl;

  std::cout << "===============================================" << std::endl;
  std::cout << "Padroes de 4" << std::endl;
  Pattern * p4d1 = new Pattern("numbers/damaged/4_d1.txt", 0);
  Pattern * p4d2 = new Pattern("numbers/damaged/4_d2.txt", 0);
  Pattern * p4d3 = new Pattern("numbers/damaged/4_d3.txt", 0);
  Pattern * p4d4 = new Pattern("numbers/damaged/4_d4.txt", 0);
  Pattern * p4d5 = new Pattern("numbers/damaged/4_d5.txt", 0);
  Pattern * p4d6 = new Pattern("numbers/damaged/4_d6.txt", 0);
  Pattern * p4d7 = new Pattern("numbers/damaged/4_d7.txt", 0);
  Pattern * p4d8 = new Pattern("numbers/damaged/4_d8.txt", 0);
  Pattern * p4d9 = new Pattern("numbers/damaged/4_d9.txt", 0);
  Pattern * p4d10 = new Pattern("numbers/damaged/4_d10.txt", 0);

  std::cout << "Danificado 1: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p4d1) << std::endl
	    << "Perceptron 1: " << rec1.input(*p4d1) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p4d1) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p4d1) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p4d1) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p4d1) << std::endl;

  std::cout << "Danificado 2: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p4d2) << std::endl
	    << "Perceptron 1: " << rec1.input(*p4d2) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p4d2) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p4d2) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p4d2) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p4d2) << std::endl;

  std::cout << "Danificado 3: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p4d3) << std::endl
	    << "Perceptron 1: " << rec1.input(*p4d3) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p4d3) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p4d3) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p4d3) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p4d3) << std::endl;

  std::cout << "Danificado 4: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p4d4) << std::endl
	    << "Perceptron 1: " << rec1.input(*p4d4) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p4d4) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p4d4) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p4d4) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p4d4) << std::endl;

  std::cout << "Danificado 5: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p4d5) << std::endl
	    << "Perceptron 1: " << rec1.input(*p4d5) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p4d5) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p4d5) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p4d5) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p4d5) << std::endl;

  std::cout << "Danificado 6: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p4d6) << std::endl
	    << "Perceptron 1: " << rec1.input(*p4d6) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p4d6) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p4d6) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p4d6) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p4d6) << std::endl;

  std::cout << "Danificado 7: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p4d7) << std::endl
	    << "Perceptron 1: " << rec1.input(*p4d7) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p4d7) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p4d7) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p4d7) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p4d7) << std::endl;

  std::cout << "Danificado 8: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p4d8) << std::endl
	    << "Perceptron 1: " << rec1.input(*p4d8) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p4d8) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p4d8) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p4d8) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p4d8) << std::endl;

  std::cout << "Danificado 9: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p4d9) << std::endl
	    << "Perceptron 1: " << rec1.input(*p4d9) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p4d9) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p4d9) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p4d9) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p4d9) << std::endl;

  std::cout << "Danificado 10: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p4d10) << std::endl
	    << "Perceptron 1: " << rec1.input(*p4d10) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p4d10) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p4d10) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p4d10) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p4d10) << std::endl;
  std::cout << "===============================================" << std::endl;

  std::cout << "===============================================" << std::endl;
  std::cout << "Padroes de 5" << std::endl;
  Pattern * p5d1 = new Pattern("numbers/damaged/5_d1.txt", 0);
  Pattern * p5d2 = new Pattern("numbers/damaged/5_d2.txt", 0);
  Pattern * p5d3 = new Pattern("numbers/damaged/5_d3.txt", 0);
  Pattern * p5d4 = new Pattern("numbers/damaged/5_d4.txt", 0);
  Pattern * p5d5 = new Pattern("numbers/damaged/5_d5.txt", 0);
  Pattern * p5d6 = new Pattern("numbers/damaged/5_d6.txt", 0);
  Pattern * p5d7 = new Pattern("numbers/damaged/5_d7.txt", 0);
  Pattern * p5d8 = new Pattern("numbers/damaged/5_d8.txt", 0);
  Pattern * p5d9 = new Pattern("numbers/damaged/5_d9.txt", 0);
  Pattern * p5d10 = new Pattern("numbers/damaged/5_d10.txt", 0);

  std::cout << "Danificado 1: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p5d1) << std::endl
	    << "Perceptron 1: " << rec1.input(*p5d1) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p5d1) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p5d1) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p5d1) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p5d1) << std::endl;

  std::cout << "Danificado 2: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p5d2) << std::endl
	    << "Perceptron 1: " << rec1.input(*p5d2) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p5d2) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p5d2) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p5d2) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p5d2) << std::endl;

  std::cout << "Danificado 3: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p5d3) << std::endl
	    << "Perceptron 1: " << rec1.input(*p5d3) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p5d3) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p5d3) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p5d3) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p5d3) << std::endl;

  std::cout << "Danificado 4: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p5d4) << std::endl
	    << "Perceptron 1: " << rec1.input(*p5d4) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p5d4) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p5d4) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p5d4) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p5d4) << std::endl;

  std::cout << "Danificado 5: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p5d5) << std::endl
	    << "Perceptron 1: " << rec1.input(*p5d5) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p5d5) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p5d5) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p5d5) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p5d5) << std::endl;

  std::cout << "Danificado 6: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p5d6) << std::endl
	    << "Perceptron 1: " << rec1.input(*p5d6) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p5d6) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p5d6) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p5d6) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p5d6) << std::endl;

  std::cout << "Danificado 7: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p5d7) << std::endl
	    << "Perceptron 1: " << rec1.input(*p5d7) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p5d7) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p5d7) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p5d7) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p5d7) << std::endl;

  std::cout << "Danificado 8: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p5d8) << std::endl
	    << "Perceptron 1: " << rec1.input(*p5d8) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p5d8) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p5d8) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p5d8) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p5d8) << std::endl;

  std::cout << "Danificado 9: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p5d9) << std::endl
	    << "Perceptron 1: " << rec1.input(*p5d9) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p5d9) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p5d9) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p5d9) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p5d9) << std::endl;

  std::cout << "Danificado 10: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*p5d10) << std::endl
	    << "Perceptron 1: " << rec1.input(*p5d10) << std::endl
  	    << "Perceptron 2: " << rec2.input(*p5d10) << std::endl
  	    << "Perceptron 3: " << rec3.input(*p5d10) << std::endl
  	    << "Perceptron 4: " << rec4.input(*p5d10) << std::endl
  	    << "Perceptron 5: " << rec5.input(*p5d10) << std::endl;
  std::cout << "===============================================" << std::endl;

  std::cout << "===============================================" << std::endl;
  std::cout << "Padroes de letras" << std::endl;
  Pattern * pa = new Pattern("letters/a.txt", 0);
  Pattern * pe = new Pattern("letters/e.txt", 0);
  Pattern * pt = new Pattern("letters/t.txt", 0);
  Pattern * ph = new Pattern("letters/h.txt", 0);
  Pattern * pc = new Pattern("letters/c.txt", 0);
  Pattern * pn = new Pattern("letters/n.txt", 0);

  std::cout << "Padrao A: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*pa) << std::endl
	    << "Perceptron 1: " << rec1.input(*pa) << std::endl
  	    << "Perceptron 2: " << rec2.input(*pa) << std::endl
  	    << "Perceptron 3: " << rec3.input(*pa) << std::endl
  	    << "Perceptron 4: " << rec4.input(*pa) << std::endl
  	    << "Perceptron 5: " << rec5.input(*pa) << std::endl;

  std::cout << "Padrao E: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*pe) << std::endl
	    << "Perceptron 1: " << rec1.input(*pe) << std::endl
  	    << "Perceptron 2: " << rec2.input(*pe) << std::endl
  	    << "Perceptron 3: " << rec3.input(*pe) << std::endl
  	    << "Perceptron 4: " << rec4.input(*pe) << std::endl
  	    << "Perceptron 5: " << rec5.input(*pe) << std::endl;

  std::cout << "Padrao T: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*pt) << std::endl
	    << "Perceptron 1: " << rec1.input(*pt) << std::endl
  	    << "Perceptron 2: " << rec2.input(*pt) << std::endl
  	    << "Perceptron 3: " << rec3.input(*pt) << std::endl
  	    << "Perceptron 4: " << rec4.input(*pt) << std::endl
  	    << "Perceptron 5: " << rec5.input(*pt) << std::endl;

  std::cout << "Padrao H: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*ph) << std::endl
	    << "Perceptron 1: " << rec1.input(*ph) << std::endl
  	    << "Perceptron 2: " << rec2.input(*ph) << std::endl
  	    << "Perceptron 3: " << rec3.input(*ph) << std::endl
  	    << "Perceptron 4: " << rec4.input(*ph) << std::endl
  	    << "Perceptron 5: " << rec5.input(*ph) << std::endl;

  std::cout << "Padrao C: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*pc) << std::endl
	    << "Perceptron 1: " << rec1.input(*pc) << std::endl
  	    << "Perceptron 2: " << rec2.input(*pc) << std::endl
  	    << "Perceptron 3: " << rec3.input(*pc) << std::endl
  	    << "Perceptron 4: " << rec4.input(*pc) << std::endl
  	    << "Perceptron 5: " << rec5.input(*pc) << std::endl;

  std::cout << "Padrao N: " << std::endl;
  std::cout << "Perceptron 0: " << rec0.input(*pn) << std::endl
	    << "Perceptron 1: " << rec1.input(*pn) << std::endl
  	    << "Perceptron 2: " << rec2.input(*pn) << std::endl
  	    << "Perceptron 3: " << rec3.input(*pn) << std::endl
  	    << "Perceptron 4: " << rec4.input(*pn) << std::endl
  	    << "Perceptron 5: " << rec5.input(*pn) << std::endl;
  std::cout << "===============================================" << std::endl;


  return 0;
}
