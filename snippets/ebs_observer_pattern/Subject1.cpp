// Subject1.cpp 
// The observed entity, Model, Subject

#include "Subject1.h"
#include <iostream>
using namespace std;

void Subject1::setState(unsigned int newState) 
{
	state = newState;
	notify();  // inform observers
}

unsigned int Subject1::getState() const 
{
  	return state;
}