void bar(int count)
{
  int *myVariableSizedArray = new int[count];
  delete[] myVariableSizedArray;
}

void foo()
{
  int somevariable;
  bar(8);
}

int main(int argc, char **argv)
{
  foo();
}