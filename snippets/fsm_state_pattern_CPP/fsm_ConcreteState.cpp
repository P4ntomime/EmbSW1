// IdleState.cpp
// implements the IdleState of an up/down-Counter

#include <iostream>
#include "IdleState.h"
#include "CounterCtrl.h"  // Events are defined here
using namespace std;

IdleState* IdleState::getInstance()
{
  static IdleState instance; // local definition guarantees execution order
  return &instance;
}

CounterState* IdleState::handle(Counter& entity, CounterCtrl::Event e)
{
  cout << "State: idleState" << endl;
  if (CounterCtrl::evUp == e)
  {
    // transition actions
    cout << "counter = " << entity.getCounter() << endl;
    // state transition
    return changeState(entity, CountUpState::getInstance());
  }
  else if (CounterCtrl::evDown == e)
  {
    // transition actions
    cout << "counter = " << entity.getCounter() << endl;
    // state transition
    return changeState(entity, CountDownState::getInstance());
  }
  return this;
}