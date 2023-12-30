#include "decorator.h"

int main() {
	Tea* tea = new Tea();
	tea->getState();

	Tea* teaWithMilk = new Milk(tea);
	teaWithMilk->getState();

	Tea* teaWithMilkAndSugar = new Sugar(teaWithMilk);
	teaWithMilkAndSugar->getState();

	Tea* teaWithMilkSugarAndSyrup = new Syrup(teaWithMilkAndSugar, 2);
	teaWithMilkSugarAndSyrup->getState();

	return 0;
}