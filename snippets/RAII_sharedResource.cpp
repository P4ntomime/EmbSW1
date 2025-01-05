// file: SharedResource.h
class SharedResource
{
  public:
    SharedResource(){pthread_mutex_init(&mutex, 0); }
    ~ SharedResource() {pthread_mutex_destroy(&mutex); }
    pthread_mutex_t* getMutex() {return &mutex;}
  private:
    pthread_mutex_t mutex; // the shared mutex
};