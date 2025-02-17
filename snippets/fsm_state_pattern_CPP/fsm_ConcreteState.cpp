// CountUpState.cpp
// implements the CountUpState of an up/down-Counter without actions

#include <iostream>
#include "CountUpState.h"
#include "CounterCtrl.h"  // Events are defined here
using namespace std;

CountUpState* CountUpState::getInstance()
{
  static CountUpState instance; // local definition guarantees execution order
  return &instance;             // of initialization
}

CounterState* CountUpState::handle(Counter& entity, CounterCtrl::Event e)
{
  cout << "State: countUpState" << endl;
  if (CounterCtrl::evCount == e)
  {
    // transition actions
    entity.count(1);
    cout << "counter = " << entity.getCounter() << endl;
    // state transition
    return changeState(entity, CountUpState::getInstance());
  }
  else if (CounterCtrl::evStop == e)
  {
    // transition actions
    // state transition
    return changeState(entity, IdleState::getInstance());
  }
  return this;
}