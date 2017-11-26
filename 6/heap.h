#ifndef HEAP_H_
#define HEAP_H_
#include<iostream>

using namespace std;

template <class Type>
class priorityQueue
{
public:
	priorityQueue(int capacity = 100) 
	{
		array = new Type[capacity];
		maxSize = capacity;
		currentSize = 0;
	}
	priorityQueue(const Type data[], int size)
	{
		maxSize = size + 10;
		currentSize = size;
		array = new Type[size + 1];
		for (int i = 0; i <= size; i++) {
			array[i] = data[i];
		}
	}
	~priorityQueue() {
		delete[] array;
	}

	bool isEmpty() const { return currentSize == 0; }
//	void enQueue(const Type &x);
//	Type deQueue();
	Type getHead() const { return array[1]; }
	void adjustOrder();
	void printHeap();

private:
	int currentSize;
	Type * array;
	int maxSize;

//	void doubleSpace();
//	void buildHeap();
	void percolateDown(int hole);

};

#endif // HEAP_H_
