#include <iostream>
#include <sstream>

std::stringstream add(int a, int b) {
	std::stringstream ss;
	ss << a+b;
	return ss;
}

std::stringstream sub(int a, int b) {
	std::stringstream ss;
	ss << a-b;
	return ss;
}

std::stringstream mult(int a, int b) {
	std::stringstream ss;
	ss << a*b;
	return ss;
}

std::stringstream divide(int a, int b) {
	std::stringstream ss;
	if(b==0) {
		ss << "Error";
	} else {
		ss << a/b;
	}
	return ss;
}

std::stringstream mod(int a, int b) {
	std::stringstream ss;
	if(b==0) {
		ss << "Error";
	} else {
		ss << a%b;
	}
	return ss;
}


std::stringstream checkOperatorAndCalc(int a, char op, int b) {
	switch (op){
		case '+':
			return add(a,b);
			break;
		case '-':
			return sub(a,b);
			break;
		case '*':
			return mult(a,b);
			break;
		case '/':
			return divide(a,b);
			break;
		case '%':
			return mod(a,b);
			break;
		default:
			std::stringstream ss;
			ss << "Error";
			return ss;
	}
}

std::stringstream calc(std::istream &in) {
	int a {0};
	int b {0};
	char op {'?'};
	in >> a;
	in >> op;
	in >> b;

	return checkOperatorAndCalc(a,op,b);
}
