#include <iostream>
#include "MyVector.h"

template <class T>
MyVector<T>::MyVector() {
    // MyVector default constructor- creates a new empty array.

    vectorSize = 0;
    vectorCapacity = 10;
    arr = new T[vectorCapacity];
}

template <class T>
MyVector<T>::MyVector(int size) {
    // MyVector constructor
    // Creates a new array of the given size if it is valid, otherwise of default size (10).

    if (size < 0) {
        size = 10;
    } 
    vectorCapacity = size;
    arr = new T[vectorCapacity];
    vectorSize = 0;
}

template <class T>
MyVector<T>::~MyVector() {
    // MyVector Deconstructor- deletes array.

    delete [] arr;
    arr = 0;
}

template <class T>
int MyVector<T>::size() {
    // Returns the number of elements in the vector.
    return vectorSize;
}

template <class T>
int MyVector<T>::capacity() {
    // Returns the number of elements the vector can hold before more memory must be allocated.

    return vectorCapacity;
}

template <class T>
bool MyVector<T>::empty() {
    // Returns true if the size is 0, otherwise false.
    
    return (vectorSize == 0);
}

template <class T>
void MyVector<T>::push_back(T n) {
    // Adds element n at the back (end) of the vector.

    if (vectorSize >= vectorCapacity) {
        vectorCapacity += 1;
        T* temp = arr;
        arr = new T[vectorCapacity];
        for (int i = 0; i < vectorSize; i++) {
            arr[i] = temp[i];
        }
        delete[] temp;
        temp = 0;
    }
    arr[vectorSize] = n;
    vectorSize += 1;
}

template <class T>
void MyVector<T>::pop_back(int n) {
    // Removes the element at index n from the vector

    if ((n >= 0) && (n < vectorSize)) { // if index n is out of range, func does nothing
        for (int i = n; i < (vectorSize - 1); i++) {
            arr[i] = arr[i+1];
        }
        vectorSize -= 1;
    }
}

template <class T>
void MyVector<T>::pop_back() {
    // Removes the last element in the vector.

    if (vectorSize > 0) { // nothing happens if vector is empty
        T* temp = arr;
        arr = new T[vectorCapacity];
        for (int i = 0; i < (vectorSize - 1); i++) {
            arr[i] = temp[i];
        }
        vectorSize -= 1;

        delete [] temp;
        temp = 0;
    }
}

template <class T>
void MyVector<T>::clear() {
    // Removes all elements from the vector
    vectorSize = 0;
    arr = new T[vectorCapacity];
}

template <class T>
T& MyVector<T>::operator[](int i) {
    if ((i >= vectorSize) || (i < 0)) {
        std::cout << "Invalid index\n";
        exit(0);
    } else {
        return arr[i];
    }
}


template<class T>
void MyVector<T>::printVector(){
    std::cout << "Vector: [";
    for (int i = 0; i < (vectorSize - 1); i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[vectorSize - 1] << "]" << std::endl;
    std::cout << "Size: " << vectorSize << std::endl;
    std::cout << "Capacity: " << vectorCapacity << std::endl;
}