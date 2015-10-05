#include <iostream>
#include <string>

struct Adder
{
public :
	int & value;
	//int * value = new int[1];
	Adder(int & i)
		:value(i)
	{
	
	};
	//Adder(const int & i){ value = i; }
	void operator() (const int & i) 
	{
		std::cout << "i: "<< i << std::endl;
		value = value + i;
		std::cout << "value: " << value << std::endl;
	}
	void printOut(){ std::cout << "Adder value is: " << value << std::endl; }
private:


};