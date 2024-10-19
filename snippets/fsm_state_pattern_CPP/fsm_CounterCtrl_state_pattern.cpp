// CounterCtrl.cpp
// implements the Finite State Machine (FSM) of an up/down-Counter
// CounterCtrl is the Context class in the State pattern

#include "CounterCtrl.h"
#include "CounterState.h"

CounterCtrl::CounterCtrl(int initValue): 
  entity(initValue), 
  pState(IdleState::getInstance()) // initial state
{
}

void CounterCtrl::process(Event e)
{ // delegates all requests to CounterState
  pState =  pState->handle(entity, e);
}