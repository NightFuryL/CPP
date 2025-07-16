#pragma once
#include <iostream>
#include <string>

class Animal
{
private:
	std::string name;
	int age;
public:
	Animal(const std::string& name, int age) : name(name), age(age) {}
	
	std::string getName() const { return name; }
	int getAge() const { return age; }
	
	void setName(const std::string& newName) { name = newName; }
	void setAge(int newAge) { age = newAge; }
	
	virtual void makeSound() const = 0; // ����� ��������� �������
	virtual ~Animal() {} // ³��������� ����������
};

class Monkey : public Animal
{
	public:
	Monkey(const std::string& name, int age) : Animal(name, age) {}
	void makeSound() const override {
		std::cout << getName() << " ����: �-�-�!" << std::endl;
	}
};

class Elephant : public Animal
{
	public:
	Elephant(const std::string& name, int age) : Animal(name, age) {}
	void makeSound() const override {
		std::cout << getName() << " ����: ���-��!" << std::endl;
	}
};

