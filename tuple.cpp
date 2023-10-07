#include <utility>
#include <tuple>
#include <iostream>

int main() {
    std::pair d(0, 0.0);
    std::tuple t(1, 2, 3);
    
    std::cout << std::get<0>(t) << ", " << std::get<1>(t) << ", " << std::get<2>(t) << "\n";
}