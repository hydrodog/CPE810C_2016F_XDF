#include <iostream>
#include "content.h"
#include <list>

using namespace std;

int main() {
  /* This is a sample code, it shows how to use our classes for other groups  */
  Content sample;

  list<char> SampleText;
  SampleText = sample.exportContent();
  list<char>::iterator itText=SampleText.begin();
  for(;itText != SampleText.end();itText++) {
        cout << *itText << endl;
  }

  list<char> SampleFont;
  SampleFont = sample.contentFont();
  list<char>::iterator itFont=SampleFont.begin();
  for(;itFont != SampleFont.end();itFont++) {
        cout << *itFont << endl;
  }

  return 0;
}
