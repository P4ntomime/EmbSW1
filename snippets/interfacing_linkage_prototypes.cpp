extern "C" void foo(int);     // use C language linkage   -> preferred variant
void hoo(int);                // use C++ language linkage -> preferred variant
extern void goo(int);         // use C++ language linkage -> other variant
extern "C++" void koo(int);   // use C++ language linkage -> other variant

extern "C"
{
  // list multiple prototypes with C linkage or
  // #include C header file(s) -> preferred variant
}