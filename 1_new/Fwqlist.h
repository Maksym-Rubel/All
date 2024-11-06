#pragma once
#include <iostream>
using namespace std;

template<typename T>
struct Node
{
	T data;
	Node * next;
	Node(const T& data = T(), Node* next = nullptr)
		:data(data), next(next){}


	
};
template<typename T>

class Fwqlist
{
public:
	Fwqlist() = default;
	bool empty() const;
	void print() const;
	
	~Fwqlist();

	void addHead(const T& data);
	void addTail(const T& data);
	void removeHead();
	void clear();


private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	size_t size = 0;




};

template<typename T>
inline bool Fwqlist<T>::empty() const
{
	return head == nullptr;
}

template<typename T>
inline void Fwqlist<T>::print() const
{
	if (empty()) {
		cout << "List is empty" << endl;
		return;
	}
	auto tmp = head; // починаЇмо з початку списку
	cout << "List: \t";
	while (tmp != nullptr) // виводимо доки не дойшли до к≥нц€
	{
		cout << tmp->data << "\t";
		tmp = tmp->next; // переходимо до наступного вузла
	}
	cout << endl;

}

template<typename T>
inline Fwqlist<T>::~Fwqlist()
{
	clear();
}

template<typename T>
inline void Fwqlist<T>::addHead(const T& data)
{
	Node<T>* tmp = new Node<T>(data, head);
	if (empty())
		tail = tmp;
	head = tmp;
	++size;
}

template<typename T>
inline void Fwqlist<T>::addTail(const T& data)
{
	Node<T>* tmp = new Node<T>(data, nullptr);
	if (empty()) {
		head = tmp;
	}
	else
		tail->next = tmp;
	tail = tmp;
	++size;


}

template<typename T>
inline void Fwqlist<T>::removeHead()
{
	if (empty())
		return;
	auto tmp = head;
	head = head->next;
	if (empty())
		tail = head;

	delete tmp;
	--size;
}

template<typename T>
inline void Fwqlist<T>::clear()
{
	if (empty())
		return;

	while (head != nullptr)
	{
		removeHead();
	}
	tail = nullptr;
	size = 0;
}
