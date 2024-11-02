// Observer.h 

#ifndef OBSERVER_H__
#define OBSERVER_H__

class Observer
{
  public:
    // method to update something 
    // (pure virtual)
		virtual void update() const = 0;
		
    // Dtor
		virtual ~Observer() {}
};
#endif