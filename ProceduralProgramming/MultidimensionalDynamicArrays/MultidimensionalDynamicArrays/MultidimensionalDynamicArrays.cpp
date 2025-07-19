#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    srand(time(NULL));

    // ��������� ���������� ����������� ������
    int size_x = 3, size_y = 5;

    int** arr_3x5 = new int* [size_x]; // �������� ���'�� ��� ������ ���������

    for (int i = 0; i < size_x; i++) 
    {
        arr_3x5[i] = new int[size_y]; // �������� ���'�� ��� ����������� ������
        for (int j = 0; j < size_y; j++) 
        {
            arr_3x5[i][j] = rand() % 10; // ����������� ���������� ������
            cout << arr_3x5[i][j] << " "; // ���� �� �����
        }
        cout << endl;
    }

    // ������� ���'���
    for (int i = 0; i < size_x; i++)
    {
        delete[] arr_3x5[i];
    }
    delete[] arr_3x5;

    cout << endl << endl;

    // ��������� ��������� (�������) ������
    int size_A;
    cout << "������ ������� ������: " << endl;
    cin >> size_A;

    int** A = new int* [size_A]; // ����� ��������� �� ������
    int* sizes = new int[size_A]; // ����� ������ ����� ������

    for (int i = 0; i < size_A; i++) {
        int temp_size;
        cout << "������ ����� " << i << " ������: ";
        cin >> temp_size;
        A[i] = new int[temp_size]; // �������� ���'��� �� �����
        sizes[i] = temp_size;   // �������� ����� ������
        for (int j = 0; j < temp_size; j++) {
            // ���������� ����� ����������
            int temp_value;
            cout << "������  �������� " << j << " �������� " << i << " ������: ";
            cin >> temp_value;
            A[i][j] = temp_value;
        }
    }

    // �������� ������
    for (int i = 0; i < size_A; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    // ������� ���'��
    for (int i = 0; i < size_A; i++) {
        // �������� ����� �������� �����
        delete[] A[i];
    }
    delete[] A; // �������� ����� ���������

    cout << endl << endl;

    // ���������� ��������� �����
    
    cout << endl << "���������� ��������� �����" << endl;

    int size_i= 4, size_j = 2, size_z = 3;

    // �������� �� ����� ��������� �� �������� :)
    int*** arr_4x2x3 = new int** [size_i]; 

    for (int i = 0; i < size_i; i++) 
    {
        arr_4x2x3[i] = new int* [size_j]; // ����� ���������
        for (int j = 0; j < size_j; j++) 
        {
            arr_4x2x3[i][j] = new int[size_z]; // ����� �����
            // ���������� �� ��������
            for (int z = 0; z < size_z; z++) 
            {
                arr_4x2x3[i][j][z] = rand() % 10;
                cout << arr_4x2x3[i][j][z] << " ";
            }
            cout << endl;
        }
        cout << "--------" << endl;
    }
    
    // ��������� ���'��
    for (int i = 0; i < size_i; i++) {
        for (int j = 0; j < size_j; j++) {
            delete[] arr_4x2x3[i][j];
        }
        delete[] arr_4x2x3[i];
    }
    delete[] arr_4x2x3;

}
