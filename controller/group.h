#include "student.h"
#include <iostream>
#include <string>
#include <vector>

class Group {
	int n = 2;
	student* students;

public:
	Group() {
		std::cout << "Group size: " << n << ":\n";
		students = new student[n];
		for (int i = 0; i < n; i++) {
			std::string firstName, lastName;
			std::cin >> firstName >> lastName;
			students[i] = (student(firstName, lastName, 5));
		}
	}
	void print() {
		for (int i = 0; i < n; i++) {
			student currentStudent = students[i];
			std::cout << i + 1 << ". ";
			currentStudent.print();
		}
	}
	void addStudentRand() {
		std::string firstName, lastName;
		std::cin >> firstName >> lastName;
		student* newst = new student[n + 1];
		for (int i = 0; i < n; i++)
			newst[i] = students[i];
		newst[n] = student(firstName, lastName, 5);
		n++;
		students = newst;
	}
	void deleteStudent(int k) {
		student* newst = new student[n - 1];
		for (int i = 0, j = 0; i < n; i++, j++) {
			if (i == (k - 1))
				i++;
			if (i < n)
				newst[j] = students[i];
		}
		n--;
		students = newst;
	}
	void sort() {
		student* newst = new student[n];
		for (int i = 0; i < n; i++)
			newst[i] = students[i];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n - 1; j++)
				if (newst[j].getFirstName() > newst[j + 1].getLastName()) {
					student copy = newst[j];
					newst[j] = newst[j + 1];
					newst[j + 1] = copy;
				}
		for (int i = 0; i < n; i++) {
			student currentStudent = newst[i];
			std::cout << i + 1 << ": ";
			currentStudent.print();
		}
	}
	void theBestTheWorth() {
		student best, bad;
		float bestRating = 0;
		float badRating = 6;
		for (int i = 0; i < n; i++) {
			student currentStudent = students[i];
			double current_ratings = currentStudent.averageRatings();
			if (current_ratings >= bestRating) {
				bestRating = current_ratings;
				best = currentStudent;
			}
			if (current_ratings <= badRating) {
				badRating = current_ratings;
				bad = currentStudent;
			}
		}
		std::cout << bestRating << " - ";
		best.print();
		std::cout << badRating << " - ";
		bad.print();
	}
	void displayStudents() {
		int m = 1;
		for (int i = 0; i < n; i++) {
			student currentStudent = students[i];
			if (currentStudent.averageRatings() < 2.5) {
				std::cout << m << ": ";
				currentStudent.print();
				m++;
			}
		}
	}
};