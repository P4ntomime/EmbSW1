// testApp.cpp 
// client using observer pattern

#include <iostream>
#include "Subject1.h"
#include "Observer1.h"
using std::cout;
using std::endl;

int main(void)
{
  Subject1 myS;
  Observer1 myO(myS);
  myS.setState(23);
  myS.setState(87);
  
  return 0;
}