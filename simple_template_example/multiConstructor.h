/*
 * multiConstructor.h
 *
 *  Created on: 5 May 2022
 *      Author: SYS02
 */

#ifndef MULTICONSTRUCTOR_H_
#define MULTICONSTRUCTOR_H_


template< class T>
class MultiConstructor{
public:
	MultiConstructor(){
		mValue = 0;
	}
	MultiConstructor(T t){
		mValue = t;
	}

	MultiConstructor(T t1, T t2){
		if ( t1 > t2){
			mValue = t1;
		} else {
			mValue = t2;
		}
	}

	T getValue(){
		return mValue;
	}
public:
	void setValue(T value){
		mValue = value;
	}

private:
	T mValue;
};


#endif /* MULTICONSTRUCTOR_H_ */
