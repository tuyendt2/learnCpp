#include "multiConstructor.h"

void test(){
	MultiConstructor<int> testObject;
	testObject.setValue(100);
	testObject.getValue();

	float value = 1.01;
	MultiConstructor<float> sTestObject(value);
	sTestObject.getValue();

	double dValue = 1.01;
	double dValue2 = 2.03;
	MultiConstructor<double> tTestObject(dValue, dValue2);
	tTestObject.getValue();

	MultiConstructor<double> fTestObject(dValue2, dValue);
	fTestObject.getValue();

	MultiConstructor<long> lTestObject;
	lTestObject.setValue(1000);
	lTestObject.getValue();
}
