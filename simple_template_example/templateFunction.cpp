#include "templateFunction.h"

// template specialisation
template <>
double calculate( double param1, double param2){
	return param1 - param2;
}

// template explicit instantiation
template float calculate(float , float);

void test(){
	int a = 10;
	int b = 20;
	// template implicit instantiation
	calculate(a, b);
}

