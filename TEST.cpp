#include "TEST.h"

bool TEST_INT() {
	MyStack::Stack<int> data(3);
	data.push(5);
	data.push(39);
	data.push(10);
	data.push(7);
	std::cout << "Stack: " << std::endl << data;
	std::cout << "Empty? " << data.empty() << std::endl;
	std::cout << "Pop " << data.pop() << std::endl;
	std::cout << data;
	data.optimize();
	std::cout << data;
	std::cout << data.check_pop() << std::endl;
	std::cout << data;
	std::cout << "Change data.top() = 9" << std::endl;
	data.top() = 9;
	std::cout << data;
	std::cout << "Change data.swap(4)" << std::endl;
	data.swap(4);
	std::cout << data;
	data.clear();
	std::cout << data;
	std::cout << "Empty? " << data.empty() << std::endl;
	data.push(3);
	std::cout << data;
	std::cout << "data << 5" << std::endl;
	data << 5;
	std::cout << data;
	std::cout << "int temp; temp >> data";
	int temp;
	temp >> data;
	std::cout << "temp = " << temp << std::endl;
	std::cout << data;

	return true;
}

bool TEST_DOUBLE() {
	MyStack::Stack<double> data(2);
	data.push(5.3);
	data.push(39.8);
	data.push(10.1);
	data.push(7.2);
	std::cout << "Stack: " << std::endl << data;
	std::cout << "Empty? " << data.empty() << std::endl;
	std::cout << "Pop " << data.pop() << std::endl;
	std::cout << data;
	data.optimize();
	std::cout << data;
	std::cout << data.check_pop() << std::endl;
	std::cout << data;
	std::cout << "Change data.top() = 9.7" << std::endl;
	data.top() = 9.7;
	std::cout << data;
	std::cout << "Change data.swap(4.4)" << std::endl;
	data.swap(4.4);
	std::cout << data;
	data.clear();
	std::cout << data;
	std::cout << "Empty? " << data.empty() << std::endl;
	data.push(3.8);
	std::cout << data;
	std::cout << "data << 5.5" << std::endl;
	data << 5.5;
	std::cout << data;
	std::cout << "double temp; temp >> data";
	double temp;
	temp >> data;
	std::cout << "temp = " << temp << std::endl;
	std::cout << data;

	return true;
}

bool TEST_STRUCT() {
	MyStack::Stack<testStruct> data(2);
	testStruct test("Oliver", 10);
	data.push(test);
	test("Juliana", 54);
	data.push(test);
	test("Dmitriy", 33);
	data.push(test);
	test("Thomas", 15);
	data.push(test);
	std::cout << "Stack: " << std::endl << data;
	std::cout << "Empty? " << data.empty() << std::endl;
	std::cout << "Pop " << data.pop() << std::endl;
	std::cout << data;
	data.optimize();
	std::cout << data;
	std::cout << data.check_pop() << std::endl;
	std::cout << data;
	std::cout << "Change data.top() = Rachel, 25" << std::endl;
	test("Rachel", 25);
	data.top() = test;
	std::cout << data;
	std::cout << "Change data.swap(\"Pierre\", 45)" << std::endl;
	test("Pierre", 45);
	data.swap(test);
	std::cout << data;
	data.clear();
	std::cout << data;
	std::cout << "Empty? " << data.empty() << std::endl;
	test("Kristina", 20);
	data.push(test);
	std::cout << data;
	std::cout << "data << \"Nicolas\", 12" << std::endl;
	test("Nicolas", 12);
	data << test;
	std::cout << data;
	std::cout << "testStruct temp; temp >> data";
	test >> data;
	std::cout << "temp = " << test << std::endl;
	std::cout << data;

	return true;
}

bool TEST_STRING() {
	MyStack::Stack<std::string> data(2);
	data.push("Oliver");
	data.push("Juliana");
	data.push("Dmitriy");
	data.push("Thomas");
	std::cout << "Stack: " << std::endl << data;
	std::cout << "Empty? " << data.empty() << std::endl;
	std::cout << "Pop " << data.pop() << std::endl;
	std::cout << data;
	data.optimize();
	std::cout << data;
	std::cout << data.check_pop() << std::endl;
	std::cout << data;
	std::cout << "Change data.top() = Rachel" << std::endl;
	data.top() = "Rachel";
	std::cout << data;
	std::cout << "Change data.swap(\"Pierre\")" << std::endl;
	data.swap("Pierre");
	std::cout << data;
	data.clear();
	std::cout << data;
	std::cout << "Empty? " << data.empty() << std::endl;
	data.push("Kristina");
	std::cout << data;
	std::cout << "data << \"Nicolas\"" << std::endl;
	data << "Nicolas";
	std::cout << data;
	std::cout << "std::string temp; temp >> data";
	std::string temp;
	temp >> data;
	std::cout << "temp = " << temp << std::endl;
	std::cout << data;

	return true;
}