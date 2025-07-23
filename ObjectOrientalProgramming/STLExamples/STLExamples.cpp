#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

// ���������
bool isEven(int n);

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
		cout << "\nVector size: " << numbers.size() << endl;
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
		cout << endl;

		numbers.pop_back(); // ��������� ���������� ��������

		numbers.erase(numbers.begin() + 1); // ��������� �������� �� ��������

		numbers.clear(); // �������� �������

		// ��������, �� ������ �������
		if (numbers.empty()) {
			cout << "Vector is empty after clear." << endl;
		}
		else {
			cout << "Vector is not empty." << endl;
		}
	}

	{
		// ������� ������������ ���������
		vector<int> numbers = { 13, 2, 23, -4, 8 };
		list<int> numberList = { 13, 2, 23, -4, 8 };

		// ����� � ������ �� ������
		// find ����������� ��������� ��� ������� �� ��������
		// ���� ������� � ��� ���� ����������
		auto resultVect = find(numbers.begin(), numbers.end(), 23);
		auto resultList = find(numberList.begin(), numberList.end(), 23);

		cout << "Found in vector: " << (resultVect != numbers.end() ? "Yes" : "No") << endl;
		cout << "Found in list: " << (resultList != numberList.end() ? "Yes" : "No") << endl;
	}

	{
		// ������������ ����� list
		list<string> names = { "Alice", "Bob", "Charlie" };

		names.push_back("David"); // ��������� �������� � ����� ������
		names.push_front("Eve"); // ��������� �������� �� ������� ������

		names.sort(); // ���������� ������ - ����������� ���������� ����� sort

		cout << "List elements: ";
		// ����� ��������������� range-based for loop ��� ��������� �������� ������
		for (const auto& name : names) {
			cout << name << " ";
		}
		cout << endl;
	}

	{
		// ������� ������������ map
		map<string, string> phoneBook;
		phoneBook["Alice"] = "123-456-7890";
		phoneBook["Bob"] = "987-654-3210";
		phoneBook["Charlie"] = "555-555-5555";
		phoneBook["David"] = "111-222-3333";

		phoneBook["Alice"] = "111-111-1111"; // ��������� ������ �������� ��� Alice

		cout << phoneBook["Alice"] << endl; // ��������� ������ �������� Alice

		// ��������� ������ �������� ��� Donald, ���� �� ���� � ��������� ����
		// �� �������� ����� ����� � ������� ���������
		cout << phoneBook["Donald"] << endl;

		phoneBook.erase("Charlie"); // ��������� ������ ��� Charlie
	}

	{
		// multimap � ����� ������� �� ���� ����
		multimap<string, string> multiMap;
		multiMap.insert({ "apple", "�������" });
		multiMap.insert({ "apple", "��������" }); // �� ��������������

		cout << "\nmultimap:\n";
		for (const auto& pair : multiMap) {
			cout << pair.first << " � " << pair.second << endl;
		}
	}

	{
		 // ������������ ��������
		struct Desc {
			bool operator()(int a, int b) const {
				return a > b;
			}
		};

		vector<int> numbers = { 5, 2, 8, 1 };
		sort(numbers.begin(), numbers.end(), Desc());

		for (int n : numbers) {
			cout << n << " ";
		}
	}

	{
		// ������������ ��'���� �������
		vector<int> nums = { 1, 2, 3, 4, 5, 6 };
		function<bool(int)> isEven = isEven;
		int evenCount = count_if(nums.begin(), nums.end(), isEven);

		cout << "ʳ������ ������: " << evenCount << endl;
	}

	{
		// ������������ ������-�������
		vector<int> nums = { 3, 7, 1, 9, 5 };
		auto greaterThan5 = [](int x) { return x > 5; };

		int count = count_if(nums.begin(), nums.end(), greaterThan5);
		cout << "����� > 5: " << count << endl;
	}
}

bool isEven(int n) {
	return n % 2 == 0;
}