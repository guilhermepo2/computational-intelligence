#include "pattern/pattern.hpp"

class Perceptron
{
private:
  int weights[PATTERN_ROW * PATTERN_COLUMN];
  int size = (PATTERN_ROW * PATTERN_COLUMN);
  int bias = 0;
  Pattern * p_zero = new Pattern("numbers/0.txt", 0);
  Pattern * p_one = new Pattern("numbers/1.txt", 1);
public:
  Perceptron();
  void trainment();
  void input(Pattern input);
  void print_weights();
};
