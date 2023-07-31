#include "simpleTemplateFunction.h"

// template specialisation
template <>
double calculate( double param1, double param2){
	return param1 - param2;
}

template<>
int multiply(int param1, int param2){
	return param1 * param2;
}

template<>
int * createArray<int, 0>(){
	return new int;
}

// template explicit instantiation
template float calculate(float , float);

template double multiply(double, float);

void test(){
	int a = 10;
	int b = 20;
	// template implicitly instantiation
	calculate(a, b);
	float c = 1.1;
	float d = 2.2;
	calculate(c, d);
	multiply<float , double>(1.23f, 1.25);
	createArray<int, 5>();
	createArray<int, 0>();
	createArray<int, -5>();
}
