#ifndef DECORATOR_H
#define DECORATOR_H
#include <iostream>
#include <string>

class Tea {
protected:
	int strength, bitter, temp;

public:
	Tea() : strength(55), bitter(55), temp(55) {}

	virtual int getStrength() {return strength;}
	virtual int getBitter() {return bitter;}
	virtual int getTemp() {return temp;}

	void getState() {
		std::cout << "\033[91m-----------\033[0m" << std::endl
			<< "Strength: " << (this->getStrength()) << std::endl
			<< "Bitter: " << this->getBitter() << std::endl
			<< "Temperature: " << this->getTemp() << std::endl
			<< "\033[91m-----------\033[0m" << std::endl;
	}
};

class Milk : public Tea {
protected:
	Tea* tea;

public:
	Milk(Tea* t) {
		this->tea = t;
		this->strength -= 30;
		this->bitter -= 20;
	}

	int getStrength() {return strength + tea->getStrength();}
	int getBitter() {return bitter + tea->getBitter();}
	int getTemp() {return tea->getTemp();}
};

class Sugar : public Tea {
protected:
	Tea* tea;

public:
	Sugar(Tea* t) {
		this->tea = t;
		this->bitter -= 15;
	}

	int getStrength() { return tea->getStrength(); }
	int getBitter() { return bitter + tea->getBitter(); }
	int getTemp() { return tea->getTemp(); }
};

class Syrup : public Tea {
protected:
	Tea* tea;
	int flavor;

public:
	Syrup(Tea* t, int f) : tea(t), flavor(f) {}

	int getStrength() { return tea->getStrength(); }
	int getBitter() { return tea->getBitter(); }
	int getTemp() { return tea->getTemp(); }

	void getState() {
		std::cout << "\033[91m-----------\033[0m" << std::endl
			<< "Strength: " << (this->getStrength()) << std::endl
			<< "Bitter: " << this->getBitter() << std::endl
			<< "Temperature: " << this->getTemp() << std::endl
			<< "Flavor: " << flavor << std::endl
			<< "\033[91m-----------\033[0m" << std::endl;
	}
};
#endif //DECORATOR_H