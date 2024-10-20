// CountUpState.h
// interface of the CountUpState of an up/down-Counter

#ifndef COUNTUPSTATE_H__
#define COUNTUPSTATE_H__
#include "CounterCtrl.h"  // Events are defined here

class CountUpState : public CounterState // it's a singleton
{
  public:
    static CountUpState* getInstance();
    CounterState*  handle(Counter& entity, CounterCtrl::Event e) override;

  /* -------------------- if actions are used ------------------------------------ */
  protected:
    void entryAction(Counter& entitiy) override;  // only if  default is not enough
    void exitAction(Counter& entitiy) override;   // only if  default is not enough
  /* ----------------------------------------------------------------------------- */
  private:
    CountUpState() {};
};
#endif