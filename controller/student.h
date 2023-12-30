#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

class student {
	std::string firstName, lastName;
	int* ratings;
	int n;
	std::string id;

public:
	student() {
		firstName = "Ivan";
		lastName = "Ivanov";
		srand(time(NULL));
		n = 10;
		ratings = new int[n];
		for (int i = 0; i < n; i++)
			ratings[i] = rand() % 5 + 1;
		generateID();
	}

	student(std::string firstName, std::string lastName, int k) {
		this->firstName = firstName;
		this->lastName = lastName;
		srand(time(NULL));
		n = k;
		ratings = new int[n];
		for (int i = 0; i < n; i++)
			ratings[i] = rand() % 5 + 1;
		generateID();
	}

	std::string getFirstName() {return firstName;}

	std::string getLastName() {return lastName;}

	int* getRatings() {return ratings;}

	int getN() {return n;}

	std::string getID() {return id;} 

	void print() {
		std::cout << "ID: " << id << ", " << lastName << " " << firstName << "; rate: ";
		for (int j = 0; j < n; j++)
			std::cout << ratings[j] << " ";
		std::cout << std::endl;
	}

	double averageRatings() {
		double sum = 0;
		for (int i = 0; i < n; i++)
			sum += ratings[i];
		return sum / n;
	}

private:
	void generateID() {
		time_t now = time(0);
		id = std::to_string(now);
	}
};