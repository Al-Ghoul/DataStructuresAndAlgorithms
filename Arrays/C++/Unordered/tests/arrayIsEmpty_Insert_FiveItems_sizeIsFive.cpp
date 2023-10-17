#include "UnorderedArray.h"

int __tests_arrayIsEmpty_Insert_FiveItems_sizeIsFive(int argc, char *argv[])
{
  Unordered_Array<int, 20> array;

  constexpr size_t expectedSize = 5;
  for (size_t i{0}; i < expectedSize; ++i)
    array.Insert(i * i);

  if (array.Size() != expectedSize)
    return 1;

  return 0;
}