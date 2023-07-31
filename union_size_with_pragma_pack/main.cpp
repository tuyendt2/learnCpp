
/*
 * main.cpp
 *
 *  Created on: 30 Nov 2022
 *      Author: SYS02
 */
#include "iostream"

using namespace std;

union union_type {
	float a;
	double b;
};
//#pragma pack(1)
// Bit field test 2
struct struct12 {
    int a;
    int b : 8;
    int c : 16;
    char d;
    int e : 1;
};

// Bit field test 4 (check alignment of bit field c)
struct struct14 {
    int a;
    int b : 8;
    int c : 16;
    char d;
};
//#pragma pack(0)

int main(){
	union union_type u = {1.5};
	cout << "u.a == " << u.a << endl;
	cout << "u.b == " << u.b << endl;
	cout << "sizeof struct12 = " << sizeof(struct struct12) << endl;
	cout << "sizeof struct14 = " << sizeof(struct struct14) << endl;
	struct struct12  struct12_instance;
	return 0;
}




