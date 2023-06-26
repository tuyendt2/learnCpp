#include "header.h"

TestClass::TestClass(){
	cout << "TestClass() constructor " << endl;
	fp_instance = &TestClass::mul;
}

double TestClass::mul(double x , double y){
	cout << "TestClass::mul(double, double) " << endl;
	return x * y;
}
	
double TestClass::plus(double x, double y){
	cout << "TestClass::plus(double, double) " << endl;
	return x + y;
}


int main(){
	TestClass testObj;
	testObj.function_pointer = &TestClass::plus;
	double ret = (testObj.*testObj.function_pointer)(2, 5);
	cout << "ret = (testObj.*testObj.function_pointer)(2, 5) =  " << ret << endl;
	double (TestClass::*another_fp)(double , double );
	another_fp = &TestClass::mul;
	cout <<  "(testObj.*another_fp)(1, 3) " << (testObj.*another_fp)(1, 3) << endl;
	cout << "(testObj.*testObj.fp_instance)(1,2) " << (testObj.*testObj.fp_instance)(1,2) << endl;
	
	return 0;
}