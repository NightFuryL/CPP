#include <iostream>
#include <Windows.h>

using namespace std;

int main(int argc, char* args[])
{
    SetConsoleOutputCP(1251);
    cout << "������ �������� (����� ��������): " << args[0] << endl;
    if (argc > 1)
    {
        for (int i = 0; i < argc; i++) {
            cout << "�������� " << i + 1 << ": " << args[i] << endl;
        }
    }
}
