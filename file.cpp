#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Getter methods
    double getReal() const { return real; }
    double getImag() const { return imag; }

    // Overload + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload - operator
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload * operator
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
                       real * other.imag + imag * other.real);
    }

    // Overload / operator
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator,
                       (imag * other.real - real * other.imag) / denominator);
    }

    // Overload == operator
    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }

    // Overload != operator
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    // Overload << operator for output
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }

    // Overload prefix ++ operator
    Complex& operator++() {
        real++;
        return *this;
    }

    // Overload postfix ++ operator
    Complex operator++(int) {
        // Complex temp = *this;
        // real++;
        // return temp;
        Complex temp = *this;
        real++;
        return temp;
    }

    // Overload prefix -- operator
    Complex& operator--() {
        real--;
        return *this;
    }

    // Overload postfix -- operator
    Complex operator--(int) {
        Complex temp = *this;
        real--;
        return temp;
    }
};

int main() {
 Complex c1(3.0, 4.0);
    Complex c2(2.0, 1.0);

    // Using + operator
    Complex c3 = c1 + c2;
    std::cout << "c1 + c2 = " << c3 << std::endl;

    // Using - operator
    c3 = c1 - c2;
    std::cout << "c1 - c2 = " << c3 << std::endl;

    // Using * operator
    c3 = c1 * c2;
    std::cout << "c1 * c2 = " << c3 << std::endl;

    // Using / operator
    c3 = c1 / c2;
    std::cout << "c1 / c2 = " << c3 << std::endl;

    // Using == operator
    std::cout << "c1 == c2: " << (c1 == c2 ? "True" : "False") << std::endl;

    // Using != operator
    std::cout << "c1 != c2: " << (c1 != c2 ? "True" : "False") << std::endl;

    // Using prefix ++ operator
    std::cout << "++c1 = " << ++c1 << std::endl;

    // Using postfix ++ operator
    std::cout << "c1++ = " << c1++ << std::endl;
    std::cout << "c1 after postfix ++ = " << c1 << std::endl;

    // Using prefix -- operator
    std::cout << "--c1 = " << --c1 << std::endl;

    // Using postfix -- operator
    std::cout << "c1-- = " << c1-- << std::endl;
    std::cout << "c1 after postfix -- = " << c1 << std::endl;

    return 0;
}