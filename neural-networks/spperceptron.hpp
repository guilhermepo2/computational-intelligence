#include "pattern/pattern.hpp"
#include <vector>

class SPPerceptron
{
private:
  int weights[PATTERN_ROW * PATTERN_COLUMN];
  int size = PATTERN_ROW * PATTERN_COLUMN;
  int bias = 0;
  int learning_rate;
  std::vector<Pattern*> patterns;
public:
  SPPerceptron(int = 1);
  void trainment();
  int input(Pattern& input);
  void print_weights();
  void add_pattern(Pattern * p);
  const inline int get_bias() { return this->bias; }
  const inline int get_size() { return this->size; }
};
