// counterCtrl.c
// implements the Finite State Machine (FSM) of an up/down-Counter

#include <stdio.h>
#include "counterCtrl.h"
#include "counter.h"

typedef enum {idleState,        // idle state
              countUpState,     // counting up at each count event
              countDownState}   // counting down at each count event
             State;

static State currentState = idleState; // holds the current state of the FSM

void cnt_ctrlInit(int initValue)
{
  currentState = idleState;   // set init-state
  cnt_init(initValue);        // set initValue
}

void cnt_ctrlProcess(cnt_Event e)
{
  switch (currentState)
  {
    case idleState:
      printf("State: idleState\n");
      if (cnt_evUp == e)
      {
        // actions (and exit-actions from idleState)
        printf("State: idleState, counter = %d\n", cnt_getCounter());
        // state transition (and entry-actions from countUpState)
        printf("Changing to State: countUpState\n");
        currentState = countUpState;
      }
      else if (cnt_evDown == e)
      {
        // actions (and exit-actions from idleState)
        printf("State: idleState, counter = %d\n", cnt_getCounter());
        // state transition (and entry-actions from countDownState)
        printf("Changing to State: countDownState\n");
        currentState = countDownState;
      }
      break;
      
    case countUpState:
      printf("State: countUpState\n");
      if (cnt_evCount == e)
      {
        // actions
        cnt_count(1);
        printf("State: countUpState, counter = %d\n", cnt_getCounter());
        // state transition
      }
      else if (cnt_evStop == e)
      {
        // actions
        // state transition
        printf("Changing to State: idleState\n");
        currentState = idleState;
      }
      break;
    
    case countUpState:
      // ...
      break;
      
    default:
      break;
  }
}