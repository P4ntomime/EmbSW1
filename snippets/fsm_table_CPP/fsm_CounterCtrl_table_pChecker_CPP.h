    // ...

    typedef bool (CounterCtrl::*Checker)(Event); // function ptr for checker function
    typedef void (CounterCtrl::*Action)(void);   // no change here!

    // check functions
    bool checkIdleUp(Event e);
    bool checkIdleDown(Event e);
    // ...

    struct Transition
    {
      State currentState;   // current state
      Checker pChecker;     // pointer to checker function
      Action pAction;       // pointer to action function
      State nextState;      // next state
    };
    // ...