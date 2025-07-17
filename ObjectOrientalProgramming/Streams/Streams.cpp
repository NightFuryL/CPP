#include <iostream>
#include <fstream>

using namespace std;

class Point {
private:
	int x, y;
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}	

	friend ostream& operator<<(ostream& os, const Point& p) {
		os << "Point(" << p.x << ", " << p.y << ")";
		return os;
	}
	friend istream& operator>>(istream& is, Point& p) {
		is >> p.x >> p.y;
		return is;
	}
};

int main()
{
    {
		// ������������ ������ �������� �� ���������

		cout << "Hello, World!" << endl; // ��������� �� �������
		string input;
		cin >> input; // �������� � ������
		cerr << "Error: " << input << endl; // ��������� ������� �� �������
		clog << "Log: " << input << endl; // ��������� ������� �� �������
		
		Point p1(3, 4);
		cout << "Point p1: " << p1 << endl; // ��������� ��'���� Point
		Point p2;
		cout << "Enter coordinates for Point p2 (x y): ";
		cin >> p2; // �������� ��'���� Point
    }

	{
		// ��������� ������ �� ��'�������� � ������
		// ����� �������� �����: 
		// ios_base::in - �������� ��� �������
		// ios_base::out - �������� ��� ������
		// ios_base::app - ��������� �� ���� �����
		fstream file("example.txt", ios_base::app);
		if (!file) {
			cerr << "Error opening file!" << endl;
			return 1;
		}
		file.close(); // �������� �����
	}

	{
		fstream fs;

		fs.open("example.txt", ios_base::in | ios_base::out | ios_base::app);

		// �������� � ������

		fs.close(); // �������� �����
	}

	{
		ifstream is("example.txt");

		if (!is) {
			cerr << "Error opening file for reading!" << endl;
			return 1;
		}

		char* line = new char[101];
		is.read(line, 100); // ������� �� 100 ������� � �����
		int readCount = is.gcount(); // ������ ������� ���������
		line[readCount] = '\0'; // �������� ������� '\0' ���� ���������� �����
		cout << "Read line: " << line << endl;
		delete[] line; // ��������� ���'��
	}

	{
		ofstream os("output.txt");

		if(!os) {
			cerr << "Error opening file for writing!" << endl;
			return 1;
		}

		os << "Hello, file!" << endl; // ����� ����� � ����

		Point p(5, 10);
		os << p << endl; // ����� ��'���� Point � ����

		os.write("This is a test.", 14); // ����� 14 ������� � ����
	}
}