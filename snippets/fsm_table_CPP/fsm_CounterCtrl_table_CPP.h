// CounterCtrl.h
// implements the Finite State Machine (FSM) of an up/down-Counter as a simple table

#ifndef COUNTERCTRL_H__
#define COUNTERCTRL_H__
#include "Counter.h"

class CounterCtrl
{
  /* ------------------------------ NO CHANGES ------------------------------*/
  public:
    enum Event{evUp,       // count upwards
               evDown,     // count downwards
               evCount,    // count (up or down)
               evStop};    // stop counting

    CounterCtrl(int initValue = 0);   // C-tor

    void process(Event e);  // execution engine
    // changes the state of the FSM based on the event 'e'
    // starts the actions

  private:
    enum State{idleState,         // idle state
               countUpState,      // counting up at each count event
               countDownState};   // counting down at each count event

    State currentState;           // holds the current state of the FSM
    Counter myCounter;            // holds the counter for calculation
    
    /* -------------------------------- CHANGES -------------------------------*/

    typedef void (CounterCtrl::*Action)(void);   // function ptr for action function
  
    // action functions (must match with  function pointer!)
    void actionIdleUp(void);
    void actionIdleDown(void);
    void actionDoNothing(void);   // ensure that there is always a valid fkt-ptr
    void actionUpUp(void);
    void actionDownDown(void);
    
    struct Transition
    {
      State currentState;   // current state
      Event ev;             // event triggering the transition
      Action pAction;       // pointer to action function
      State nextState;      // next state
    };

    // static open array for transision structs
    static const Transition fsm[];
};
#endif