#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);

	int sum = 0;
	int temp;

	do {
		cout << "������ �����: ";
		cin >> temp;
		sum += temp;
	} while (temp != 0);

	cout << "���� �����, �� �� �����: " << sum << '\n';
}