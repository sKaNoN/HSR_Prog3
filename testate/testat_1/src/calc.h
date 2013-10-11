#ifndef CALC_H_
#define CALC_H_

#include <iosfwd>
#include <iostream>

int add(int a, int b);
int sub(int a, int b);
int mult(int a, int b);
int divide(int a, int b);
int mod(int a, int b);
std::stringstream checkOperatorAndCalc(int a, char op, int b);
std::stringstream calc(std::istream &in);

#endif /* CALC_H_ */
