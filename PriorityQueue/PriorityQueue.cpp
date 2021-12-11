#include "PriorityQueue.h"
#include <iostream>
#include <stdexcept>

int PriorityQueue::getMin()
{
	try
	{
		if (queue.empty())
		{
			throw std::underflow_error("Queue underflow!");
		}
		return queue.front();
	}
	catch (const std::underflow_error& ue)
	{
		std::cerr << ue.what() << std::endl;
	}
}

int PriorityQueue::extractMin()
{
	try
	{
		if (queue.empty())
		{
			throw std::underflow_error("Queue underflow!");
		}
		std::swap(queue.front(), queue.back());

		int min = queue.back();

		queue.pop_back();
		heapifyDown(0);
		return min;
	}
	catch (const std::underflow_error& ue)
	{
		std::cerr << ue.what() << std::endl;
	}
}

void PriorityQueue::insert(int key)
{
	queue.push_back(key);
	heapifyUp(queue.size() - 1);
}

bool PriorityQueue::isEmpty()
{
	return queue.empty();
}

void PriorityQueue::heapifyDown(int index)
{
	int left = leftChild(index);
	int right = rightChild(index);
	int min = index;

	if (left < queue.size() && queue.at(left) < queue.at(min))
	{
		min = left;
	}
	if (right < queue.size() && queue.at(right) < queue.at(min))
	{
		min = right;
	}
	if (min != index)
	{
		std::swap(queue.at(min), queue.at(index));
		heapifyDown(min);
	}
}

void PriorityQueue::heapifyUp(int index)
{
	int par = parent(index);

	if (index && queue.at(index) < queue.at(par))
	{
		std::swap(queue.at(index), queue.at(par));
		heapifyUp(par);
	}
}

inline int PriorityQueue::parent(int index)
{
	return (index - 1) / 2;
}

inline int PriorityQueue::leftChild(int index)
{
	return (2 * index + 1);
}

inline int PriorityQueue::rightChild(int index)
{
	return (2 * index + 2);
}
