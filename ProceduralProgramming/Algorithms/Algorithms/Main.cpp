#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	srand(time(NULL));

	const int size = 5;
	int arr[size];
	int min = -10, max = 10;

	for (int i = 0; i < size; i++) {
		arr[i] = rand() % (max - min + 1) + min;
	}

	// ���������� �������
	cout << "����� �� ����������: ";
	for (int item : arr) {
		cout << item << " ";
	}
	cout << endl;

	int minIndex; // ����� ��� ���������� ������� ����������� ��������
	// �������� ���� ����������
	for (int i = 0; i < size; i++) {
		// ������� �������� ���������� �������
		minIndex = i;

		// �������� ���� ��� ������ ���������� ��������
		for (int j = i; j < size; j++) {
			if (arr[minIndex] > arr[j]) {
				minIndex = j;
			}
		}
		// ���� ��������� ������� �� ������� ��������� - ������ ������.
		if (minIndex != i) {
			int temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
		}
	}

	cout << "����� ���� ����������: ";
	for (int item : arr) {
		cout << item << " ";
	}
	cout << endl;

	// �������������� �����
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % (max - min + 1) + min;
	}

	// ����������� ����������
	cout << endl;
	cout << "����� �� ����������: ";
	for (int item : arr) {
		cout << item << " ";
	}
	cout << endl;

	// ������� ����, i - ����� �������
	for (int i = 0; i < size; i++) {
		// �������� ���� - ����� �� ���������� �� i, �� �� i ��� ����������
		for (int j = size - 1; j > i; j--) {
			// ��������� ����� �������� �� ������ �� ������ � ��� �������
			if (arr[j - 1] > arr[j]) {
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}

	cout << "����� ���� ����������: ";
	for (int item : arr) {
		cout << item << " ";
	}
	cout << endl;

	// �������������� �����
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % (max - min + 1) + min;
	}

	// ���������� ���������
	cout << endl;
	cout << "����� �� ����������: ";
	for (int item : arr) {
		cout << item << " ";
	}
	cout << endl;

	// ������� ����, i - ����� �������
	for (int i = 1; i < size; i++) {
		int temp = arr[i]; // ���������� ��������� ��������
		int j = i - 1;

		// ���� ��������, �� ����� �� temp ������
		while (j >= 0 && arr[j] > temp) {
			arr[j + 1] = arr[j];
			j--;
		}

		// ������� temp �� ��������� ����
		arr[j + 1] = temp;
	}

	cout << "����� ���� ����������: ";
	for (int item : arr) {
		cout << item << " ";
	}
	cout << endl;

	cout << endl;

	int searchArr[size] = { 2, -1, 6, 5, 0 };

	cout << "����� ��� ������: ";
	for (int item : searchArr) {
		cout << item << " ";
	}
	cout << endl;

	// ˳����� �����
	int value;
	cout << "������ �������� ��� ������: ";
	cin >> value;

	int index = -1;
	for (int i = 0; i < size; i++) {
		if (searchArr[i] == value) {
			index = i;
			cout << "�������� " << value << " �������� �� �������� " << index << ".";
			break;
		}
	}
	if (index == -1) {
		cout << "�������� " << value << " �� ��������.";
	}

	cout << endl;

	// �������� �����
	cout << "������ �������� ��� ������: ";
	cin >> value;

	// ������� �����
	for (int i = 1; i < size; i++) {
		int temp = searchArr[i]; // ���������� ��������� ��������
		int j = i - 1;

		// ���� ��������, �� ����� �� temp ������
		while (j >= 0 && searchArr[j] > temp) {
			searchArr[j + 1] = searchArr[j];
			j--;
		}

		// ������� temp �� ��������� ����
		searchArr[j + 1] = temp;
	}

	int left = 0;
	int right = size - 1;
	index = -1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (searchArr[mid] == value) {
			index = mid; // ������� ��������, �������� ������
			break;
		}
		else if (searchArr[mid] < value) {
			left = mid + 1; // ������� ������� � ����� �������
		}
		else {
			right = mid - 1; // ������� ������� � ��� �������
		}
	}

	if (index == -1) {
		cout << "�������� " << value << " �� ��������.";
	}
	else {
		cout << "�������� " << value << " �������� �� �������� " << index << ".";
	}
}