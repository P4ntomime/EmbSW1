// Observer1.cpp -> implements an observer

#include "Observer1.h"
#include <iostream>
#include "Subject1.h"
using namespace std;

Observer1::Observer1(Subject1& s) : sub(s)
{
  	sub.attach(*this);
}

void Observer1::update() const
{
	cout << "Observer1 view: " << sub.getState() << endl;
}

Observer1::~Observer1()
{
  	sub.detach(*this);
}