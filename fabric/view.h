#ifndef VIEWS_H
#define VIEWS_H

#include "models.h"
#include <iostream>
#include <string>

enum : int {STUDENT, TEACHER};

class University {
	int count;
	People** people;
	Builder markBuilder;
	Fabric fabric;

	public:
	University() {
		this->count = 1;
		people = new People * [this->count];
		for (int i = 0; i < this->count; i++) {
			int type = -1;
			std::string firstName, lastName, surname, birthDay;
			std::cout << "Enter last name: ";
			std::cin >> lastName;
			std::cout << "Enter first name: ";
			std::cin >> firstName;
			std::cout << "Enter surname: ";
			std::cin >> surname;
			std::cout << "Enter birth date: ";
			std::cin >> birthDay;
			std::cout << "Enter status (0 - student, 1 - teacher): ";
			while (type < 0 || type > 1) {
				std::cin >> type;
				switch (type) {
				case 0:
					std::cout << "You selected the student \n";
					break;
				case 1:
					std::cout << "You selected the teacher \n";
					break;
				default:
					std::cout << "\033[91mYou selected wrong type\033[0m \n";
					std::cout << "Enter status (0 - student, 1 - teacher): ";
					break;
				}
			}
			people[i] = fabric.create(firstName, lastName, surname, birthDay, type);
			if (type == 0) {
				std::cout << "Enter student's marks: ";
				markBuilder.inputMarks((Student*)people[i]);
			}
		}
	}

	int getStudentCount() {
		int localCount = 0;
		for (int i = 0; i < localCount; i++)
			people[i]->getState() == 0 ? localCount++ : NULL;
		return localCount;
	}

	int getTeacherCount() {
		int localCount = 0;
		for (int i = 0; i < localCount; i++)
			people[i]->getState() == 1 ? localCount++ : NULL;
		return localCount;
	}

	void printStudents() {
		int localCount = 1;
		for (int i = 0; i < this->count; i++)
			if (people[i]->getState() == 0) {
				std::cout << localCount << ": ";
				people[i]->print();
				localCount++;
			}
	}

	void printTeachers() {
		int localCount = 1;
		for (int i = 0; i < this->count; i++)
			if (people[i]->getState() == 1) {
				std::cout << localCount << ": ";
				people[i]->print();
				localCount++;
			}
	}

	void printAll() {
		for (int i = 0; i < this->count; i++)
			people[i]->print();
	}

	void createStudent() {
		std::string firstName, lastName, surname, birthDay;
		std::cout << "Enter last name: ";
		std::cin >> lastName;
		std::cout << "Enter first name: ";
		std::cin >> firstName;
		std::cout << "Enter  surname: ";
		std::cin >> surname;
		std::cout << "Enter birth date: ";
		std::cin >> birthDay;
		std::cout << "Enter student's marks: ";
		People* newStudent =
			fabric.create(firstName, lastName, surname, birthDay, STUDENT);
		markBuilder.inputMarks((Student*)newStudent);
		People** copyPeople = new People * [this->count + 1];
		for (int i = 0; i < this->count; i++)
			copyPeople[i] = people[i];
		copyPeople[this->count] = newStudent;
		this->count++;
		people = copyPeople;
	}

	void createTeacher() {
		std::string firstName, lastName, surname, birthDay;
		std::cout << "Enter last name: ";
		std::cin >> lastName;
		std::cout << "Enter first name: ";
		std::cin >> firstName;
		std::cout << "Enter surname: ";
		std::cin >> surname;
		std::cout << "Enter birth date: ";
		std::cin >> birthDay;
		People* newTeacher =
			fabric.create(firstName, lastName, surname, birthDay, TEACHER);
		People** copyPeople = new People * [this->count + 1];
		for (int i = 0; i < this->count; i++)
			copyPeople[i] = people[i];
		copyPeople[this->count] = newTeacher;
		this->count++;
		people = copyPeople;
	}

	void deletePerson(int index, int type) {
		int localCount1 = 0, localCount2 = 0;
		People** copyPeople = new People * [this->count - 1];
		for (int i = 0; i < this->count; i++) {
			People* current = people[i];
			current->getState() == type ? localCount1++ : NULL;
			localCount1 == index ? i++ : NULL;
			if (i < this->count)
				copyPeople[localCount2] = people[i];
			localCount2++;
		}
		this->count--;
		people = copyPeople;
	}

	void changePerson(int index, int type) {
		int localCount = 0;
		for (int i = 0; i < this->count; i++) {
			People* current = people[i];
			current->getState() == type ? localCount++ : NULL;
			if (localCount == index && i < this->count) {
				current->change();
				break;
			}
		}
	}
};

#endif // VIEWS_H
