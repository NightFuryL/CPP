#include <iostream>
// #include <windows.h> ����� �� Windows

using namespace std;

// ��������� ��� ���������� ���������� ��� ����.
// ���������� ������ � ������ ���������� ���.
struct date {
    int day;            // ����
    int month;          // ̳����
    int year;           // г�
    int weekday;        // ����� ��� �����
    char mon_name[15];  // ����� �����
};

struct person
{
    char name[50];      // ��'�, �������, �� �������.
    char address[50];   // ������� ������.
    int zipcode[2];     // �������� ������.
    int s_number[2];    // ��� ���.������������.
    int salary[4];      // ��������.
    date birthdate;     // ���� ����������.
    date hiredate;      // ���� ������� �� ������.
};

struct point {
    int x;
    int y;
};

void PrintDate(const date& d)
{
    cout << d.day << "." << d.month << "." << d.year
         << ", " << d.weekday << ", " << d.mon_name << '\n';
}

int main()
{
    // ҳ���� �� Windows
    // SetConsoleOutputCP(1251);
    // SetConsoleCP(1251);

    struct Test { // 8 ���� - �����������
        char c; // 1 ����
        int i;  // 4 �����
    };

    Test d = { '#', 77 };
    cout << "����� ���������: " << sizeof(Test) << "\n" << "����� ��'���� ���������: " << sizeof(d) << '\n';

    int value = 10;
    bool boolean = false;
    bool* ptr = &boolean;
    int arr[10];

    cout << "����� ����� � ����� int: " << sizeof(value) << '\n';
    cout << "����� ����� � ����� bool: " << sizeof(boolean) << '\n';
    cout << "����� ���������: " << sizeof(ptr) << '\n';
    cout << "����� ������ ���� int �� 10 ��������: " << sizeof(arr) << '\n';

    point pa = { 12, 31 };

    // ����������� ������ ��'���� ����� ��'�����
    // ³��������� ��������� ����� ��ﳿ
    point pb = pa;

    point p = { 10, 11 };

    cout << sizeof(p) << endl;

    // ������ �� �������� ���������
    cout << p.x << '\n';
    // ��������� ������ ��'���� ���������
    point* pp = &p;
    // ������ �� �������� ��������� ����� ��������
    cout << pp->x << '\n';

    // ��������� �� �����������
    date myBirthday = { 20, 7, 1981, 1, "�������" };

    // ���� ��������
    myBirthday.year = 1988;

    // ��������� �����
    cout << "� ��������� " << myBirthday.day << " " << myBirthday.mon_name << " " << myBirthday.year << ".\n";

    cout << sizeof(myBirthday) << endl;

    PrintDate(myBirthday);
}