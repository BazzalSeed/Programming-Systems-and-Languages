#include <string>
#include <tuple>
#include <iostream>
#include <sstream>
using namespace std;
class Complex {

public:



	friend ostream;
	//Default constructor initialize to origin
	Complex()
	{
		get<0>(complex_number) = 0.00;
		get<1>(complex_number) = 0.00;
	}

	//constructor from double precision floating point numbers for the real and imaginary parts of the complex number
	Complex(double x  , double y ){
		double real = x + 0.00;
		double img = y + 0.00;
		get<0>(complex_number) = real;
		get<1>(complex_number) = img;

	}
	//copy construct
	Complex( const Complex & c ){

		tuple<double,double> test (c.complex_number);
		this->complex_number = test;
	}

	string to_string(){
		ostringstream os;
		os << "The complex number is: ";
		os << get<0>(complex_number) << " + " << get<1>(complex_number)<< "i" << endl;
		return os.str();
	}
	Complex operator*(Complex&c){
		double myReal = get<0>(complex_number);
		double myImg = get<1>(complex_number);
		double otherReal = get<0>(c.complex_number);
		double otherImg = get<1>(c.complex_number);
		double newReal = myReal* otherReal + myImg*otherImg;
		double newImg = myReal * otherImg + myImg*otherImg;
		Complex newComplex(newReal, newImg);
		return newComplex;
	}
	Complex operator+(Complex&c){
		double myReal = get<0>(complex_number);
		double myImg = get<1>(complex_number);
		double otherReal = get<0>(c.complex_number);
		double otherImg = get<1>(c.complex_number);
		double newReal = myReal + otherReal;
		double newImg =  myImg + otherImg;
		Complex newComplex(newReal, newImg);
		return newComplex;
	}
	Complex & operator << (tuple<double, double> t){
		complex_number = t;
		return *this;
	}
private:
	tuple<double, double> complex_number;
};

ostream & operator << (ostream & os, Complex c){
	os << c.to_string();
	return os;

}