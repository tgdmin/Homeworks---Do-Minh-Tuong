// 2) Construct the Vector class. It should have overloaded compound assingment and arithmetical operators (for adding/substituting vector and vector), getters and setters, << and >> operators, constructors and assingment operator. 
// The multiplication should be overloaded in two ways: if one of the operands is number, then vector is just multiplied by number. 
// If both operands are vectors, multiplication should return scalar product. 

#include <iostream>
#include <vector>

using namespace std;

class Vector {
private:
    vector<double> components;

public:
    Vector() {}                                                 //Constructor

    explicit Vector(const vector<double>& components) {
        this->components = components;
    }

    const vector<double>& getComp() const {      // Getters and setters
        return components; 
    }
    void setComp(const vector<double>& newComp) {
        components = newComp;
    }

    Vector& operator+=(const Vector& other) {           // Overloaded compound assignment operator plus
        if (components.size() == other.components.size()) {
            for (size_t i = 0; i < components.size(); ++i) {
                components[i] += other.components[i];
            }
        } else {
            std::cout << "Vectors are unable to add." << std::endl;
        }
        return *this;
    }

    Vector& operator-=(const Vector& other) {           // Overloaded compound assignment operator minus
        if (components.size() == other.components.size()) {
            for (size_t i = 0; i < components.size(); ++i) {
                components[i] -= other.components[i];
            }
        } else {
            cout << "Vectors are unable to subtract." << endl;
        }
        return *this;
    }

    Vector& operator*=(double scalar) {             // Overloaded compound assignment operator multiply
        for (size_t i = 0; i < components.size(); ++i) {
            components[i] *= scalar;
        }
        return *this;
    }

    //friend function: to access all  private, protected, and public 
    friend Vector operator+(const Vector& v1, const Vector& v2);         // Overloaded arithmetic operators
    friend Vector operator-(const Vector& v1, const Vector& v2);
    friend Vector operator*(const Vector& v, double scalar);
    friend double operator*(const Vector& v1, const Vector& v2);

    friend std::ostream& operator<<(std::ostream& os, const Vector& v);      // Overloaded input/output operators
    friend std::istream& operator>>(std::istream& is, Vector& v);
};

Vector operator+(const Vector& v1, const Vector& v2) {          // Overloaded non-member arithmetic operator plus
    Vector result = v1;
    result += v2;
    return result;
}

Vector operator-(const Vector& v1, const Vector& v2) {          // Overloaded non-member arithmetic operator minus
    Vector result = v1;
    result -= v2;
    return result;
}

Vector operator*(const Vector& v, double scalar) {              // Overloaded non-member arithmetic operator multiply
    Vector result = v;
    result *= scalar;
    return result;
}

double operator*(const Vector& v1, const Vector& v2) {
    if (v1.components.size() == v2.components.size()) {
        double dotProduct = 0.0;
        for (size_t i = 0; i < v1.components.size(); ++i) {
            dotProduct += v1.components[i] * v2.components[i];
        }
        return dotProduct;
    } else {
        cout << "Vectors must have the same size for dot product." << endl;
        return 0.0;
    }
}

ostream& operator<<(ostream& os, const Vector& v) {           // Overloaded output operator
    os << "[ ";
    for (size_t i = 0; i < v.components.size(); ++i) {
        os << v.components[i] << " ";
    }
    os << "]";
    return os;
}

istream& operator>>(istream& is, Vector& v) {             // Overloaded input operator
    size_t size;
    is >> size;

    vector<double> newComp(size);
    for (size_t i = 0; i < size; ++i) {
        is >> newComp[i];
    }

    v.setComp(newComp);

    return is;
}

int main() {
    Vector v1({2.0, 3.0, 4.0});         //Test cases
    Vector v2({5.0, 6.0, 7.0});

    Vector sum = v1 + v2;
    Vector difference = v1 - v2;
    Vector scaled = v1 * 2.0;
    double dotProduct = v1 * v2;

    cout << "v1 + v2 = " << sum << endl;              //Result
    cout << "v1 - v2 = " << difference << endl;
    cout << "v1 * 2.0 = " << scaled << endl;
    cout << "Dot product = " << dotProduct << endl;

    return 0;
}
