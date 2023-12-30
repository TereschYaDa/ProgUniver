#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "group.h"
#include <iostream>

class controller {
	Group currentGroup;

public:
	controller() {}
	void execute() {
		int run = 1;
		while (run) {
			menu();
			int var = 0;
			while (var < 1 || var > 6) {
				std::cout << "Input variant: ";
				std::cin >> var;
			}
			switch (var) {
			case 6:
				run = 0;
				break;
			case 1:
				std::cout << "Add student:\n";
				currentGroup.addStRand();
				break;
			case 2:
				currentGroup.print();
				std::cout << "input index of student:\n";
				int n;
				std::cin >> n;
				currentGroup.deleteSt(n);
				break;
			case 3:
				std::cout << "Sort student:\n";
				currentGroup.sort();
				break;
			case 4:
				std::cout << "Top of students:\n";
				currentGroup.theBestTheWorth();
				break;
			case 5:
				std::cout << "Display students:\n";
				currentGroup.displayStudents();
				break;
			}
		}
	}

	void menu() {
		std::cout << "Commands: \n"
			<< "1. Add student\n"
			<< "2. Delete student by index\n"
			<< "3. Sort student\n"
			<< "4. Top of student\n"
			<< "5. Display students\n"
			<< "6. Exit\n";
	}
};
#endif //CONTROLLER_H