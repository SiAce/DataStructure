#include<iostream>

using namespace std;

struct element
{
	int key;
	int data;
};

void sort(int n, element a[])
{
	int i = 0;
	element tmp, tmp2;

	while (i < n)
	{
		if (a[i].key == i)
		{
			i++;
		}
		else
		{
			tmp = a[i];
			a[i] = a[tmp.key];
			a[tmp.key] = tmp;
		}
	}
}

int main()
{
	element a[20];

	for (int i = 0; i < 20; i++)
	{
		a[19 - i].key = i;
		a[19 - i].data = i*i;
	}

	sort(20, a);

	for (int i = 0; i < 20; i++)
	{
		cout << a[i].data << endl;
	}
	return 0;
}