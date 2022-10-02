#pragma once

#include <iostream>
#include "Stack.h"

struct testStruct{
	std::string name;
	int age;
public:
	testStruct() { name = "NULL", age = 0; }
	testStruct(const char* name, int age) : name(name), age(age) {}
	void operator()(std::string name, int age) { this->name = name; this->age = age; }
	void operator=(testStruct other) { name = other.name; age = other.age; }
	friend std::ostream& operator<<(std::ostream& os, testStruct ts) { os << ts.name << " " << ts.age; return os; }
};

bool TEST_INT();
bool TEST_DOUBLE();
bool TEST_STRUCT();
bool TEST_STRING();