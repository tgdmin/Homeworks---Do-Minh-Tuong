#include <iostream>
#include <utility>

// Base case function for perfect forwarding
void print() {
    std::cout << std::endl; // Print newline when no arguments are left
}

// Variadic template function for perfect forwarding
template<typename T, typename... Args>
void print(T&& arg, Args&&... args) {
    std::cout << std::forward<T>(arg) << " "; // Print the forwarded argument
    print(std::forward<Args>(args)...); // Recursively call print for remaining arguments
}

int main() {
    int a = 5;
    double b = 2;
    std::string c = "Hello";

    print(a, b, c); // Print integers, doubles, and strings
    print("Good", "morning", "my", "Moscow"); // Print constant strings
    print(31, "Answer", 2); // Print mixed types

    return 0;
}
