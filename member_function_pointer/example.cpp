#include "iostream"

using namespace std;

int function_instance ( float a, double b){
	return a + b;
}

int (*FUNCTION_POINTER)(float, double);

class TestClass;

double (TestClass::*MEMBER_FUNCTION_POINTER)(int, float) = NULL;

class TestClass{
public:
	TestClass(){

	}
	double square(int width, float length){
		return width * length;
	}

	double perimeter(int width, float length){
		return 2*(width + length);
	}

	void process( double (TestClass::*function_pointer)(int, float), int first, float second ){
		MEMBER_FUNCTION_POINTER = function_pointer;
		cout << "process == " <<  (this->*MEMBER_FUNCTION_POINTER)(first, second) << endl;
	}

	void internalProcess(int x, float y){
		if( MEMBER_FUNCTION_POINTER == NULL){
			cout << "internalProcess : (this->*MEMBER_FUNCTION_POINTER) == NULL, x = " << x << " y = " << y << endl;
			return;
		}
		cout << "internalProcess =  " << (this->*MEMBER_FUNCTION_POINTER)(x,y) << endl;
	}
};



int main(){
	FUNCTION_POINTER = function_instance;
	cout << FUNCTION_POINTER(10, 20) << endl;
	TestClass testObject;
	testObject.internalProcess(10, 20);
	testObject.process(TestClass::square, 10, 20);
	MEMBER_FUNCTION_POINTER = TestClass::perimeter;
	(testObject.*MEMBER_FUNCTION_POINTER)(100, 200);
	testObject.internalProcess(10, 20);
	return 0;
}
