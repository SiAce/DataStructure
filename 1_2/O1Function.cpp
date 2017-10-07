#include<iostream>

using namespace std;

int sum(int n) {
	if (n % 2 == 0) {
		return -n / 2;
	}
	else
	{
		return (n + 1) / 2;
	}
}

int main() {
	for (int i = 1; i < 11; i++) {
		cout << sum(i) << endl;
	}
	return 0;
}
