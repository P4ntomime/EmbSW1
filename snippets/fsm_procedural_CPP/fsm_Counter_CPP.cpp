// Counter.cpp
// implements an up/down-Counter

#include "Counter.h"

Counter::Counter(int val): countValue(val)
{
}

void Counter::count(int step)
{
  countValue += step;
}

int Counter::getCounter() const
{
  return countValue;
}

void Counter::setCounter(int val)
{
  countValue = val;
}