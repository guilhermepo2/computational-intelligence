#include <iostream>

#define PATTERN_ROW 5
#define PATTERN_COLUMN 6

#define DEBUG 0

class Pattern
{
private:
  std::string file_ref;
  char pattern_vector[PATTERN_ROW * PATTERN_COLUMN];
  int number_equivalent;
  int total_size = PATTERN_ROW * PATTERN_COLUMN;
  
public:
  Pattern(std::string file_ref, int number_equivalent);
  void print_pattern();
  const inline int get_pattern_position(int pos) { return (int)pattern_vector[pos]; }
  const inline int get_number_equivalent() { return number_equivalent; }
  const inline int get_total_size() { return total_size; }
  const inline int get_row_size() { return PATTERN_ROW; }
  const inline int get_column_size() { return PATTERN_COLUMN; }
};
