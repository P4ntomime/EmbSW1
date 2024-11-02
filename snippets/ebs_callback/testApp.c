// testApp.c
// this is the client

#include <stdio.h>
#include "fooServer.h"
#include "fooSigGen.h"

// functions to be registered (prototypes)
static void f1(int a);
// ...

int main(void)
{
  enum {maxId = 8};
  int fId[maxId] = {0};
  // register functions on events
  fId[0] = foo_registerCb(foo_ev1, f1);
  fId[1] = foo_registerCb(foo_ev1, f2);
  fId[2] = foo_registerCb(foo_ev1, f3);
  fId[3] = foo_registerCb(foo_ev2, f4);
  fId[4] = foo_registerCb(foo_ev2, f2); // same function registered on two events
  fId[5] = foo_registerCb(foo_ev3, f5);

  for (size_t i = 0; i < maxId; ++i)
  {
    if (foo_failed == fId[i])
      printf("fId[%zu] failed to register\n", i);
  }
  foo_generateSignals();
  
  // unregister some functions
  if (foo_unregisterCb(foo_ev1, fId[0]) == fId[0])
    printf("f1 successfully unregistered from foo_ev1\n");
  else
    printf("failed to unregister f1 from foo_ev1\n");

  if (foo_unregisterCb(foo_ev1, 27) == 27) // should fail: unknown id
    printf("xy successfully unregistered from qr\n");
  else
    printf("failed to unregister (unknown id)\n");
  
  // register functions on events
  printf("try to register f4 on foo_ev2 at fId[6]\n");
  fId[6] = foo_registerCb(foo_ev2, f4); // should fail: too many registered functions
  for (size_t i = 0; i < maxId; ++i)
  {
    if (foo_failed == fId[i])
    {
      printf("fId[%zu] failed to register\n", i);
    }
  }

  foo_generateSignals();
  return 0;
}

// local functions
void f1(int a)
{
  printf("f1() called. Event# = %d.\n", a);
}

// ...