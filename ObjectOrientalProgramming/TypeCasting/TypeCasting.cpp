#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

#include "Animal.h"
#include "ZooWorker.h"

using namespace std;

struct Point {
	int x, y;
};

class Book {
private:
	string title;
	string author;
public:
	Book(const string& title, const string& author) : title(title), author(author) {}
	string getTitle() const { return title; }
	string getAuthor() const { return author; }
};

class Base { };
class Derived : public Base {};

class BasePolymorphic { virtual void foo() {} };
class DerivedPolymorphic : public BasePolymorphic {};

template<typename T>
class MyTemplate {
private:
		T value;
public:
	MyTemplate(T val) : value(val) {}
	T getValue() const { return value; }
};

void printAndChange(const int* ptr) {
	int* modifiable = const_cast<int*>(ptr);
	*modifiable = 42;
	std::cout << *modifiable << "\n";
}

int main()
{
    #ifdef _WIN32
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
    #endif

    {
		cout << "typeid � ���������� ������" << '\n';
		int a = 10;
		cout << "��'� ���� ����� �: " << typeid(a).name() << '\n';
		cout << "��'� ���� � ����� (a + 5.5): " << typeid(a + 5.5).name() << '\n';
		float* f = new float(3.14f);
		cout << "��'� ���� ��������� f: " << typeid(f).name() << '\n';
		cout << "��'� ����, �� ���� ����� f: " << typeid(*f).name() << '\n';
		delete f;
		Point p1 = { 1, 2 };
		cout << "��'� ���� ����� p1 (��������� Point): " << typeid(p1).name() << '\n';
		Book book("�������� ��", "��� �����-��������");
		cout << "��'� ���� ����� book (���� Book): " << typeid(book).name() << '\n';
    }

	{
		cout << "\ntypeid � ����������� ������ (�, �� ������ �������� �������)" << '\n';
		BasePolymorphic* basePtr = new BasePolymorphic();
		DerivedPolymorphic* derivedPtr = new DerivedPolymorphic();
		BasePolymorphic* polymorphicPtr = derivedPtr;
		cout << "��'� ����, �� ���� ����� basePtr: " << typeid(*basePtr).name() << '\n';
		cout << "��'� ����, �� ���� ����� derivedPtr: " << typeid(*derivedPtr).name() << '\n';
		// ��� polymorphicPtr ����� �� DerivedPolymorphic, ���� typeid ������� DerivedPolymorphic
		cout << "��'� ����, �� ���� ����� polymorphicPtr: " << typeid(*polymorphicPtr).name() << '\n';
		delete basePtr;
		delete derivedPtr;
	}

	{
		cout << "\ntypeid � �� ����������� ������ (�, �� �� ������ ���������� �������" << '\n';
		Base* basePtr = new Base();
		Derived* derivedPtr = new Derived();
		Base* polymorphicPtr = derivedPtr;
		cout << "��'� ����, �� ���� ����� basePtr: " << typeid(*basePtr).name() << '\n';
		cout << "��'� ����, �� ���� ����� derivedPtr: " << typeid(*derivedPtr).name() << '\n';
		// ��� polymorphicPtr ����� �� Derived, ��� typeid ������� Base, ������� Base �� � ����������
		cout << "��'� ����, �� ���� ����� polymorphicPtr: " << typeid(*polymorphicPtr).name() << '\n';
		delete basePtr;
		delete derivedPtr;
	}

	{
		cout << "\ntypeid � ��������� �����\n";
		MyTemplate<int> intTemplate(42);
		MyTemplate<double> doubleTemplate(3.14);
		cout << "��'� ���� intTemplate: " << typeid(intTemplate).name() << '\n';
		cout << "��'� ���� doubleTemplate: " << typeid(doubleTemplate).name() << '\n';
	}

	{
		cout << "\n��������� ������ � ��������\n";
		Animal* monkey = new Monkey("��������", 5);
		Animal* elephant = new Elephant("�������", 10);
		ZooWorker worker("����", 1500.0);
		worker.feedAnimal(*monkey);
		worker.feedAnimal(*elephant);
		delete monkey;
		delete elephant;
	}

	{
		cout << "\nstatic_cast\n";
		
		// ������������ ��������� ����
		int i = 42;
		double d = static_cast<double>(i); // i -> 42.0

		Monkey monkey("������", 5);

		Animal* animalPtr = static_cast<Animal*>(&monkey); // upcast: ��������
		animalPtr->makeSound();

		// Downcast � ���������, ��� ���������� ��� �������� (typeid)
		Monkey* monkeyPtr = static_cast<Monkey*>(animalPtr);
		monkeyPtr->makeSound();

		// ������������ ���������
		void* ptr = new int(100);

		int* iptr = static_cast<int*>(ptr);
		std::cout << *iptr << "\n"; // 100

		delete iptr;
	}

	{
		cout << "\nstatic_cast �� C-style cast\n";

		int i = 10;
		int* p = &i;
		double* d = (double*)p; // C-style ���������, ��� �� undefined behavior

		// double* d2 = static_cast<double*>(p); // �������: static_cast ���������
	}

	{
		cout << "\ndynamic_cast\n";

		Animal* animalPtr1 = new Monkey("���", 7);

		Monkey* monkeyPtr1 = dynamic_cast<Monkey*>(animalPtr1); // ��, a ����� �� Dog
		if (monkeyPtr1) {
			monkeyPtr1->makeSound(); // �-�-�!
		}

		Animal* animalPtr2 = new Elephant("��� ���", 10);
		Monkey* monkeyPtr2 = dynamic_cast<Monkey*>(animalPtr2); // �� ��, ������� nullptr
		if (!monkeyPtr2) {
			cout << "animalPtr2 �� Monkey\n";
		}

		delete animalPtr1, animalPtr2;

		Monkey monkey("����", 3);
		Animal& a = monkey;

		try {
			Elephant& m = dynamic_cast<Elephant&>(a);
			m.makeSound();
		}
		catch (const std::bad_cast& e) {
			std::cout << "�� Elephant: " << e.what() << "\n";
		}
	}

	{
		cout << "\nconst_cast\n";

		int x = 10;
		printAndChange(&x); // ������ 42

		const int y = 20;
		printAndChange(&y); // ����������, ���������� undefined behavior
	}

	{
		cout << "\nreinterpret_cast\n";
		int a = 65; // ASCII ��� ��� 'A'
		char* c = reinterpret_cast<char*>(&a); // ������������ int � char*
		cout << "reinterpret_cast: " << *c << "\n"; // ������ 'A' ��� ����� ������ � ��������� �� �������
	}
}