/*
 * template.cpp
 *
 *  Created on: 21 Jul 2022
 *      Author: SYS02
 */
#include "template.h"
template class TempalteClass<int>;

void test(){
	int a =1;
//	TempalteClass<int> t(a);
	TempalteClassInt t2(a);
	t2.dummyFunction();
//	float b = 1.01;
//	t2.templateFunction(b);
}


