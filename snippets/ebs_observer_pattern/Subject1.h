// Subject1.h 
// observed entity, Model, Subject

#ifndef SUBJECT1_H__
#define SUBJECT1_H__

#include "Subject.h"

class Subject1 : public Subject
{
  public:
    // sets the state of the subject
		void setState(unsigned int newState);
		
    // returns ok: success 
    // or failed: no success
		unsigned int getState() const;
  private:
		unsigned int state = 0;
};
#endif