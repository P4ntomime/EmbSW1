// CounterCtrl.cpp
// implements the Finite State Machine (FSM) of an up/down-Counter as a simple table

#include <iostream>
#include "CounterCtrl.h"
#include "Counter.h"
using namespace std;

const CounterCtrl::Transition CounterCtrl::fsm[] =  // this table defines the fsm
{//currentState     triggering event  action function                 next state
  {idleState,       evUp,             &CounterCtrl::actionIdleUp,     countUpState},
  {idleState,       evDown,           &CounterCtrl::actionIdleDown,   countDownState},
  {countUpState,    evCount,          &CounterCtrl::actionUpUp,       countUpState},
  {countUpState,    evStop,           &CounterCtrl::actionDoNothing,  idleState},
  {countDownState,  evCount,          &CounterCtrl::actionDownDown,   countDownState},
  {countDownState,  evStop,           &CounterCtrl::actionDoNothing,  idleState}
};

CounterCtrl::CounterCtrl(int initValue) :   // initializations with initialization list
  currentState(idleState),
  myCounter(initValue)
{
}

void CounterCtrl::process(Event e)    // execution engine, this function never changes!
{
  // determine number of transitions automatically
  for (size_t i = 0; i < sizeof(fsm) / sizeof(Transition); ++i) 
  {
    // is there an entry in the table?
    if (fsm[i].currentState == currentState && fsm[i].ev == e) 
    {
      (this->*fsm[i].pAction)();
      currentState = fsm[i].nextState
      break;
    }
  }
}

// action functions
void CounterCtrl::actionIdleUp(void)
{
  cout << "State: idleState, counter = " << myCounter.getCounter() << endl;
}

void CounterCtrl::actionIdleDown(void)
{
  cout << "State: idleState, counter = " << myCounter.getCounter() << endl;
}

void CounterCtrl::actionDoNothing(void)
{
}
// ...