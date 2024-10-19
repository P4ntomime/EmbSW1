// CounterState.h
// implements an up/down-Counter
// this file contains all classes of the state machine

#ifndef COUNTERSTATE_H__
#define COUNTERSTATE_H__
#include "CounterCtrl.h"  // Events are defined here

class CounterState  // abstract base class
{
  public:
    virtual CounterState* handle(Counter& entity, CounterCtrl::Event e) = 0;
    // returns new state
  protected:    // only inherited classes may use these member functions
    CounterState* changeState(Counter& entity, CounterState* pnewState);
};

class IdleState : public CounterState // it's a singleton
{
  public:
    static IdleState* getInstance();
    CounterState*  handle(Counter& entity, CounterCtrl::Event e) override;
  private:
    IdleState() {};
};

class CountUpState : public CounterState // it's a singleton
{
  public:
    static CountUpState* getInstance();
    CounterState*  handle(Counter& entity, CounterCtrl::Event e) override;
  private:
    CountUpState() {};
};

class CountDownState : public CounterState // it's a singleton
{
  public:
    static CountDownState* getInstance();
    CounterState*  handle(Counter& entity, CounterCtrl::Event e) override;
  private:
    CountDownState() {};
};
#endif