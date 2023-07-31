#include "header.h"

void test(){
	FirstElement firstElement;
	SecondElement secondElement;
	ParamClass<FirstElement, SecondElement> v(firstElement, secondElement);
	TemplateClass<FirstElement, SecondElement, ParamClass> templateObj(firstElement, secondElement);
	templateObj.getInstance();
}
