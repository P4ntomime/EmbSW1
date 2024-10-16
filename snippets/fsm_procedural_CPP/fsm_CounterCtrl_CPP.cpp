// CounterCtrl.cpp
// implements the Finite State Machine (FSM) of an up/down-Counter

#include <iostream>
#include "CounterCtrl.h"
#include "Counter.h"
using namespace std;

CounterCtrl::CounterCtrl(int initValue) : 
  currentState(idleState),
  myCounter(initValue)
{
}

void CounterCtrl::process(Event e)
{
  switch (currentState)
  {
    case idleState:
      cout << "State: idleState" << endl;
      if (evUp == e)
      {
        // actions (and exit-actions from idleState)
        cout << "State: idleState, counter = " << myCounter.getCounter() << endl;
        // state transition (and entry-actions from countUpState)
        cout << "Changing to State: countUpState" << endl;
        currentState = countUpState;
      }
      else if (evDown == e)
      {
        // actions (and exit-actions from idleState)
        cout << "State: idleState, counter = " << myCounter.getCounter() << endl;
        // state transition (and entry-actions from countDownState)
        cout << "Changing to State: countDownState" << endl;
        currentState = countDownState;
      }
      break;
      
    case countUpState:
      cout << "State: countUpState" << endl;
      if (evCount == e)
      {
        // actions
        myCounter.count(1);
        cout << "State: countUpState, counter = " << myCounter.getCounter() << endl;
        // state transition
      }
      else if (evStop == e)
      {
        // actions
        // state transition
        cout << "Changing to State: idleState" << endl;
        currentState = idleState;
      }
      break;
      
    case countDownState:
      // ...
      break;
      
    default:
      break;
  }
}