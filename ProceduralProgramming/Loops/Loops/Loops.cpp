#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // ���� while - ����������, ���� ����� �������
    int i = 0;
    while (i < 5) {
        cout << "while: " << i << endl;
        i++; // �������� i
    }

    // ���� do-while - ���������� ���� � ���� ���, ����� ���� ����� �����
    int j = 0;
    do {
        cout << "do-while: " << j << endl;
        j++;
    } while (j < 5);

    // ���� for - ������ �����������, ����� �� ��������� �����
    for (int k = 0; k < 5; k++) {
        cout << "for: " << k << endl;
    }

    // ����������� ����
    while (true) {
        cout << "�� ����������� ����" << endl;
    }
}
