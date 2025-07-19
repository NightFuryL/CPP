#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main()
{
#ifdef _WIN32
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
#endif

	{
		// ������� ������������ �������
		vector<int> numbers = { 1, 2, 3, 4, 5 };
		cout << "Vector elements: ";
		for (const auto& num : numbers) {
			cout << num << " ";
		}
		cout << "Vector size: " << numbers.size() << endl;
		cout << "Vector capacity: " << numbers.capacity() << endl;
		cout << "Vector element at index 2: " << numbers.at(2) << endl;

		// ��������� �������� �� ������� � �����
		numbers.push_back(6);

		// ��������� �������� �� ������� � ������������� ���������
		// numbers.begin() - �� ��������, ���� ����� �� ������ ������� �������
		numbers.insert(numbers.begin() + 1, 10);

		cout << "Vector elements after modify: ";
		for (const auto& num : numbers) {
			cout << num << " ";
		}

		numbers.pop_back(); // ��������� ���������� ��������

		numbers.erase(numbers.begin() + 1); // ��������� �������� �� ��������

		numbers.clear(); // �������� �������

		// ��������, �� ������ �������
		if(numbers.empty()) {
			cout << "\nVector is empty after clear." << endl;
		} else {
			cout << "\nVector is not empty." << endl;
		}
	}

	{
		// ������� ������������ ���������
		vector<int> numbers = { 13, 2, 23, -4, 8 };
		list<int> numberList = { 13, 2, 23, -4, 8 };

		// ���������� ������� �� ������
		// sort ����������� ��������� ��� ������� �� ��������
		// ���� ������� - ��� ���� ����������
		sort(numbers.begin(), numbers.end());
		sort(numberList.begin(), numberList.end());
	}
}