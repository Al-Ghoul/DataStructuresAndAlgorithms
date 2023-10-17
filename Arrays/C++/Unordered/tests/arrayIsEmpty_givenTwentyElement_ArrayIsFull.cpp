#include "UnorderedArray.h"

int __tests_arrayIsEmpty_givenTwentyElement_ArrayIsFull(int argc, char *argv[])
{
  constexpr size_t elementsCount = 20;
  Unordered_Array<int, elementsCount> array;

  for (size_t i{0}; i < elementsCount; ++i)
    array.Insert(i * i);

  if (!array.IsFull())
    return 1;

  return 0;
}