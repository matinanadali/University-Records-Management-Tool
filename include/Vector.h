#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <iostream>

template <class T> class Vector {
  int size;
  T **array;

public:
  Vector();
  Vector(const Vector &vector);            // Copy constructor
  Vector &operator=(const Vector &vector); // Assignment operator
  ~Vector();

  int getSize() const;
  void add(T *item);
  bool removeAt(int index);
  int indexOf(T *item) const;
  T *getAt(int i) const;
  void setAt(int i, T *newItem);
  template <typename U>
  friend std::ostream &operator<<(std::ostream &cout, Vector<U> &vector);
};

// Default constructor
template <class T> Vector<T>::Vector() : size(0), array(nullptr) {}

// Copy constructor
template <class T> Vector<T>::Vector(const Vector &vector) : size(vector.size) {
  array = new T *[size];

  for (int i = 0; i < size; i++) {
    array[i] = vector.array[i] ? new T(*vector.array[i]) : nullptr;
  }
}

// Assignment operator
template <class T> Vector<T> &Vector<T>::operator=(const Vector &vector) {
  if (this != &vector) { // Self-assignment check
    delete[] array;

    // Copy from vector
    size = vector.size;
    array = new T *[size];
    for (int i = 0; i < size; i++) {
      if (vector.array[i] == NULL) {
        array[i] = NULL;
      } else {
        array[i] = new T(*vector.array[i]);
      }
    }
  }
  return *this;
}

// Destructor
template <class T> Vector<T>::~Vector() { delete[] array; }

// Get the size of the vector
template <class T> int Vector<T>::getSize() const { return size; }

// Add an item to the vector
template <class T> void Vector<T>::add(T *item) {
  T **newArray = new T *[size + 1];
  for (int i = 0; i < size; i++) {
    newArray[i] = array[i];
  }
  newArray[size++] = item;

  delete[] array; // Delete the old array to prevent memory leak
  array = newArray;
}

// Find the index of an item in the vector
template <class T> int Vector<T>::indexOf(T *item) const {
  for (int i = 0; i < size; i++) {
    if (array[i] == NULL)
      continue;
    if (*array[i] == *item) {
      return i;
    }
  }
  return -1;
}

// removeAt an item from the vector
template <class T> bool Vector<T>::removeAt(int index) {
  size--;
  array[index] = NULL;
  T **newArray = new T *[size];
  for (int i = 0; i < index; i++) {
    newArray[i] = array[i];
  }
  for (int i = index; i < size; i++) {
    newArray[i] = array[i + 1];
  }

  delete[] array; // Properly delete the old array
  array = newArray;
  return true;
}

// Get an item at a specific index
template <class T> T *Vector<T>::getAt(int i) const { return array[i]; }

// Set an item at a specific index
template <class T> void Vector<T>::setAt(int i, T *newItem) {
  array[i] = newItem;
}

template <class T>
std::ostream &operator<<(std::ostream &cout, Vector<T> &vector) {
  for (int i = 0; i < vector.size; i++) {
    if (vector.array[i] == NULL)
      continue;
    std::cout << *vector.array[i];
    if (i != vector.size - 1)
      std::cout << "\n";
  }
  return std::cout;
}

#endif
