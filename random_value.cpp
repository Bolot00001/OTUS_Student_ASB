#include <iostream>
#include "random_value.h"
#include <cstdlib>
#include <ctime>

int help_random(int &max_value) {

	//const int max_value = 10;

	std::srand(std::time(nullptr)); // use current time as seed for random generator

	const int random_value = std::rand() % max_value;

	std::cout << random_value << std::endl;

	return random_value;
}
