#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

enum {maxCount = 10, numThreads = 3, countLimit = 12};

volatile static int count = 0;			    // shared resource
static pthread_mutex_t countMutex; 		  // the mutex
static pthread_cond_t countThresholdCv; // the condition variable

void* incCount(void* t); 		// count thread function
void* watchCount(void* t);  // watch thread function

int main(void)
{
  int t[numThreads] = {1, 2, 3};
  pthread_t threads[numThreads];
  
  pthread_mutex_init(&countMutex, 0);		    // init mutex
  pthread_cond_init (&countThresholdCv, 0); // init condition variable
  
  pthread_create(&threads[0], 0, watchCount, (void*)&t[0]);
  pthread_create(&threads[1], 0, incCount, (void*)&t[1]);
  pthread_create(&threads[2], 0, incCount, (void*)&t[2]);
  
  for (int i = 0; i < numThreads; ++i)
    pthread_join(threads[i], 0);

  pthread_mutex_destroy(&countMutex);
  pthread_cond_destroy(&countThresholdCv);
  pthread_exit(0);
}

void* incCount(void* t)
{
  int myId = *(int*)t;
  printf("Starting incCount(): thread %ld\n", myId);
  for (int i = 0; i < maxCount; ++i)
  {
    pthread_mutex_lock(&countMutex); 			// start of critical section
    ++count;
    // Check the value of count and signal waiting thread when condition is
    // reached. Note that this occurs while mutex is locked.
    if (count == countLimit)
      pthread_cond_signal(&countThresholdCv); 	// signal waiting thread
    
    pthread_mutex_unlock(&countMutex); 			// end of critical section
    
    sleep(1); // Do some work so threads can alternate on mutex lock
  }
  pthread_exit(0);
}

void* watchCount(void* t)
{
  int myId = *(int*)t;
  printf("Starting watchCount(): thread %ld\n", myId);

  // Note that pthread_cond_wait() will automatically and atomically unlock
  // mutex while it waits. Also, note that if countLimit is reached before this
  // routine is run by the waiting thread, the loop will be skipped to prevent
  // pthread_cond_wait() from never returning.

  pthread_mutex_lock(&countMutex); // start of critical section
  while (count < countLimit)
  {
    pthread_cond_wait(&countThresholdCv, &countMutex); // wait on condition
    printf("watchCount(): condition signal received.\n");
    count += 125; // updating the value of count
  }
  pthread_mutex_unlock(&countMutex); // end of critical section
  pthread_exit(0);
}