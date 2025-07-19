#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#endif

using namespace std;

int main()
{
#ifdef _WIN32
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
#endif

	{
		// auto_ptr
		auto_ptr<int> p1(new int(10));
		cout << "auto_ptr: " << *p1 << endl;
		auto_ptr<int> p2 = p1; // p1 == nullptr
		cout << p1.get() << endl;
	}

	{
		// unique_ptr
		unique_ptr<int> p1(new int(20));
		cout << "unique_ptr: " << *p1 << endl;
		// unique_ptr<int> p2 = p1; // Error: unique_ptr �� ������� ���������
		unique_ptr<int> p2 = move(p1); // p1 == nullptr - ��������� ����������
		cout << p1.get() << endl; // nullptr
		cout << *p2 << endl; // 20 - p2 ����� ����䳺 ��������

		// release() - ������ �������� ��������, ��� �� ������� ����
		unique_ptr<int> p3(p2.release()); // p2 ���� ������, p3 ����䳺 ���
	}

	{
		// shared_ptr
		shared_ptr<int> p1(new int(30));
		shared_ptr<int> p2 = p1; // p2 �� p1 ����� ���� � ��� �� ������
		cout << *p1 << endl;
		cout << *p2 << endl;
		cout << p1.get() << endl; // ������ �������
		cout << p2.get() << endl; // �������� ������ �������
		cout << "Use count: " << p1.use_count() << endl; // 2 ��������� ����� ������
	}

	{
		// weak_ptr
		shared_ptr<int> p1(new int(40));
		weak_ptr<int> wp1 = p1; // weak_ptr �� ����䳺 ��������, ��� ���� �������� ������

		cout << *p1 << '\n';
		cout << p1.use_count() << '\n'; // 1, ������� p1 � ������ ��������� �������

		if (auto locked = wp1.lock()) { // locked - �� shared_ptr
			cout << *locked << "\n"; // ������ �� ��������
		}
		else {
			cout << "��'��� ��� ��������\n";
		}
	}
}