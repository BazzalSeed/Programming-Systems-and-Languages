// Studio7_TMA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void SubOne(unsigned int n) 
{ 
	std::cout << "Value: " << n << " Address: " << &n << std::endl;
	if (n ==0)
	{
		return;
	}
	else
	{	
		SubOne(n-1);
	}
}
void addInt(int chris, int seed){

}

class Mengna
{ 
public:

	int a = 6;
	double b = 9.0;
};

class Peiyun : public Mengna
{ 
public:
	bool fml = true;
};


int main(int argc, char * argv[])
{
	/*
	//Question 2
	std::cout << "Size of char: " << sizeof(char) << std::endl;
	std::cout << "Size of bool: " << sizeof(bool) << std::endl;
	std::cout << "Size of int:  " << sizeof(int) << std::endl;
	std::cout << "Size of wchar_t:  " << sizeof(wchar_t) << std::endl;
	std::cout << "Size of char16_t:  " << sizeof(char16_t) << std::endl;
	std::cout << "Size of long:  " << sizeof(long) << std::endl;
	std::cout << "Size of char32_t:  " << sizeof(char32_t) << std::endl;
	std::cout << "Size of float:  " << sizeof(float) << std::endl;
	std::cout << "Size of double:  " << sizeof(double) << std::endl;
	std::cout << "Size of long long:  " << sizeof(long long) << std::endl;
	std::cout << "Size of long double:  " << sizeof(long double) << std::endl;
	
	std::cout << "Size of unsigned char:  " << sizeof(unsigned char) << std::endl;
	std::cout << "Size of unsigned short:  " << sizeof(unsigned short) << std::endl;
	std::cout << "Size of unsigned int:  " << sizeof(unsigned int) << std::endl;
	std::cout << "Size of unsigned long:  " << sizeof(unsigned long) << std::endl;
	std::cout << "Size of unsigned long long:  " << sizeof(unsigned long long) << std::endl;
	*/
	/*
	//Question 3

	int(*functionPtr)(int, int) = &addInt;
	std::cout << "Size of char: " << sizeof(char*) << std::endl;
	std::cout << "Size of bool: " << sizeof(bool*) << std::endl;
	std::cout << "Size of int:  " << sizeof(int*) << std::endl;
	std::cout << "Size of wchar_t:  " << sizeof(wchar_t*) << std::endl;
	std::cout << "Size of char16_t:  " << sizeof(char16_t*) << std::endl;
	std::cout << "Size of long:  " << sizeof(long*) << std::endl;
	std::cout << "Size of char32_t:  " << sizeof(char32_t*) << std::endl;
	std::cout << "Size of float:  " << sizeof(float*) << std::endl;
	std::cout << "Size of double:  " << sizeof(double*) << std::endl;
	std::cout << "Size of long long:  " << sizeof(long long*) << std::endl;
	std::cout << "Size of long double:  " << sizeof(long double*) << std::endl;

	std::cout << "Size of unsigned char:  " << sizeof(unsigned char*) << std::endl;
	std::cout << "Size of unsigned short:  " << sizeof(unsigned short*) << std::endl;
	std::cout << "Size of unsigned int:  " << sizeof(unsigned int*) << std::endl;
	std::cout << "Size of unsigned long:  " << sizeof(unsigned long*) << std::endl;
	std::cout << "Size of unsigned long long:  " << sizeof(unsigned long long*) << std::endl;
	std::cout << "Size of function ptr:  " << sizeof(functionPtr) << std::endl;
	*/


	/*
	//Question 4
	int  a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	double d[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
	float f[] = { 1.1, 2.1, 3.1, 4.1, 5.1, 6.1 };

	int * ptr_a = a;
	double * ptr_d = d;
	float * ptr_f = f;

	std::cout << "a int array prinout" << std::endl;
	for (int i = 0; i < 11; i++)
	{
		std::cout << ptr_a <<  " : "  << *ptr_a << std::endl;
		ptr_a++;
	}
	std::cout << std::endl;

	std::cout << std::endl;

	std::cout << "a double array prinout" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << ptr_d << " : " << *ptr_d << std::endl;
		ptr_d++;
	}
	std::cout << std::endl;

	std::cout << "a float array prinout" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << ptr_f << " : " << *ptr_f << std::endl;
		ptr_f++;
	}
	std::cout << std::endl;
	char array[] = "cao ni ma";
	for (int i = 0; i<9; i++){
		std::cout << static_cast<void*>(&array[i]) <<" : " << array[i]<< std::endl;
	}
	*/
	/*
	Question 5

	SubOne(0);
	std::cout << "New Call" << std::endl;
	SubOne(4);
	std::cout << "New Call" << std::endl;
	SubOne(15);
	std::cout << "New Call" << std::endl;
	SubOne(3);
	std::cout << "New Call" << std::endl;
	SubOne(2);
	std::cout << "New Call" << std::endl;
	SubOne(10);
	*/

	/*
	//Question 6
	Mengna m;
	Peiyun s;

	std::cout << "Struct Mengna: " << &m << ", size of Mengna is " << sizeof(m) << std::endl;
	std::cout << "From struct Mengna, value a: "<< &m.a << std::endl;
	std::cout << "From struct Mengna, value b: " << &m.b << std::endl;


	std::cout << "Struct Peiyun: " << &s <<  ", size of Seed is " << sizeof(s) << std::endl;
	std::cout << "From struct Peiyun, value a: " << &s.a << std::endl;
	std::cout <<"From struct Peiyun, value b: " <<&s.b << std::endl;
	std::cout << "From struct Peiyun, value fml: " << &s.fml << std::endl;
	*/

// Ask (the smart) Chris on wed


	std::cout << std::endl;
	char  seed[] = "cao ni ma";
	//char seed[] = { 'c','a','o',' ','n', 'i', ' ' , 'm', 'a' };

	char * ptr = seed;
	std::cout << &ptr[2] << std::endl;

	
	for (int i = 0; i < 9; i++){
		std::cout << static_cast<void*>(&seed[i]) << " : " << seed[i] << std::endl;
		std::cout << *ptr << std::endl;
		ptr++;
	}
	
	
	return 0;
}

