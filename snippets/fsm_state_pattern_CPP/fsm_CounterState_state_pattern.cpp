// CounterState.cpp
// implements all states of an up/down-Counter

#include <iostream>
#include "CounterState.h"
using namespace std;

// only if actions are used:
CounterState* CounterState::init(Counter& entity)  // it's static
{
  CounterState* initState = IdleState::getInstance();
  initState->entryAction(entity);      // executes entry action into init state
  return initState;
}

CounterState* CounterState::changeState(Counter& entity,
                                        Action ptransAction, // only with actions
                                        CounterState* pnewState)
{
  exitAction(entity);               // polymorphic call of exit action
  (this->*ptransAction)(entity);    // call of transition action
  pnewState->entryAction(entity);   // polymorphic call of entry action
  return pnewState;                 
}

// default implementations of entryActions() and exitAction() 
// ...