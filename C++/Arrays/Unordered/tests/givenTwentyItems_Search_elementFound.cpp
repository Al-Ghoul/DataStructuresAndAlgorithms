#include "UnorderedArray.h"

int __tests_givenTwentyItems_Search_elementFound(int argc, char *argv[])
{
  Unordered_Array<int, 20> array;
  for (size_t index{0}; index < array.Capacity(); ++index)
    array.Insert(index);

  if (!array.Search(17))
    return 1;

  return 0;
}