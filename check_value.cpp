#include <iostream>
#include <string>
#include "random_value.h"
#include "high_scores.h"
#include "argument.h"


int main(int argc, char* argv[]) {
	
	int target_value = 54;
	int current_value = 0;
	int max_value = 10;
	bool not_win = true;
	int nom_par;
	int par_value =  argumet_compare(argc, argv, nom_par);
	if (nom_par == 2) {
		read_high_score();
		return -1;
	}
	std::cout << argv[0] << std::endl;

	std::cout << "Hi! Enter your name, please:" << std::endl;
	std::string user_name;
	std::cin >> user_name;
	int amount_value = 0;
	if (nom_par == 1) {
		max_value = par_value;	
	}
	else if (nom_par == 3) {
		switch (par_value) {
			case 1:
				max_value = 10;
				break;
			case 2:
				max_value = 50;
				break;
			case 3:
				max_value = 100;
				break;
		}
	}
	target_value = help_random(max_value);


	std::cout << "Enter your guess:" << std::endl;

	do {
		std::cin >> current_value;

		if (current_value < target_value) {
			std::cout << "less than " << current_value << std::endl;
			amount_value++;
		}
		else if (current_value > target_value) {
			std::cout << "greater than " << current_value << std::endl;
			amount_value++;
		}
		else {
			std::cout << "you win! attemps = "<< amount_value << std::endl;
			amount_value++;
			save_high_score(user_name, amount_value);
			break;
		}

	} while(true);
	read_high_score();
	return 0;
}