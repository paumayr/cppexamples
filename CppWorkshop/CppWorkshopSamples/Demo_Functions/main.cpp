#include <iostream>

int Circumference(int w, int h); // function declaration

int main(int argc, char **argv)
{
  int w = 10;
  int h = 20;
  int circumFerence = Circumference(w, h);
  std::cout << "circumference = " << circumFerence << std::endl;
  return 0;
}

int Circumference(int w, int h)  // function definition
{
  return 2 * (w + h);
}

