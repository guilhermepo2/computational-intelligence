#include "../pattern/pattern.hpp"

class Perceptron
{
private:
  int weights[PATTERN_ROW * PATTERN_COLUMN];
  int size = (PATTERN_ROW * PATTERN_COLUMN);
  int bias = 0;
  int learning_rate;
  Pattern * p_zero = new Pattern("../numbers/0.txt", 0);
  Pattern * p_one = new Pattern("../numbers/1.txt", 1);
public:
  Perceptron(int = 1);
  void trainment();
  int input(Pattern& pattern);
  void print_weights();
  const inline int get_bias() { return this->bias; }
};
