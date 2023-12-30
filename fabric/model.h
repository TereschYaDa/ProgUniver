#ifndef MODELS_H
#define MODELS_H

#include <iostream>

#define MAX_LEN 5

class People {
	protected:
	std::string firstName, lastName, surname, birthDay;
	int state;

	public:
	virtual void create(std::string firstName, std::string lastName, std::string surname, std::string birthDay) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->surname = surname;
		this->birthDay = birthDay;
	}

	int getState() const {return state;}
	virtual void print() = 0;
	virtual void change() = 0;
};

class Student : public People {
	protected:
	int marks[MAX_LEN];

	public:
	Student() {
		state = 0;
		for (int i = 0; i < MAX_LEN; i++)
			marks[i] = 0;
	}
	void markSet(int index, int value) {marks[index] = value;}
	int getMark(int index) {return marks[index];}

	void print() {
		std::cout << "Student \n"
			<< lastName << " " << firstName << " " << surname << " "
			<< birthDay << " \n"
			<< "Marks: ";
		for (int i = 0; i < MAX_LEN; i++)
			std::cout << " " << marks[i];
		std::cout << "\n";
	}
	void change() {
		std::cout << "Choose a student's item you would like to edit:\n"
			<< "1 - First Name\n"
			<< "2 - Last Name\n"
			<< "3 - Surname\n"
			<< "4 - Birth Date\n"
			<< "5 - Marks\n";
		int choose = 0;
		while (choose < 1 || choose > 5) {
			std::cin >> choose;
		}
		switch (choose) {
		case 1:
			std::cout << "Enter new first name: \n";
			std::cin >> firstName;
			break;
		case 2:
			std::cout << "Enter new last name: \n";
			std::cin >> lastName;
			break;
		case 3:
			std::cout << "Enter new surname: \n";
			std::cin >> surname;
			break;
		case 4:
			std::cout << "Enter new birth date: \n";
			std::cin >> birthDay;
			break;
		}
	}
};

class Teacher : public People {
	public:
	Teacher() {state = 1;}
	void print() {
		std::cout << "Teacher \n"
			<< lastName << " " << firstName << " " << surname << " "
			<< birthDay << "\n";
	}
	void change() {
		std::cout << "Choose a teacher's item you would like to edit:\n"
			<< "1 - First Name\n"
			<< "2 - Last Name\n"
			<< "3 - Surname\n"
			<< "4 - Birth Date\n";
		int choose = 0;
		while (choose < 1 || choose > 4) {
			std::cin >> choose;
		}
		switch (choose) {
		case 1:
			std::cout << "Enter new first name: \n";
			std::cin >> firstName;
			break;
		case 2:
			std::cout << "Enter new last name: \n";
			std::cin >> lastName;
			break;
		case 3:
			std::cout << "Enter new surname: \n";
			std::cin >> surname;
			break;
		case 4:
			std::cout << "Enter new birth date: \n";
			std::cin >> birthDay;
			break;
		}
	}
};

class Builder {
	public:
	void inputMarks(Student* person) {
		int value;
		for (int index = 0; index < MAX_LEN; index++) {
			index ? std::cout << "\t\t\t" << index + 1 << ": "
				: std::cout << index + 1 << ": ";
			std::cin >> value;
			person->markSet(index, value);
		}
	}
};

class Fabric {
	public:
	People* create(std::string firstName, std::string lastName,
		std::string surname, std::string birthDay, int type) {
		People* obj = nullptr;
		switch (type) {
		case 0:
			obj = new Student;
			obj->create(firstName, lastName, surname, birthDay);
			break;
		case 1:
			obj = new Teacher;
			obj->create(firstName, lastName, surname, birthDay);
			break;
		}
		return obj;
	}
};
#endif // MODELS_H