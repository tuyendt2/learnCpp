
#ifndef HEADER_H_
#define HEADER_H_


void intCheck(int);

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

#endif /* HEADER_H_ */
