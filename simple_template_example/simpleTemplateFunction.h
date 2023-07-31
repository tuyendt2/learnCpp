
#ifndef SIMPLETEMPLATEFUNCTION_H_
#define SIMPLETEMPLATEFUNCTION_H_

// function template
template <class T>
T calculate(T t1, T t2){
	return t1 + t2;
}


// function template with 2 parameters

template <class T, class Z>
T multiply(T t, Z z){
	return t * z;
}

// function template with non-type parameter

template <class T, int N>
T* createArray(){
	T * arrT = nullptr;
	if (N > 0){
//		arrT = new T[N];
		arrT = new T;
	}
	return arrT;
}

// template explicit specialisation declaration
template<> int multiply(int param1, int param2);

//template float calculate(float , float);


#endif /* SIMPLETEMPLATEFUNCTION_H_ */
