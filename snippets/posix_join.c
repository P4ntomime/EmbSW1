#include <pthread.h>  // for threads API
#include <stdio.h>
#include <unistd.h>   // for usleep()

// function prototype
void* printDashes(void* arg);

int main(void)
{
  int ret;
  pthread_t dasher;

  printf("start");
  ret = pthread_create(&dasher, 0,
                       printDashes, 0);
  if (ret)
  {
    printf("ERROR CODE: %d\n", ret);
    return -1;
  }
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
    fflush(stdout); // write character-wise
                    // don't buffer
  }
  return 0;
}