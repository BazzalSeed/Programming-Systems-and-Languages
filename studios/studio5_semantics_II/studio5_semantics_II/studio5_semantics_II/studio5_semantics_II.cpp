// studio5_semantics_II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int global_int = 18;

int main(int argc, char * argv[])
{
	//int local_int = 28;
	//int * ptr = new int;
	//int ptr_value = 20;
	//*ptr = ptr_value;
	/*
	std::cout << "Global int: " << global_int << std::endl;
	std::cout << "Local int: " << local_int << std::endl;
	std::cout << "Pointer value: "<< *ptr << std::endl;
	*/
	/*
	std::cout << "Global int address: " << &global_int << std::endl;
	std::cout << "Local int address: " << &local_int << std::endl;
	std::cout << "Pointer value address: " << ptr << std::endl;

	int stack_to_global = sizeof(int)* (&local_int - &global_int);
	int heap_to_global  = sizeof(int)* (ptr - &global_int);
	int Heap_to_stack   = sizeof(int)* (ptr - &local_int);
	
	std::cout << "Distance of Local int -  Global int: " << stack_to_global << std::endl;
	std::cout << "Distance of Ptr - Global int: " << heap_to_global << std::endl;
	std::cout << "Distance of Heap - Stack: " << heap_to_global << std::endl;
	*/



	//Question 4
	/*
	int * ptr_1 = &global_int;
	int * ptr_2 = ptr; 
	int * ptr_3 = &local_int;

	*ptr_2 = *ptr;
	
	delete ptr;
	delete ptr_1;
	delete ptr_2;
	delete ptr_3;
	*/

	int a = 4;
	int b = 9;
	int * ptr = &a;
	int * test = new int(2);
	
	std::cout << "The address pointer points to is: " << ptr << " the value is " << *ptr << std::endl;
	a = 5;
	std::cout << "The address pointer points to is: " << ptr << " the value is " << *ptr << std::endl;

	ptr = &b;
	std::cout << "The address pointer points to is: " << ptr << " the value is " << a << std::endl;

	std::cout << "The address pointer points to is: " << ptr << " the value is " << b << std::endl;

	return 0;
}

