#include <iostream>
#include "PriorityQueue.h"

int main()
{
	PriorityQueue queue;

	queue.insert(5);
	queue.insert(10);
	queue.insert(2);
	queue.insert(8);
	queue.insert(6);
	queue.insert(1);

	std::cout << queue.getMin() << std::endl;
	std::cout << queue.extractMin() << std::endl;
	std::cout << queue.extractMin() << std::endl;
	std::cout << queue.extractMin() << std::endl;
	std::cout << queue.extractMin() << std::endl;
	std::cout << queue.extractMin() << std::endl;
	std::cout << queue.extractMin() << std::endl;
	std::cout << queue.isEmpty() << std::endl;
	queue.extractMin();

	system("pause");
	return 0;
}