#pragma once

#include <vector>

class PriorityQueue
{
public:
	int getMin();
	int extractMin();
	void insert(int);
	bool isEmpty();

private:
	std::vector<int> queue;

	void heapifyDown(int);
	void heapifyUp(int);
	int parent(int);
	int leftChild(int);
	int rightChild(int);
};
