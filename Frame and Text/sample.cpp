#include <iostream>
#include <content.h>

using namespace std;

int main() {
  /* This is a sample code, it shows how to use our classes for other groups  */
  Content sample;
  cout << sample.exportContent() << endl;
  cout << sample.contentFont() << endl;
  return 0;
}
