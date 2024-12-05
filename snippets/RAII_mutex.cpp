static pthread_mutex_t m;
//...
void f()
{
  pthread_mutex_lock(&m);
  // do sth in crit. section
  // problem: exception occurs
  pthread_mutex_unlock(&m);
}


// file: Resourcelock.h
class ResourceLock
{
  public:
    ResourceLock(pthread_mutex_t& mx) : mutex(mx) {pthread_mutex_lock(&mutex); }
    ~ResourceLock() {pthread_mutex_unlock(&mutex); }
  private:
    pthread_mutex_t& mutex; // reference to mutex of shared resource
};


// file: main.cpp (or other .cpp file)
void f()
{
  { // place critical section inside a block
    ResourceLock lock(myMutex); // calls Ctor
    // do sth in critical section -> no problem if exception occurs
  } // Dtor called when block is left (out of scope) -> mutex always unlocked
  //...
}