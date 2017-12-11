#include "close_hash_table.h"

using namespace std;

template <class Type>
closeHashTable<Type>::closeHashTable(int length, int(*f)(const Type &x))
{
	size = length;
	array = new node[size];
	key = f;
}

template <class Type>
bool closeHashTable<Type>::insert(const Type &x)
{
	int position = key(x) % size;
	for (int i = 0; i < size; i++)
	{
		if (array[position].state != 0)
		{
			position = (position + 1) % size;
		}
		else
		{
			array[position].data = x;
			array[position].state = 1;
			return true;
		}
	}

	return false;
}

template <class Type>
bool closeHashTable<Type>::remove(const Type &x)
{
	int position = key(x) % size;

	for (int i = 0; i < size; i++)
	{
		if (array[position].state == 1
			&& array[position].data == x)
		{
			array[position].state = 2;
			return true;
		}
		else
		{
			position = (position + 1) % size;
		}
	}
	return false;
}

template <class Type>
bool closeHashTable<Type>::find(const Type &x) const
{
	for (int i = 0; i < size; i++)
	{
		if (array[position].state == 1
			&& array[position].data == x)
		{
			return true;
		}
		else
		{
			position = (position + 1) % size;
		}
	}
	return false;
}

template <class Type>
void closeHashTable<Type>::rehash()
{
	for (int i = 0; i < size; i++)
	{
		if (array[i].state == 2)
		{
			array[i].state = 1;
		}
	}
}

int main()
{
	struct MyStruct
	{
		int row;
		int column;
		int data;
	};

	MyStruct a[10000];

	return 0;
}