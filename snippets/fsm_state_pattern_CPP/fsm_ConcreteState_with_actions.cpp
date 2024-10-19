// CountUpState.cpp
// implements the CountUpState of an up/down-Counter with actions

#include <iostream>
#include "CountUpState.h"
#include "CounterCtrl.h"  // Events are defined here
using namespace std;

// class CountUpState
CountUpState* CountUpState::getInstance()
{
  static CountUpState instance;
  return &instance;
}

CounterState* CountUpState::handle(Counter& entity, CounterCtrl::Event e)
{
  cout << "State: countUpState" << endl;
  if (CounterCtrl::evCount == e)
  {
    // state transition
    return changeState(entity, &CountUpState::countUp, CountUpState::getInstance());
  }
  else if (CounterCtrl::evStop == e)
  {
    // state transition
    return changeState(entity, &CountUpState::emptyAction, IdleState::getInstance());
  }
  return this;
}

void CountUpState::entryAction(Counter& entity)
{
  cout << "Entering countUpState" << endl;
}

void CountUpState::exitAction(Counter& entity)
{
  cout << "Exiting from countUpState" << endl;
}