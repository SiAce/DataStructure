#include <iostream>
#include "heap.h"

using namespace std;

template< class Type >
void priorityQueue<Type>::percolateDown(int hole) 
{
	int child;
	Type tmp = array[hole];

	for (; hole * 2 <= currentSize; hole = child) 
	{
		child = hole * 2;

		if (child != currentSize && array[child + 1] < array[child]) 
		{
			child++;
		}

		if (array[child] < tmp) {
			array[hole] = array[child];
		}
		else
		{
			break;
		}

	}

	array[hole] = tmp;
}

template< class Type >
void priorityQueue<Type>::printHeap()
{
	for (int i = 1; i <= currentSize; i++) 
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

template< class Type >
void priorityQueue<Type>::adjustOrder()
{
	int second;
	int the_other;
	int third;

	if (array[2] < array[3]) 
	{
		second = 2;
	}
	else
	{
		if (array[2] == array[3]) 
		{
			return;
		}

		second = 3;
	}

	the_other = (second == 2) ? 3 : 2;

	if (second * 2 > currentSize) 
	{
		return;
	}

	if (second * 2 == currentSize) 
	{
		if (array[the_other] > array[second * 2]) 
		{
			Type tmp;
			tmp = array[the_other];
			array[the_other] = array[second * 2];
			array[second * 2] = tmp;
		}
		else
		{
			return;
		}
	}

	if (second * 2 < currentSize)
	{
		if (array[the_other] <= array[second * 2]
			&& array[the_other] <= array[second * 2 + 1])
		{
			return;
		}
		else
		{
			int smaller = (array[second * 2] <= array[second * 2 + 1]) 
				? (second * 2) : (second * 2 + 1);
			Type tmp = array[the_other];
			array[the_other] = array[smaller];
			array[smaller] = tmp;
			percolateDown(smaller);
		}
	}

}

int main() {
	int a[16] = { 0,
		1,
		2, 9,
		3, 4, 10, 11,
		5, 6, 7, 8, 12, 13, 14, 15
	};
	priorityQueue<int> pq(a, 15);
	pq.adjustOrder();
	pq.printHeap();

	return 0;
}