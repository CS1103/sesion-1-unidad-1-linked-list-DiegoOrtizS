#include "linked_list.h"
#include <time.h>

int main()
{
	srand(time(NULL));

	utec::CLinkedList ll{};
	utec::CLinkedList ll2{};
	utec::CLinkedList ll3{};
	utec::CLinkedList ll5{};
	utec::CLinkedList ll6{};

	ll3.push_back(-1);

	for (size_t i = 0; i < 5; ++i)
	{
		ll3.push_front(i);
	}

	utec::CLinkedList ll4(ll3);

	ll4.insert(2, 500);
	ll4.push_back(-10);

	ll3.erase(2);
	ll3.erase(1);

	ll2.pop_front();
	ll2.insert(0,100);
	ll2.push_back(4);
	ll2.push_front(1);
	ll2.insert(2,5);
	ll2.pop_back();

	ll.pop_back();
	ll.push_front(3);
	ll.erase(0);

	for (size_t i = 0; i < 10; i++)
	{
		ll.push_back(i + 1);
		ll.push_front(i);
	}
	ll.pop_front();
	ll.erase(ll.size() - 1);
	ll.push_back(150);
	ll.insert(2, 300);

	for (size_t i = 0; i < 2; i++)
	{
		ll.pop_front();
		ll.pop_back();
	}

	cout << ll.imprimir_list() << endl;
	cout << ll2.imprimir_list() << endl;
	cout << ll3.imprimir_list() << endl;
	cout << ll4.imprimir_list() << endl;

	ll5 = move(ll3);
	ll6 = ll2;
	ll6.erase(rand() % ll6.size());
	ll5.insert(2, -57);
	cout << "La lista 3 ahora está vacía porque se aplicó un move constructor " << ll3.imprimir_list() << endl;
	cout << ll5.imprimir_list() << endl;
	cout << ll2.imprimir_list() << endl;
	cout << ll6.imprimir_list() << endl;

}