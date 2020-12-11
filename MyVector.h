#pragma once

template <class T>
class MyVector{
private:
    int vectorSize;
    int vectorCapacity;
    T* arr;
public:
   MyVector();
   MyVector(int size);
   ~MyVector();
   bool empty();
   void push_back(T n);
   int size();
   int capacity();
   void pop_back(int n);
   void pop_back();
   void clear();
   T& operator[](int i);
   void printVector();
};
#include "MyVector.cxx"