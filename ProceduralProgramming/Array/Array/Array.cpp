#include <iostream>
#include <Windows.h>
#include <cstdlib> // rand(), srand()
#include <ctime>   // time()

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);

    // ���������� ������
    // ��� �������������[�������_��������]
    int intArr[5];          // ����� �� ���� �������� 5 ����� �����
    char charArr[4];        // ����� �� ���� �������� 4 �������
    double doubleArr[10];   // ����� �� ���� �������� 10 ������� �����

    intArr[0] = 10;     // �������� � ������ ������� ������ ����� 10
    //cout << intArr[0];  // �������� �� ����� ������ ������� ������

    charArr[1] = 'A';   // �������� � ������ ������� ������ ������ �

    int arr[3];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    
    //arr[3] = 4; // ������� ��� ����� ������ (����� Debug). ���� ������� � ����� Release!
    cout << arr[3] << endl; // ���� �������� �������� - ������������� ���'��

    const int size = 3; // ��������� ��������� ��� ������ ������
    double br[size];    // ��������� ����� �� 3 ��������

    const int arr_size = 3; // ��������� ����� ������
    int ints[arr_size] = { 2, 10, -1 }; // ��������� ����� �� ������ �������� ��������
    bool booleans[] = { true, false, true }; // ��������� ������� ������� �������� ���

    int floats[5] = { 1, 3, 4 }; // �������� ��� ����������� ������ ������ �����
    
    // ����������� �� �������� �����    
    const int size_arr = 5;
    int numbers[size_arr];

    for (int i = 0; i < size_arr; ++i) {
        numbers[i] = i + 1;
    }

    // ϳ�������� ����
    const int s = 5;
    int nums[s] = { 10, -11, 43, 0, -10 };
    int sum = 0;

    for (int i = 0; i < s; i++) {
        sum += nums[i];
    }
    cout << endl;

    // ������� �� ��������� foreach
    for (auto item : nums)
    {
        cout << item << " ";
    }

    // ��������� ����������� �����
    // ��������������� ��� ������� "seed" (����������� �����) ���������� rand(). 
    // ��� ����� rand() ������ ����������� �������� ����������� ����� ��� ������� ������� ��������.
    srand(time(nullptr));

    // rand ������ ��������� ����� ���� int � ������� �� 0 �� RAND_MAX
    // RAND_MAX � �� ���������, �������� 32767 (��� ���� ���� ����� ������� �� ��������� ����������).
    int r = rand();

    cout << r << endl;

    // ��������� ����������� ����� � �������
    srand(time(nullptr));

    r = rand() % 100; // ��������� ����� �� 0 �� 99;

    int r2 = rand() % 100 + 1; // ��������� ����� �� 1 �� 100;

    int min = 10;
    int max = 200;
    int r3 = rand() % (max - min + 1) + min; // ��������� ����� �� min �� max

    // ���������� �����
    int matrix[3][4] = { 
        {1,2,3,4}, 
        {5,6,7,8}, 
        {9,10,11,12} 
    };

    // ������ �� ��������
    matrix[0][1] = -2;
    cout << matrix[2][3] << endl;

    // ������� ����������� ������
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 4; j++) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // ����������� ������
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 4; j++) 
        {
            matrix[i][j] = rand() % 10;
        }
    }
}
