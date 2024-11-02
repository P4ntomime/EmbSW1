// Observer1.h -> implements an observer

#ifndef OBSERVER1_H__
#define OBSERVER1_H__

#include "Observer.h"

class Subject1;  // forward declaration to subject

class Observer1 : public Observer
{
  public:
		Observer1(Subject1& s);       // Ctor with reference to subject
		void update() const override; // method to update something
		virtual ~Observer1();         // Dtor
  
  private:
    Subject1& sub;
};
#endif