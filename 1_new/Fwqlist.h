
#pragma once
#include <iostream>
using namespace std;

template<typename T>
struct Node
{
	T data;
	Node* next;
	Node(const T& data = T(), Node* next = nullptr)
		:data(data), next(next) {}



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
	void clone(const Fwqlist<T>& other);
	Fwqlist<T> operator+(const Fwqlist<T>& other) const;
	Fwqlist<T> operator*(const Fwqlist<T>& other) const;

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
	auto tmp = head; // ïî÷èíàºìî ç ïî÷àòêó ñïèñêó
	cout << "List: \t";
	while (tmp != nullptr) // âèâîäèìî äîêè íå äîéøëè äî ê³íöÿ
	{
		cout << tmp->data << "\t";
		tmp = tmp->next; // ïåðåõîäèìî äî íàñòóïíîãî âóçëà
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

template<typename T>
inline void Fwqlist<T>::clone(const Fwqlist<T>& other)
{
	clear();

	if (other.head == nullptr) {
		head = nullptr;
		return;
	}
	head = new Node<T>(other.head->data);
	Node<T>* tmp = head;
	Node<T>* tmp_other = other.head->next;

	while (tmp_other != nullptr) {
		tmp->next = new Node<T>(tmp_other->data);
		tmp = tmp->next;
		tmp_other = tmp_other->next;
	}
	
}

template<typename T>
inline Fwqlist<T> Fwqlist<T>::operator+(const Fwqlist<T>& other) const
{
	Fwqlist<T> result;
	auto tmp = head;
	while (tmp != nullptr)
	{
		result.addTail(tmp->data);
		tmp = tmp->next;
	}
	auto other_tmp = other.head;
	while (other_tmp != nullptr)
	{
		result.addTail(other_tmp->data);
		other_tmp = other_tmp->next;
	}
	return result;
}

template<typename T>
inline Fwqlist<T> Fwqlist<T>::operator*(const Fwqlist<T>& other) const
{
	Fwqlist<T> result;
	auto tmp = head;
	while (tmp != nullptr)
	{
		auto other_tmp = other.head;
		while (other_tmp != nullptr)
		{
			if (tmp->data == other_tmp->data) {
				result.addTail(tmp->data);
				break;
			}
			other_tmp = other_tmp->next;
		}
		tmp = tmp->next;
	}
	return result;
}
