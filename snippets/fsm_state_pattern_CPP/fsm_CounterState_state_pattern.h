// CounterState.h
// implements an up/down-Counter

#ifndef COUNTERSTATE_H__
#define COUNTERSTATE_H__
#include "CounterCtrl.h"  // Events are defined here

class CounterState  // abstract base class
{
  public:
    // should be called first, returns new state (if actions are used)
    static CounterState* init(Counter& entity);

    virtual CounterState* handle(Counter& entity, CounterCtrl::Event e) = 0;
    // returns new state
  protected:    // only inherited classes may use these member functions
    CounterState* changeState(Counter& entity, 
                              Action ptransAction,  // only if actions are used
                              CounterState* pnewState);

    // if actions are used, the following must be added:
    virtual void entryAction(Counter& entity) {};
    virtual void exitAction(Counter& entity) {};
    typedef void (CounterState::*Action)(Counter& entity);   // ptr to action function

    // transition actions
    void emptyAction(Counter& entity) {};
    void showCounter(Counter& entity);
    void countUp(Counter& entity);
    void countDown(Counter& entity);
};