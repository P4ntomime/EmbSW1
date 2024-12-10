// file: main.c
#define MAX(a,b) ((a)>(b) ? (a) : (b))

int main(void)
{
  int z1 = 4;
  int z2 = 6;
  int m = MAX((z1, z2));
  // expectation: m = 6, z1 = 4, z2 = 6
  // true values: m = 6, z1 = 4, z2 = 6

  int m = MAX((++z1, ++z2));
  // expectation: m = 7, z1 = 5, z2 = 7
  // true values: m = (*@\crd{8}@*), z1 = 5, z2 = (*@\crd{8}@*)
  return 0;
}





m = MAX((++z1, ++z2)); // expanded to
m = ((++z1)>(++z2) ? (++z1) : (++z2));

// plug in values from example
// z1 = 4, z2 = 6
m = (((*@\crd{5}@*)) > ((*@\crd{7}@*)) ? (++z1) : ((*@\crd{8}@*)));
// z2 is incremented twice!

// -> m = (*@\crd{8}@*), z1 = 5, z2 = (*@\crd{8}@*)