#ifndef BIDIRECTIONAL_LIST_ON_ARRAY_H_
#define BIDIRECTIONAL_LIST_ON_ARRAY_H_


#include <initializer_list>
#include <vector>
namespace containers {
template<class T>
class BiDirectionalListOnArray {
 public:
  BiDirectionalListOnArray() : size_(0), capacity_(MIN_CAPACITY), data_(new T[MIN_CAPACITY]) {};

  BiDirectionalListOnArray(const std::initializer_list<T> &list);

  ~BiDirectionalListOnArray();

  BiDirectionalListOnArray(const BiDirectionalListOnArray<T> &other);

  BiDirectionalListOnArray<T> &operator=(const BiDirectionalListOnArray<T> &other);

  BiDirectionalListOnArray(BiDirectionalListOnArray<T> &&other) noexcept;

  BiDirectionalListOnArray<T> &operator=(BiDirectionalListOnArray<T> &&other) noexcept;

  int Size() const {
    return size_;
  }

  int IsEmpty() const {
    return size_ == 0;
  }

  std::vector<T> ToVector() const;

  T *Front();
  T *Back();
  T *Front() const;
  T *Back() const;

  void PushFront(const T &value);

  void PushBack(const T &value);

  void PushFront(T &&value);

  void PushBack(T &&value);

  void PopFront();

  void PopBack();

  void InsertBefore(size_t index, const T &value);

  void InsertAfter(size_t index, const T &value);

  void InsertBefore(size_t index, T &&value);

  void InsertAfter(size_t index, T &&value);

  void Erase(size_t index);

  T *operator[](size_t index);

  T *operator[](size_t index) const;

  bool operator==(const BiDirectionalListOnArray<T> &other) const;

  bool operator!=(const BiDirectionalListOnArray<T> &other) const;

 private:
  T *data_;
  size_t size_ = 0;
  size_t capacity_;

  static const size_t MIN_CAPACITY = 10;
  static const size_t GROWTH_FACTOR = 2;

  void AllocateMemory();
};

template<class T>
BiDirectionalListOnArray<T>::BiDirectionalListOnArray(const std::initializer_list<T> &list) {
  size_ = list.size();
  capacity_ = std::max(size_ * 2, MIN_CAPACITY);
  data_ = new T[capacity_];
  int index = 0;
  for (const T &elem : list) {
    data_[index] = elem;
    ++index;
  }
}

template<class T>
BiDirectionalListOnArray<T>::~BiDirectionalListOnArray() {
  size_ = 0;
  capacity_ = 0;
  delete[] data_;
}

template<class T>
BiDirectionalListOnArray<T>::BiDirectionalListOnArray(const BiDirectionalListOnArray<T> &other) :
    size_(other.size_), capacity_(other.capacity_), data_(new T[capacity_]) {
  for (int i = 0; i < size_; ++i) {
    data_[i] = other.data_[i];
  }
}

template<class T>
BiDirectionalListOnArray<T> &BiDirectionalListOnArray<T>::operator=(
    const BiDirectionalListOnArray<T> &other) {
  if (this == &other) {
    return *this;
  }
  delete[] data_;
  size_ = other.size_;
  capacity_ = other.capacity_;
  data_ = new T[capacity_];
  for (int i = 0; i < size_; ++i) {
    data_[i] = other.data_[i];
  }
  return *this;
}

template<class T>
BiDirectionalListOnArray<T>::BiDirectionalListOnArray(
    BiDirectionalListOnArray<T> &&other) noexcept {
  size_ = other.size_;
  capacity_ = other.capacity_;
  data_ = other.data_;
  other.size_ = 0;
  other.capacity_ = 0;
  other.data_ = nullptr;
}

template<class T>
BiDirectionalListOnArray<T> &BiDirectionalListOnArray<T>::operator=(
    BiDirectionalListOnArray<T> &&other) noexcept {
  if (this == &other) {
    return *this;
  }
  delete[] data_;
  size_ = other.size_;
  capacity_ = other.capacity_;
  data_ = other.data_;
  other.size_ = 0;
  other.capacity_ = 0;
  other.data_ = nullptr;
  return *this;
}

template<class T>
std::vector<T> BiDirectionalListOnArray<T>::ToVector() const {
  std::vector<T> result(size_);
  for (int i = 0; i < size_; ++i) {
    result[i] = data_[i];
  }
  return result;
}

template<class T>
T *BiDirectionalListOnArray<T>::Front() {
  if (size_ == 0) {
    throw std::exception();
  }
  return &data_[0];
}

template<class T>
T *BiDirectionalListOnArray<T>::Back() {
  if (size_ == 0) {
    throw std::exception();
  }
  return &data_[size_ - 1];
}

template<class T>
T *BiDirectionalListOnArray<T>::Front() const {
  if (size_ == 0) {
    throw std::exception();
  }
  return &data_[0];
}

template<class T>
T *BiDirectionalListOnArray<T>::Back() const {
  if (size_ == 0) {
    throw std::exception();
  }
  return &data_[size_ - 1];
}

template<class T>
void BiDirectionalListOnArray<T>::PushFront(const T &value) {
  if (size_ == capacity_) {
    AllocateMemory();
  }
  if (size_ != 0) {
    InsertBefore(0, value);
  } else {
    ++size_;
    if (size_ == capacity_) {
      AllocateMemory();
    }
    data_[0] = value;
  }
}

template<class T>
void BiDirectionalListOnArray<T>::PushBack(const T &value) {
  if (size_ == capacity_) {
    AllocateMemory();
  }
  if (size_ != 0) {
    InsertAfter(size_ - 1, value);
  } else {
    ++size_;
    if (size_ == capacity_) {
      AllocateMemory();
    }
    data_[0] = value;
  }
}

template<class T>
void BiDirectionalListOnArray<T>::PushFront(T &&value) {
  PushFront(value);
}

template<class T>
void BiDirectionalListOnArray<T>::PushBack(T &&value) {
  PushBack(value);
}

template<class T>
void BiDirectionalListOnArray<T>::PopFront() {
  Erase(0);
}

template<class T>
void BiDirectionalListOnArray<T>::PopBack() {
  Erase(size_ - 1);
}

template<class T>
void BiDirectionalListOnArray<T>::InsertBefore(size_t index, const T &value) {
  if (size_ == capacity_) {
    AllocateMemory();
  }
  if (index >= size_) {
    throw std::exception();
  }
  ++size_;
  for (int i = size_ - 1; i > index; --i) {
    data_[i] = data_[i - 1];
  }
  data_[index] = value;
}

template<class T>
void BiDirectionalListOnArray<T>::InsertAfter(size_t index, const T &value) {
  if (size_ == capacity_) {
    AllocateMemory();
  }
  if (index >= size_) {
    throw std::exception();
  }
  ++size_;
  for (int i = size_ - 1; i > index; --i) {
    data_[i] = data_[i - 1];
  }
  data_[index+1] = value;
}

template<class T>
void BiDirectionalListOnArray<T>::InsertBefore(size_t index, T &&value) {
  InsertBefore(index, value);
}

template<class T>
void BiDirectionalListOnArray<T>::InsertAfter(size_t index, T &&value) {
  InsertAfter(index, value);
}

template<class T>
void BiDirectionalListOnArray<T>::Erase(size_t index) {
  if (index >= size_) {
    throw std::exception();
  }
  for (int i = index; i < size_; ++i) {
    data_[i] = data_[i + 1];
  }
  --size_;
}

template<class T>
T *BiDirectionalListOnArray<T>::operator[](size_t index) {
  if (index >= size_) {
    throw std::exception();
  }
  return &data_[index];
}

template<class T>
T *BiDirectionalListOnArray<T>::operator[](size_t index) const {
  if (index >= size_) {
    throw std::exception();
  }
  return &data_[index];
}

template<class T>
bool BiDirectionalListOnArray<T>::operator==(const BiDirectionalListOnArray<T> &other) const {
  if (size_ != other.size_) {
    return false;
  }
  for (int i = 0; i < size_; ++i) {
    if (data_[i] != other.data_[i]) {
      return false;
    }
  }
  return true;
}

template<class T>
bool BiDirectionalListOnArray<T>::operator!=(const BiDirectionalListOnArray<T> &other) const {
  return !(*this == &other);
}

template<class T>
void BiDirectionalListOnArray<T>::AllocateMemory() {
  capacity_ *= GROWTH_FACTOR;
  T *newData = new T[capacity_];
  for (int i = 0; i < size_; ++i) {
    newData[i] = data_[i];
  }
  delete[] data_;
  data_ = newData;
}
}

#endif // BIDIRECTIONAL_LIST_ON_ARRAY_H_
