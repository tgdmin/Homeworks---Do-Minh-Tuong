// 1) Construct the fraction class for the rational numbers. 
// It should have overloaded compound assingment and arithmetical operators following the rules we discussed in the class, getters and setters, << and >> operators, constructors and assingment operator. 
// You should always have simplified version of the fraction after all the operations. 
// Write the function to convert the fraction into the "double" type. Please verify that all of your implemented operations work properly before sending the solution.

#include <iostream>
#include <cmath>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) {                                           // Greatest common divisor 
        return (b == 0) ? a : gcd(b, a % b);
    }

    void simplify() {                                                 // Simplify the fraction 
        int cFactor = gcd(abs(numerator), abs(denominator));
        numerator /= cFactor;
        denominator /= cFactor;
    }

public:
    Fraction() {                    //Constructor
        numerator = 0;
        denominator = 1;
    }

    Fraction(int num, int denom) {
        numerator = num;
        denominator = denom;
        simplify();
    }


    int getNum() const {            // Getters and setters
        return numerator; 
    }               

    int getDenom() const { 
        return denominator; 
    }

    void setNum(int num) {        
        numerator = num;
        simplify();
    }

    void setDenom(int denom) {    
        if (denom != 0) {
            denominator = denom;
            simplify();
        } else {
            cout << "Err: Denominator can't be zero." << endl;
        }
    }

    Fraction& operator+=(const Fraction& other) {                     // Overloaded compound assignment operators plus
        numerator = numerator * other.denominator + other.numerator * denominator;
        denominator *= other.denominator;
        simplify();
        return *this;
    }

    Fraction& operator-=(const Fraction& other) {                     // Overloaded compound assignment operators minus
        numerator = numerator * other.denominator - other.numerator * denominator;
        denominator *= other.denominator;
        simplify();
        return *this;
    }

    Fraction& operator*=(const Fraction& other) {                      // Overloaded compound assignment operators multiply
        numerator *= other.numerator;
        denominator *= other.denominator;
        simplify();
        return *this;
    }

    Fraction& operator/=(const Fraction& other) {                       // Overloaded compound assignment operators divide
        if (other.numerator != 0) {
            numerator *= other.denominator;
            denominator *= other.numerator;
            simplify();
        } else {
            cout << "You can't divide by zero." << endl;
        }
        return *this;
    }
    //friend function: to access all  private, protected, and public 
    friend Fraction operator+(const Fraction& f1, const Fraction& f2);  // Overloaded arithmetic operators
    friend Fraction operator-(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator/(const Fraction& f1, const Fraction& f2);

    friend ostream& operator<<(ostream& os, const Fraction& fraction);    // Overloaded input/output operators
    friend istream& operator>>(istream& is, Fraction& fraction);

    operator double() const {               // Convert to type double
        return static_cast<double>(numerator) / denominator;
    }
};

Fraction operator+(const Fraction& f1, const Fraction& f2) {        // Overloaded non-member arithmetic operator plus
    Fraction result = f1;
    result += f2;
    return result;
}

Fraction operator-(const Fraction& f1, const Fraction& f2) {        // Overloaded non-member arithmetic operator minus
    Fraction result = f1;
    result -= f2;
    return result;
}

Fraction operator*(const Fraction& f1, const Fraction& f2) {        // Overloaded non-member arithmetic operator mutiply
    Fraction result = f1;
    result *= f2;
    return result;
}

Fraction operator/(const Fraction& f1, const Fraction& f2) {        // Overloaded non-member arithmetic operator divide
    Fraction result = f1;
    result /= f2;
    return result;
}

ostream& operator<<(ostream& os, const Fraction& fraction) {      // Overloaded output operator
    os << fraction.numerator;
    if (fraction.denominator != 1) {
        os << '/' << fraction.denominator;
    }
    return os;
}

istream& operator>>(istream& is, Fraction& fraction) {        // Overloaded input operator
    char slash;
    is >> fraction.numerator >> slash >> fraction.denominator;
    if (slash != '/') {
        is.setstate(ios::failbit);
    } else {
        fraction.simplify();
    }
    return is;
}

int main() {                                               
    Fraction f1(2, 4);                  //Test cases
    Fraction f2(6, 8);

    Fraction sum = f1 + f2;             // Test arithmetic operators
    Fraction difference = f1 - f2;
    Fraction product = f1 * f2;
    Fraction quotient = f1 / f2;

    cout << "f1 + f2 = " << sum << " = " << static_cast<double>(sum) << endl;                     // Result
    cout << "f1 - f2 = " << difference << " = " << static_cast<double>(difference) << endl;
    cout << "f1 * f2 = " << product << " = " << static_cast<double>(product) << endl;
    cout << "f1 / f2 = " << quotient << " = " << static_cast<double>(quotient) << endl;

    return 0;
}
