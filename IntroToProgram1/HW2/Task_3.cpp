// 3) Construct the Figure class and inheritance hierarchy. At the top of the hierarchy is the base class Figure, from which Triangle, Rectangle, and Circle inherit.
// Each figure class stores the properties it needs and provides constructors,getters and setters for accessing them, also implements methods for calculating area and perimeter. 
// Methods must be virtual, take no parameters, but return the result of a calculation.

#include <iostream>
#include <cmath>

using namespace std;

class Figure {          // Base class 
public:
    virtual double Area() const = 0;           // Virtual methods to calculate area and perimeter
    virtual double Perimeter() const = 0;

    virtual ~Figure() {}         // Virtual destructor
};

class Triangle : public Figure {            // Derived class Triangle
private:
    double side1;
    double side2;
    double side3;

public:

    Triangle() : side1(0.0), side2(0.0), side3(0.0) {}           // Constructors
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

    double getSide1() const {                       // Getters and setters
        return side1; 
    }        
    double getSide2() const { 
        return side2; 
    }
    double getSide3() const { 
        return side3; 
    }
    void setSide1(double s1) { 
        side1 = s1; 
    }
    void setSide2(double s2) { 
        side2 = s2; 
    }
    void setSide3(double s3) { 
        side3 = s3; 
    }

    double Area() const override {         // Virtual methods to calculate area and perimeter
        double s = Perimeter() / 2.0;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    double Perimeter() const override {
        return side1 + side2 + side3;
    }
};

class Rectangle : public Figure {       // Derived class Rectangle
private:
    double length;
    double width;

public:
    Rectangle() : length(0.0), width(0.0) {}             // Constructors
    Rectangle(double l, double w) : length(l), width(w) {}

    double getLength() const {              // Getters and setters
        return length; 
    }     
    double getWidth() const { 
        return width; 
    }

    void setLength(double l) { 
        length = l; 
    }
    void setWidth(double w) { 
        width = w; 
    }

    double Area() const override {         // Virtual methods to calculate area and perimeter
        return length * width;
    }

    double Perimeter() const override {
        return 2 * (length + width);
    }
};

class Circle : public Figure {          // Derived class Circle
private:
    double radius;

public:
    Circle() : radius(0.0) {}            // Constructors
    Circle(double r) : radius(r) {}

    double getRadius() const {                    // Getter and setter
        return radius; 
    }       
    void setRadius(double r) { 
        radius = r; 
    }

    double Area() const override {         // Virtual methods to calculate area and perimeter
        return 3.14 * radius * radius;
    }

    double Perimeter() const override {
        return 2 * 3.14 * radius;
    }
};

int main() {
    Triangle triangle(3.0, 4.0, 5.0);           //Test cases
    Rectangle rectangle(2.0, 3.0);
    Circle circle(1.0);

    cout << "Rectangle Area: " << rectangle.Area() << endl;                //Result
    cout << "Rectangle Perimeter: " << rectangle.Perimeter() << endl;

    cout << "Triangle Area: " << triangle.Area() << endl;                   
    cout << "Triangle Perimeter: " << triangle.Perimeter() << endl;

    cout << "Circle Area: " << circle.Area() << endl;
    cout << "Circle Perimeter: " << circle.Perimeter() << endl;

    return 0;
}
