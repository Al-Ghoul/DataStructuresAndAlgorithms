#include "UnorderedArray.h"

int __tests_arrayIsEmpty_givenCapacityOfTwenty_capacityTwenty(int argc, char *argv[])
{
  Unordered_Array<int, 20> array;
  if (array.Capacity() != 20)
    return 1;

  return 0;
}