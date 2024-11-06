#pragma once
#include <iostream>
using namespace std;
template <typename T>
class MyArray
{
public:
	size_t getSize() const;
	void setSize(const size_t& capacity, const size_t& grow);
	size_t GetUpperBound() const;
	bool isEmpty() const;
	void FreeExtra();
	void RemoveAll();
	void Add(const T& value);
	const T& getAt(const size_t& index) const;
	void setAt(const size_t& index, const T& value);
	MyArray<T> Append(const MyArray<T>& one, const MyArray<T>& two);
	T operator[](size_t index) const; // get
	T& operator[](size_t index); // set
	T* GetData() const;
	void InsertAt(size_t index, const T& value);
	void InsertAt(size_t index, const MyArray<T>& values);
	void RemoveAt(size_t index, size_t count = 1);
private:
	T* arr = nullptr;
	size_t size = 0;
	size_t capacity = 0;
	size_t grow = 0;
	bool full() const;
	void resize(size_t newCapacity);
	void reserve();
};

template<typename T>
inline size_t MyArray<T>::getSize() const
{
	return size;
}

template<typename T>
inline void MyArray<T>::setSize(const size_t& capacity, const size_t& grow)
{
	this->grow = grow;
	if (arr == nullptr)
	{
		arr = new T[capacity];
	}
	else if (this->capacity > capacity)
	{
		T* tmp = new T[capacity];
		for (size_t i = 0; i < capacity; i++)
		{
			tmp[i] = arr[i];
		}
		delete[] arr;
		arr = tmp;
	}
	else if (this->capacity < capacity)
	{
		T* tmp = new T[capacity];
		for (size_t i = 0; i < this->capacity; i++)
		{
			tmp[i] = arr[i];
		}
		delete[] arr;
		arr = tmp;
	}
	this->capacity = capacity;
}

template<typename T>
inline size_t MyArray<T>::GetUpperBound() const
{
	return size - 1;
}

template<typename T>
inline bool MyArray<T>::isEmpty() const
{
	return size == 0;
}

template<typename T>
inline void MyArray<T>::FreeExtra()
{
	if (arr == nullptr) {
		cout << "Array is empty !" << endl;
		return;
	}
	if (size == capacity)
		return;

	T* tmp = new T[size];
	for (size_t i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	delete[] arr;
	arr = tmp;

}

template<typename T>
inline void MyArray<T>::RemoveAll()
{
	/*
		delete[] arr;
		size = 0;
		capacity = 0;
	*/
	size = 0;
}

template<typename T>
inline void MyArray<T>::Add(const T& value)
{
	if (full())
		reserve();
	arr[size++] = value;
}

template<typename T>
inline const T& MyArray<T>::getAt(const size_t& index) const
{
	static T errValue;
	if (index >= size)
		return errValue;
	return arr[index];
}

template<typename T>
inline void MyArray<T>::setAt(const size_t& index, const T& value)
{
	if (index >= size)
		return;
	arr[index] = value;
}

template<typename T>
inline MyArray<T> MyArray<T>::Append(const MyArray<T>& one, const MyArray<T>& two)
{
	MyArray<T> res;
	res.setSize(one.size + two.size, one.grow);
	for (size_t i = 0; i < one.size; i++)
	{
		res.Add(one[i]);
	}
	for (size_t i = 0; i < two.size; i++)
	{
		res.Add(two[i]);
	}
	return res;
}

template<typename T>
inline T MyArray<T>::operator[](size_t index) const
{
	static T errValue;
	if (index >= size)
		return errValue;
	return arr[index];
}

template<typename T>
inline T& MyArray<T>::operator[](size_t index)
{
	static T errValue;
	if (index >= size)
		return errValue;
	return arr[index];
}

template<typename T>
inline T* MyArray<T>::GetData() const
{
	return arr;
}

template<typename T>
inline void MyArray<T>::InsertAt(size_t index, const T& value)
{
	if (index > size) {
		cout << "Index error" << endl;
		return;
	}
	if (full()) {
		reserve();
	}
	for (size_t i = size; i > index; --i) {
		arr[i] = arr[i - 1];
	}

	arr[index] = value;
	++size;
}

template<typename T>
inline void MyArray<T>::InsertAt(size_t index, const MyArray<T>& values)
{
	if (index > size) {
		cout << "Index error" << endl;
		return;
	}
	if (size + values.size > capacity) {
		resize(size + values.size + grow);
	}
	for (size_t i = size + values.size - 1; i >= index + values.size; --i) {
		arr[i] = arr[i - values.size];
	}
	for (size_t i = 0; i < values.size; ++i) {
		arr[index + i] = values.arr[i];
	}

	size += values.size;
}

template<typename T>
inline void MyArray<T>::RemoveAt(size_t index, size_t count)
{
	if (index >= size || count == 0) {
		cout << "Error" << endl;
		return;
	}
	if (index + count > size) {
		count = size - index;
	}
	for (size_t i = index; i < size - count; ++i) {
		arr[i] = arr[i + count];
	}

	size -= count;
}

template<typename T>
inline bool MyArray<T>::full() const
{
	return size == capacity;
}

template<typename T>
inline void MyArray<T>::resize(size_t newCapacity)
{
	T* tmp = new T[newCapacity];
	for (size_t i = 0; i < size; i++) {
		tmp[i] = arr[i];
	}
	delete[] arr;
	arr = tmp;
	capacity = newCapacity;
}

template<typename T>
inline void MyArray<T>::reserve()
{
	T* tmp = new T[capacity += grow];
	for (size_t i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	delete[] arr;
	arr = tmp;
}
