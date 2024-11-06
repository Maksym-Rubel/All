
#include <iostream>
#include "MyArray.h"
int main()
{
    MyArray<int> arr;
    arr.setSize(5, 2);
    arr.Add(10);
    arr.Add(20);
    arr.Add(30);
    arr.Add(40);
    arr.Add(50);
    cout << "Array size: " << arr.getSize() << endl;
    for (size_t i = 0; i < arr.getSize(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    arr.InsertAt(2, 25);
    for (size_t i = 0; i < arr.getSize(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    MyArray<int> arr2;
    arr2.Add(35);
    arr2.Add(45);
    arr.InsertAt(4, arr2);
    for (size_t i = 0; i < arr.getSize(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    arr.RemoveAt(1, 2); 
    for (size_t i = 0; i < arr.getSize(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    arr.FreeExtra();
    for (size_t i = 0; i < arr.getSize(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

