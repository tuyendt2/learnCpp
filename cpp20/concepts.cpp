// C++ program to illustrate the constrains 
#include <iostream> 
#include <type_traits> 

using namespace std; 

// Function template with constraint using requires clause 
template <typename T> 
requires is_integral_v<T> 
void print_integer(T value) 
{ 
	cout << "The integer value is: " << value << endl; 
} 

// Concept definition 
template <typename T> concept Printable = requires(T value) 
{ 
	cout << value << endl; 
}; 

// Function template with concept as a constraint 
template <Printable T> void print(T value) 
{ 
	cout << "The printable value is: " << value << endl; 
} 

template <typename T1, typename T2>
concept integral_comparable = (is_integral_v<T1> || is_floating_point_v<T1>) && (is_integral_v<T2> || is_floating_point_v<T2>);

template <typename T1, typename T2 >
requires integral_comparable<T1, T2>
bool compareValues(T1 t1, T2 t2){
     cout << "t1 = " << t1 << " , t2 = " << t2 << endl;
     return t1 > t2;
}

template <typename U, typename Y>
concept addable_types = requires (U uVal, Y yVal){
	{uVal + yVal} -> convertible_to<U>;
};


template<typename T1, typename T2, typename T3>
requires addable_types<T1,T2> && addable_types<T1, T3> && addable_types<T2, T3>
bool add_val(T1 t1, T2 t2, T3 t3){
   cout << "t1 + t2 = " << t1 + t2 << endl;
   cout << "t2 + t3 = " << t2 + t3 << endl;
   cout << "t1 + t3 = " << t1 + t3 << endl;
   return t1 + t2 + t3;
}

int main() 
{ 
	// Call the print_integer function with an integer 
	// argument 
	print_integer(42); 

	// Call the print function with a string argument 
	print("Hello, World!"); 
	
	compareValues(1, 20);
	compareValues(1.9999, 2.00000);
	compareValues(1.9999, 2);
	compareValues(2, 2.00000);
	
	add_val(1, 1.25, 3.75d);
	float a = 1.999999999999999999;
	int b =2;
	auto ret = a <=> b;
	if ( ret > 0){
		cout << "a > b" << endl; 
	} else if (ret < 0){
		cout << "a < b" << endl;
	} else { 
		cout << "a ==b" << endl;
	}
	
}

