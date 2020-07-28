#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
  char *str = "hello world!";
  fstream out("log.txt", ios::out);

  out.write(str, 15);

  out.close();

  cout << "end";
}
