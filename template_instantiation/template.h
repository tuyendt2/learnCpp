/*
 * template.h
 *
 *  Created on: 21 Jul 2022
 *      Author: SYS02
 */

#ifndef TEMPLATE_H_
#define TEMPLATE_H_

template< class T>
class TempalteClass{
public:
	TempalteClass(T t){
		m_Member = t;
	}
	void dummyFunction(){

	}
	template<class X>
	X templateFunction(X x){
		return 2*x;
	}
private:
	T m_Member;
};
typedef class TempalteClass<int> TempalteClassInt;

#endif /* TEMPLATE_H_ */
