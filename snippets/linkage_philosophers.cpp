class Philosopher
{
  public:
    // ...
    void live(); // the philosopher's life

  private:
    pthread_attr_t attr;
    pthread_t tid;  // thread id
    // ...
    void lifeThread();  // the (C++) - tread function
    static void* staticWrapper(void* p) // C Wrapper for thread_create()
    {                                   // p must be the this pointer
      static_cast<Philosopher*>(p)->lifeThread();
      return 0;
    }
};


void Philosopher::live()
{
  pthread_attr_t_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
  pthread_create(&tid, &attr, staticWrapper, this);
}