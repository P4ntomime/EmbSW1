// file: header.h
static inline int max(int a, int b)
{
    return a > b ? a : b;
}


// file: main.c
#include "header.h"

int main(void)
{
  int z1 = 4;
  int z2 = 6;
  int m = max((z1, z2));
  // as expected: m = 6, z1 = 4, z2 = 6

  int m = max((++z1, ++z2));
  // as expected: m = 7, z1 = 5, z2 = 7
  return 0;
}