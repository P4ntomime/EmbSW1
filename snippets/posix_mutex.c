// mutex.c
 
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /* for usleep */

static volatile int val = 0;    // shared resource
static pthread_mutex_t valMtx;  // create mutex_t variable

void* threadRoutine(void* arg); // prototype

int main(void)
{
  pthread_t t1; // create pthread_t variable
  pthread_t t2; // create pthread_t variable

  pthread_mutex_init(&valMtx, 0); // init mutex

  pthread_create(&t1, 0, threadRoutine, 0);
  pthread_create(&t2, 0, threadRoutine, 0);

  pthread_join(t1, 0);  // wait for thread to finish
  pthread_join(t2, 0);  // wait for thread to finish

  pthread_mutex_destroy(&valMtx); // destory mutex
    
  return 0;
}

// main routine of each counter thread
void* threadRoutine(void* arg)
{
  unsigned int rState = 17;

  while(1)
  {
    /* non critical section; simulate with usleep() */
    usleep(rand_r(&rState) % 200000);

    /* start of critical section */
    pthread_mutex_lock(&valMtx);  // lock mutex

    if (val < 20)
    {
      /* wait random time between 0s up to 0.3s */
      usleep(rand_r(&rState) % 300000);
      val = val + 1;  // change shared resource 
      printf("val = %2d\n", val);
    }
    else 
    {
      /* end of critical section */
      pthread_mutex_unlock(&valMtx);  // unlock mutex
      break;                          // exit while(1)
    }
    /* end of critical section */
    pthread_mutex_unlock(&valMtx);    // unlock mutex
  }
  pthread_exit(0); // optional, good programming style!
}