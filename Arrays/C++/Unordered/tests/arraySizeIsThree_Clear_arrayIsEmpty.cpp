#include "UnorderedArray.h"

int __tests_arraySizeIsThree_Clear_arrayIsEmpty(int argc, char *argv[])
{
  Unordered_Array<int, 20> array;

  constexpr size_t elementsCount = 3;
  for (size_t i{0}; i < elementsCount; ++i)
    array.Insert(i * i);

  if (array.Size() != 3) return 1;

  array.Clear();
  if (!array.IsEmpty()) return 1;

  return 0;
}