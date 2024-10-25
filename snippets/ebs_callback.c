int foo_registerCb(foo_Event e, foo_cbFunction f);
// registers function 'f' on event 'e'
// sometimes called attach()


typedef void (*foo_cbFunction)(int);
// Schnittstelle: void f(int)

foo_cbFunction evClient[evNum] = {0};


for(size_t i = 0; i < evNum; ++i)
{
    if(evClient[i] != 0)    // entry found
    {
        evClient[i](arg);   // call client through function ptf
    }
}