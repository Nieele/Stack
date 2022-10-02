#include <iostream>
#include "Stack.h"
#include "TEST.h"

void show_result(bool res) {
	if (res) std::cout << "\n_______________________SUCCESS!________________________\n";
	else std::cout << "\n************************ERROR!***********************\n";
}

int main() {
	std::cout << "Test int";
	show_result(TEST_INT());

	std::cout << "Test double";
	show_result(TEST_DOUBLE());

	std::cout << "Test struct";
	show_result(TEST_STRUCT());

	std::cout << "Test std::string";
	show_result(TEST_STRING());

	return 0;
}