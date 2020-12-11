#include "MyVector.h"
#include <iostream>

int main() {
    MyVector<int> v = MyVector<int>(15);
    v.push_back(10);
    v.push_back(20);
    v.push_back(50);
    v.push_back(40);
    v.printVector(); // [10, 20, 50, 40]
    v.pop_back();
    v.printVector(); // [10, 20, 50]
    v.pop_back(1);
    v.printVector(); // [10, 50]
    std::cout << "The second element is " << v[1] << std::endl;
    v.clear();
    std::cout << "Vector is currently empty: " << std::boolalpha << v.empty() << std::endl;
}