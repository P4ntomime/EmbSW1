int foo_registerCb(foo_Event e, foo_cbFunction f);
// registers function 'f' on event 'e' -> 'id' is returned
// sometimes called attach()

int foo_unregisterCb(foo_Event e, int id);
// unregisters functionId 'id' on event 'e' -> 'id' is returned
// sometimes called detach()

typedef void (*foo_cbFunction)(int);
// Schnittstelle: void f(int)

foo_cbFunction evClient[evNum] = {0};   
// Note: NULL instead of 0 if stdio.h is included

void notify(foo_cbFunction client[], int evNum, int arg)
{
    for(size_t i = 0; i < evNum; ++i)
    {
        if(evClient[i] != 0)    // entry found
        {
            evClient[i](arg);   // call client through function ptf
        }
    }
}

void foo_signalEvent(foo_Event e)
{
    switch(e)
    {
        case foo_ev1:
            // only event passed as argument
            notify(ev1Client, ev1Num, e);
        break;
        case foo_ev2:
            // only event passed as argument
            notify(ev2Client, ev2Num, e);
        break;
        // ...
        default:
        break;
    }
}