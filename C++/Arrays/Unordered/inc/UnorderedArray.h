#pragma once

template <typename T, size_t SIZE = 50>
class Unordered_Array
{
public:
  Unordered_Array();
  ~Unordered_Array();

  void Clear();

  bool IsEmpty() const;
  bool IsFull() const;
  size_t Size() const;
  size_t Capacity() const;
  bool Search(T item) const;

  void Insert(T item);
  T Replace(T item, size_t position);
  void Delete(T item);

  T &operator[](size_t index);

protected:
  T array_[SIZE];
  size_t size_;
  size_t capacity_;
};