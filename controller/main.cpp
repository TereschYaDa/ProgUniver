#include "controller.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	controller ctrl;
	ctrl.execute();
}