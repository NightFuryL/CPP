#pragma once
#include <iostream>
#include <string>

#include "Animal.h"

class ZooWorker
{
private:
	double salary;
	std::string name;
public:
	ZooWorker(const std::string& name, double salary) : name(name), salary(salary) {}

	std::string getName() const { return name; }
	double getSalary() const { return salary; }

	void setName(const std::string& newName) { name = newName; }
	void setSalary(double newSalary) { salary = newSalary; }

	void feedAnimal(const Animal& animal) const {
		if(typeid(animal) == typeid(Monkey)) {
			std::cout << 
				"��������� ����������� ���� " << name << 
				" ���� ����� " << animal.getName() << " �������.\n";
		} else if(typeid(animal) == typeid(Elephant)) {
			std::cout 
				<< "��������� ����������� ���� " << name <<
				" ���� ����� " << animal.getName() << " �������� ���������.\n";
		} else {
			std::cout 
				<< "��������� ����������� ���� " << name << 
				" ���� ������� " << animal.getName() << ".\n";
		}
	}
};

