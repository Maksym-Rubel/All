#include <iostream>
#include "FwqList.h"

using namespace std;


int main()
{
	Fwqlist<int> list;
	Fwqlist<int> list2;

	for (size_t i = 0; i < 5; i++)
	{
		list.addHead(rand() % 50);
		list.print();
	}

	cout << "Remove head" << endl;
	/*while (!list.empty())
	{
		list.removeHead();
		list.print();
	}*/




	//list.clear();
	//list.print();

	list.addTail(rand() % 50);
	list.print();


	list2.clone(list);
	list.print();
	list2.print();
	list.addTail(rand() % 50);
	list.print();
	list2.print();


	Fwqlist<int> list3 = list + list2;
	list3.print();
	Fwqlist<int> list4 = list * list2;
	list4.print();

}

