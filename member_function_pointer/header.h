#include "iostream"

using namespace std;

class TestClass{

public:
	TestClass();
	
	double mul(double, double);
	
	double plus(double , double);
	
	typedef double (TestClass::*func_pointer) (double , double); 
	
	double (TestClass::*function_pointer) (double , double);
	
	func_pointer fp_instance;
};