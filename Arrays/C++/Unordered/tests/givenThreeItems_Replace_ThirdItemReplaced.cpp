#include "UnorderedArray.h"

int __tests_givenThreeItems_Replace_ThirdItemReplaced(int argc, char *argv[])
{
  Unordered_Array<int, 20> array;
  for (size_t index{0}; index < 3; ++index)
    array.Insert(index);

  if (array[2] != 2)
    return 1;

  if (array.Replace(5, 2) != 2)
    return 1;

  if (array[2] != 5)
    return 1;

  return 0;
}