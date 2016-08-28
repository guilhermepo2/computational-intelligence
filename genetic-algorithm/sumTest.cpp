#include <iostream>

int main()
{
  int a = 0;

  for(int i = 0; i < 100; i++)
    {
      a += 100000;
      std::cout << "value: " << a << std::endl;
    }
  
  return 0;
}
