#include "iostream"

using namespace std;

class Y {
public:
  int a, b;
  char* name;
  Y(int i) {
	  a = i; b = i + 1;
  };
  Y(const char* n, int j = 0) { a = 0; b =0; };
};
static int value = 0;

int add(Y y) { value += y.a; };

int main() {
  cout << "value === " << value << endl;
  // equivalent to
  // obj1 = Y(2)
  Y obj1 = 2;
  add(obj1);
  cout << "value === " << value << endl;
  // equivalent to
  // obj2 = Y("somestring",0)
  Y obj2 = "somestring";
  add(obj2);
  cout << "value === " << value << endl;
  // equivalent to
  // obj1 = Y(10)
  obj1 = 10;
  add(obj1);
  cout << "value === " << value << endl;
  // equivalent to
  // add(Y(5))
  add(5);
  cout << "value === " << value << endl;
}
