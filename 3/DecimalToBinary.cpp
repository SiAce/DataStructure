#include<iostream>

using namespace std;

void DecimalToBinary(int decimal) 
{
	if (decimal != 0) 
	{
		DecimalToBinary(decimal / 2);
		cout << decimal % 2;
	}
}

int main() {
	for (int i = 0; i < 17; i++) {
		DecimalToBinary(i);
		cout << endl;
	}
	return 0;
}

