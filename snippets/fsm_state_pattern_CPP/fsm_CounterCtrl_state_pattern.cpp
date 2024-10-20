// CounterCtrl.cpp
// implements the Finite State Machine (FSM) of an up/down-Counter
// CounterCtrl is the Context class in the State pattern

#include "Counter.h"  // only needed if there is an entryAction in initState
#include "CounterCtrl.h"
#include "CounterState.h"

CounterCtrl::CounterCtrl(int initValue): 
  entity(initValue),                  // use either line 11 or 12
  pState(CounterState::init(entitiy)) // initial state incl. entryAction
  pState(IdleState::getInstance())    // initial state without entryAction
{
}

void CounterCtrl::process(Event e)
{ // delegates all requests to CounterState
  pState =  pState->handle(entity, e);
}