static pthread_mutex_t m;
//...
void f()
{
  pthread_mutex_lock(&m);
  // do sth in crit. section
  // problem: exception occurs
  pthread_mutex_unlock(&m);
}


class ResourceLock
{
  public:
    ResourceLock(pthread_mutex_t& mx) : mutex(mx) {pthread_mutex_lock(&mutex); }
    ~ResourceLock() {pthread_mutex_unlock(&mutex); }
  private:
    pthread_mutex_t& mutex; // reference to mutex of shared resource
};

void f()
{
  { 
    ResourceLock lock(myMutex); // calls Ctor
    // do sth in crit. section
    // no problem if exception occurs
  } // Dtor called -> mutex always unlocked
  //...
}