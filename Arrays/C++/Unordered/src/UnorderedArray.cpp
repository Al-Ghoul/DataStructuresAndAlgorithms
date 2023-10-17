#include "UnorderedArray.h"
#include <iostream>

template <typename T, size_t SIZE>
Unordered_Array<T, SIZE>::Unordered_Array() : capacity_(SIZE), size_(0)
{
}

template <typename T, size_t SIZE>
Unordered_Array<T, SIZE>::~Unordered_Array()
{
  Unordered_Array::Clear(); // This is useless anyways.
}

template <typename T, size_t SIZE>
bool Unordered_Array<T, SIZE>::IsEmpty() const
{
  return size_ == 0;
}

template <typename T, size_t SIZE>
bool Unordered_Array<T, SIZE>::IsFull() const
{
  return size_ == capacity_;
}

template <typename T, size_t SIZE>
size_t Unordered_Array<T, SIZE>::Size() const
{
  return size_;
}

template <typename T, size_t SIZE>
size_t Unordered_Array<T, SIZE>::Capacity() const
{
  return capacity_;
}

template <typename T, size_t SIZE>
void Unordered_Array<T, SIZE>::Clear()
{
  size_ = capacity_ = 0;
}

template <typename T, size_t SIZE>
bool Unordered_Array<T, SIZE>::Search(T item) const
{
  // Since this is unordered array, the search must be linear which is O(n)
  for (size_t index = 0; index < size_; ++index)
  {
    if (array_[index] == item)
      return true;
  }

  return false;
}

template <typename T, size_t SIZE>
T &Unordered_Array<T, SIZE>::operator[](size_t index)
{
  if (index >= capacity_)
    std::cout << "Array Out of bound\n";
  return array_[index];
}

template <typename T, size_t SIZE>
void Unordered_Array<T, SIZE>::Insert(T item)
{
  if (!IsFull())
    array_[size_++] = item;
  else
    std::cout << "Array is full\n";
}

template <typename T, size_t SIZE>
T Unordered_Array<T, SIZE>::Replace(T item, size_t position)
{
  if (position >= capacity_)
    std::cout << "Array Out of bound\n";
  T temp = array_[position];
  array_[position] = item;
  return temp;
}

template <typename T, size_t SIZE>
void Unordered_Array<T, SIZE>::Delete(T item)
{
  size_t itemIndex = -1;
  // Since this is unordered array, the search must be linear which is O(n)
  for (size_t index = 0; index < size_; ++index)
  {
    if (item == array_[index])
    {
      itemIndex = index;
      break;
    }
  }

  // If the item is not found, return early.
  if (itemIndex == -1)
    return;

  // Else we have to shift the items to the left
  // If it is the last item, just decrease the size
  if (itemIndex == (capacity_ - 1))
    --size_;
  else
  {
    // If it is somewhere else, we have to shift the items to left, 1 by 1.
    for (size_t index = itemIndex; index < size_ - 1; ++index)
      array_[index] = array_[index + 1];

    --size_;
  }
}

template Unordered_Array<int, 20>;