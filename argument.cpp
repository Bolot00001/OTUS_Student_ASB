#include <iostream>
#include <string>
#include "argument.h"

int argumet_compare(int argx, char** args, int &n_par) {

	int parameter_value = 0;

	 //argc - it is a count of arguments
	 //But there is some detail - OS always pass one system argument - the name of the executable
	 //So, is the application was executed without arguments at all, argc will be still == 1
	
	 //Let's print this argument
	if (argx > 0) {
		//std::cout << "We have at least one argument!" << std::endl;
		//std::cout << "argv[0] = " << argx << std::endl;
	}

	// To check - does use print some other argument we should check if the argc >= 2
	if (argx >= 2) {
		//std::cout << "We have one more argument!" << std::endl;
		//std::cout << "argv[1] = " << args[1] << std::endl;

		std::string arg1_value{ args[1] };
		if (arg1_value == "-max") {
			std::cout << "-parameter argument was detected!  " << args[1] << std::endl;
			n_par = 1;
			// We've detected the '-parameter' argument. And we extect that after this argument there is a value:
			//int parameter_value = 0;
			if (argx < 3) {
				std::cout << "Wrong usage! The argument '-parameter' requires some value!" << std::endl;
				return -1;
			}
			// We need to parse the string to the int value
			parameter_value = std::stoi(args[2]);
			std::cout << "The '-parameter' value = " << parameter_value << std::endl;
		}
		if (arg1_value == "-table") {
			std::cout << "-parameter argument was detected!  " << args[1] << std::endl;
			n_par = 2;
			// We've detected the '-parameter' argument. And we extect that after this argument there is a value:
		}
		if (arg1_value == "-level") {
			std::cout << "-parameter argument was detected!  " << args[1] << std::endl;
			n_par = 3;
			// We've detected the '-parameter' argument. And we extect that after this argument there is a value:
			//int parameter_value = 0;
			if (argx < 3) {
				std::cout << "Wrong usage! The argument '-parameter' requires some value!" << std::endl;
				return -1;
			}
			// We need to parse the string to the int value
			parameter_value = std::stoi(args[2]);
			std::cout << "The '-parameter' value = " << parameter_value << std::endl;
		}
	}
	//std::cout << args[0] << std::endl;
	return parameter_value;

}