// IdleState.h
// implements the IdleStatde of an up/down-Counter

#ifndef IDLESTATE_H__
#define IDLESTATE_H__
#include "CounterCtrl.h"  // Events are defined here

class IdleState : public CounterState // it's a singleton
{
  public:
    static IdleState* getInstance();
    CounterState*  handle(Counter& entity, CounterCtrl::Event e) override;
  private:
    IdleState() {};
};
#endif