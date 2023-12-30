#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "views.h"
#include <iostream>

class Controller {
	University universe;

public:
	Controller() {}

	void displayMenu() {
		std::cout << "Options: \n"
			<< "[1] Print all \n"
			<< "[2] Add student \n"
			<< "[3] Remove student \n"
			<< "[4] Modify student \n"
			<< "[5] Print all students \n"
			<< "[6] Add teacher \n"
			<< "[7] Dismiss teacher \n"
			<< "[8] Modify teacher \n"
			<< "[9] Print all teachers \n"
			<< "[10] Exit program \n";
	}

	void execute() {
		int choose = 0;
		bool isWorking = true;
		while (isWorking) {
			displayMenu();
			int option = 0;
			while (option < 1 || option > 10) {
				std::cout << "Enter an option: ";
				std::cin >> option;
			}
			switch (option) {
			case 10:
				isWorking = false;
				break;
			case 1:
				universe.printAll();
				break;
			case 2:
				universe.createStudent();
				break;
			case 3:
				std::cout << "Choose a student to remove \n";
				universe.printStudents();
				while (choose < 1 || choose > universe.getStudentCount()) {
					std::cin >> choose;
				}
				universe.deletePerson(choose, 0);
				break;
			case 4:
				std::cout << "Choose a student to modify \n";
				universe.printStudents();
				while (choose < 1 || choose > universe.getStudentCount()) {
					std::cin >> choose;
				}
				universe.changePerson(choose, 0);
				break;
			case 5:
				universe.printStudents();
				break;
			case 6:
				universe.createTeacher();
				break;
			case 7:
				std::cout << "Choose a teacher to dismiss \n";
				universe.printTeachers();
				while (choose < 1 || choose > universe.getTeacherCount()) {
					std::cin >> choose;
				}
				universe.deletePerson(choose, 1);
				break;
			case 8:
				std::cout << "Choose a teacher to modify \n";
				universe.printTeachers();
				while (choose < 1 || choose > universe.getTeacherCount()) {
					std::cin >> choose;
				}
				universe.changePerson(choose, 1);
				break;
			case 9:
				universe.printTeachers();
				break;
			}
		}
	}
};

#endif //CONTROLLER_H