// fooServer.h -> Callback server

#ifndef FOO_SERVER_H__
#define FOO_SERVER_H__

// typeless enum with integer for a failed result
enum {foo_failed = -1};

//function pointer to callback functions
typedef void (*foo_cbFunction)(int);  

// enum with possible events
typedef enum {foo_ev1 = 1,        // foo example event 1 
              foo_ev2,            // foo example event 2
              foo_ev3             // foo example event 3 
              }foo_Event; 

// registers function 'f' on event 'e'
// returns id: success or foo_failed: no success
int foo_registerCb(foo_Event e, foo_cbFunction f);

// unregisters functionId 'id' on event 'e'
// returns id: success or foo_failed: no success
int foo_unregisterCb(foo_Event e, int id);
       
// signals that event 'e' occurred
void foo_signalEvent(foo_Event e);
#endif