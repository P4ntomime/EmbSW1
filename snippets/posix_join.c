#include <pthread.h>  // for threads API
#include <stdio.h>
#include <unistd.h>   // for usleep()

// function prototype
void* printDashes(void* arg);

int main(void)
{
  int ret;
  pthread_t dasher; // pthread_t instance

  printf("start");

  // starts thread -> immediately returns
  // (thread maybe not fully started yet)
  ret = pthread_create(&dasher, 0,
                       printDashes, 0);
  if (ret)
  {
    printf("ERROR CODE: %d\n", ret);
    return -1;
  }
  // main thread shall wait until 
  // dasher is finished
  ret = pthread_join(dasher, 0);
  if (ret) 
  {
    printf("ERROR CODE: %d\n", ret);
    return -1;
  }
  
  printf("end\n");
  return 0;
}

void* printDashes(void* arg)
{
  for (size_t i = 0; i<20; ++i)
  {
    usleep(40000);
    putchar('-');
    fflush(stdout); // write character-
                    // wise and
                    // don't buffer
  }
  return 0;
}