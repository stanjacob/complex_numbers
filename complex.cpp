#include <iostream>
#include <cmath>
#include <complex>
#include <cassert>

class Complex_Num {
	double real_part, imaginary_part;

public:
	Complex_Num(double real, double imag) {
		real_part = real;
		imaginary_part = imag;
	}
	Complex_Num(double real) {
		real_part = real;
		imaginary_part = 0;
	}
	Complex_Num() {
		real_part = 0;
		imaginary_part = 0;
	}

	double get_real() const {
		return real_part;
	}

	double get_imag() const {
		return imaginary_part;
	}

	void set_real(double real) {
		real_part = real;
	}

	void set_imag(double imag) {
		imaginary_part = imag;
	}

	Complex_Num& operator+=(Complex_Num z) {
		real_part += z.real_part;
		imaginary_part += z.imaginary_part;
		return *this;
	}

	Complex_Num& operator-=(Complex_Num z) {
		real_part -= z.real_part;
		imaginary_part -= z.imaginary_part;
		return *this;
	}

	Complex_Num& operator*=(Complex_Num);
	Complex_Num& operator/=(Complex_Num);

	friend ostream& operator<<(ostream&, const Complex_Num&);
};

ostream& operator<<(ostream& os, const Complex_Num& comp) {
	os << '(' << comp.real_part << ' ' << comp.imaginary_part << ')';
	return os;
}

Complex_Num& Complex_Num::operator*=(Complex_Num z) {
	double new_real = real_part * z.get_real() - imaginary_part * z.get_imag();
	double new_imag = imaginary_part * z.get_real() + real_part * z.get_imag();
	real_part = new_real;
	imaginary_part = new_imag;
	return *this;
}

Complex_Num& Complex_Num::operator/=(Complex_Num z) {
	Complex_Num Complex_Num_num = *this;
	Complex_Num temp = Complex_Num(z.get_real(), -z.get_imag());
	Complex_Num_num *= temp;

	double Complex_Num_den = z.get_real() * z.get_real() + z.get_imag() * z.get_imag();
	
	real_part= Complex_Num_num.get_real() / Complex_Num_den;
	imaginary_part = Complex_Num_num.get_imag() / Complex_Num_den;

	return *this;
}

Complex_Num operator+(Complex_Num a, Complex_Num b) { return a += b; }
Complex_Num operator-(Complex_Num a, Complex_Num b) { return a -= b; }
Complex_Num operator-(Complex_Num a) { return Complex_Num(a.get_real(), a.get_imag()); }
Complex_Num operator*(Complex_Num a, Complex_Num b) { return a *= b; }
Complex_Num operator/(Complex_Num a, Complex_Num b) { return a /= b; }

bool operator==(Complex_Num a, Complex_Num b)
{
	return a.get_real() == b.get_real() && a.get_imag() == b.get_imag();
}

bool operator!=(Complex_Num a, Complex_Num b) 
{
	return !(a==b);
}

void f(Complex_Num z) 
{
	Complex_Num a = Complex_Num(2.3);
	Complex_Num b = Complex_Num(1/a);
	Complex_Num c = a+Complex_Num(1,2.3)*z;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	if (c != b) {
		c = -(b/a) + 2*b;
	}
}

void test_Complex_Num_class() {
	Complex_Num one = Complex_Num(4, 2);
	Complex_Num two = Complex_Num(7, 8);

	Complex_Num add_result = one + two;
	Complex_Num sub_result = one - two;
	Complex_Num mult_result = one * two;
	Complex_Num div_result = one / one;

	cout << add_result;
	cout << sub_result;
	cout << mult_result;
	cout << div_result;

	// assert(add_result == Complex_Num(11, 10));
	// assert(sub_result == Complex_Num(-3, -6));
	// assert(mult_result == Complex_Num(12, 46));
	// assert(div_result == Complex_Num(1, 0));

}

int main() {

	test_Complex_Num_class();

	while(1) {

		double real;
		double imag;

		std::cout << "Complex_Num number 1.\n";
		std::cout << "Real part: " << std::endl;
		std::cin >> real;
		std::cout << "Imag part: " << std::endl;
		std::cin >> imag;

		Complex_Num a = Complex_Num(real, imag);

		std::cout << "Complex_Num number 2.\n";
		std::cout << "Real part: " << std::endl;
		std::cin >> real;
		std::cout << "Imag part: " << std::endl;
		std::cin >> imag;

		Complex_Num b = Complex_Num(real, imag);

		char operation;
		std::cout << "Operation: ";
		std::cin >> operation;

		Complex_Num result;
		switch(operation) {
			case '+':
				result = a + b;
				break;
			case '-':
				result = a - b;
				break;
			case '*':
				result = a * b;
				break;
			case '/':
				result = a / b;
				break;
		}
		std::cout << result << std::endl;

	}

	return 0;
}