#include <iostream>
#include <sstream>

int add(int a, int b) {
	return a+b;
}

int sub(int a, int b) {
	return a-b;
}

int mult(int a, int b) {
	return a*b;
}

int divide(int a, int b) {
	return a/b;
}

int mod(int a, int b) {
	return a%b;
}


std::stringstream checkOperatorAndCalc(int a, char op, int b) {
	std::stringstream ss;
	switch (op) {
		case '+':
			ss << add(a,b);
			break;
		case '-':
			ss << sub(a,b);
			break;
		case '*':
			ss << mult(a,b);
			break;
		case '/':
			if(b==0) {
				ss << "Error";
			} else {
				ss << divide(a,b);
			}
			break;
		case '%':
			if(b==0) {
				ss << "Error";
			} else {
				ss << mod(a,b);
			}
			break;
		default:
			ss << "Error";
	}
	return ss;
}

std::stringstream calc(std::istream &in) {
	try {
		int a {0};
		int b {0};
		char op {'?'};
		in >> a;
		in >> op;
		in >> b;
		return checkOperatorAndCalc(a,op,b);
	} catch (...) {
		std::stringstream ss;
		ss << "Error";
		return ss;
	}
}
