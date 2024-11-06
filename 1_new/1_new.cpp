#include <iostream>
#include "FwqList.h"

using namespace std;


int main()
{
    Fwqlist<int> list;
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

}

