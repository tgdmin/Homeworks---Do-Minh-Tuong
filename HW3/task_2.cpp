#include <iostream>
using namespace std;

// Create meta - function to calculate the sum of a sequence: 
template<int Base, int Exponent>
struct Power {
    static const int Result = Base * Power<Base, Exponent - 1>::Result;
};

// For the case Base ^ 0 = 1:
template<int Base>
struct Power<Base, 0> {
    static const int Result = 1;
};

template<int Base, int Exponent>
struct SumOfSequence {
    static const int Value = Power<Base, Exponent>::Result + SumOfSequence<Base, Exponent - 1>::Value;
};

// For the case the sequence has one element: 
template<int Base>
struct SumOfSequence<Base, 0> {
    static const int Value = 1;
};

int main() {
    cout << "Sum of Power sequence: " << endl;
    cout << SumOfSequence<2, 5>::Value;  
    return 0;
}
