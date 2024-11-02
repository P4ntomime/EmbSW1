// fooSigGen.c
// Signal generator implementation

#include "fooServer.h"
#include <stdio.h>

// interface functions' definitions
void foo_generateSignals(void)
{
  int answer;
  
  do
  {
    printf("------------------------------\n");
    printf("\nChoose event to be signalled\n");
    printf("    (1)     Event 1\n");
    printf("    (2)     Event 2\n");
    printf("    (3)     Event 3\n");
    printf("\n    (0)     Exit\n");
    printf("\n\nYour choice: ");
    scanf("%d", &answer);
    printf("\n------------------------------\n");
    switch (answer)
    {
      case 1:
        foo_signalEvent(foo_ev1);
        break;
      case 2:
        foo_signalEvent(foo_ev2);
        break;
      case 3:
        foo_signalEvent(foo_ev3);
        break;
      default:
        break;
    }
  } while (answer != 0);
}