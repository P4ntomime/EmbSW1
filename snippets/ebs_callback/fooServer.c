// fooServer.c --> Callback server

#include "fooServer.h"
#include <stddef.h>

enum {ev1Num = 3,   // max number of registered functions for event ev1      
      ev2Num = 2,   // dito ev2    
      ev3Num = 2};  // dito ev3

// definition of function tables
static foo_cbFunction ev1Client[ev1Num] = {0};  // clients for event ev1
static foo_cbFunction ev2Client[ev2Num] = {0};  // clients for event ev2
static foo_cbFunction ev3Client[ev3Num] = {0};  // clients for event ev3

// local function declarations
static int insertCb(foo_cbFunction f, foo_cbFunction client[], int evNum);
// inserts callback function 'f' in list 'client[]'

static int deleteCb(int id, foo_cbFunction client[], int evNum);
// deletes callback functionId 'id' in list 'client[]'

static void notify(foo_cbFunction client[], int evNum, int arg);
// notifies all registered clients

// interface functions' definitions
int foo_registerCb(foo_Event e, foo_cbFunction f)
{
  switch (e)
  {
    case foo_ev1:
      return insertCb(f, ev1Client, ev1Num);
    case foo_ev2:
      return insertCb(f, ev2Client, ev2Num);
    case foo_ev3:
      return insertCb(f, ev3Client, ev3Num);
    default:
      break;
  }
  return foo_failed; // no success if I get here
}

int foo_unregisterCb(foo_Event e, int id)
{
  switch (e)
  {
    case foo_ev1:
      return deleteCb(id, ev1Client, ev1Num);
    case foo_ev2:
      return deleteCb(id, ev2Client, ev2Num);
    case foo_ev3:
      return deleteCb(id, ev3Client, ev3Num);
    default:
      break;
  }
  return foo_failed; // no success if I get here
}

void foo_signalEvent(foo_Event e)
{
  switch (e)
  {
    case foo_ev1:
      // in this example, only the event # is passed as argument
      notify(ev1Client, ev1Num, e);
      break;
    case foo_ev2:
      notify(ev2Client, ev2Num, e);
      break;
    case foo_ev3:
      notify(ev3Client, ev3Num, e);
      break;
    default:
      break;
  }
}

// local functions
int insertCb(foo_cbFunction f, foo_cbFunction client[], int evNum)
{
  for (size_t i = 0; i < evNum; ++i)
  {
    if (0 == client[i]) // free entry found
    {
      client[i] = f;
      return i;  // success
    }
  }
  return foo_failed;   // number of registered functions exceeded
}

int deleteCb(int id, foo_cbFunction client[], int evNum)
{
  if (id < evNum && id >= 0)
  {
    client[id] = 0;
    return id;  // success
  }
  else
  {
    return foo_failed;   // illegal id
  }
}

void notify(foo_cbFunction client[], int evNum, int arg)
{
  for (size_t i = 0; i < evNum; ++i)
  {
    if (client[i] != 0) // entry found
    {
      client[i](arg);   // call the registered client through function pointer
    }                       
  }
}