/*
Defintions for the Number (token) dervied class.
*/
#include"stdafx.h"
#include "NUMBER.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
Number::Number(const string & s) : Token(NUMBER, s)
{
	//not checking whether it is a valid "number" We should then do the possible throw outside
	//Cannot use initializer list here for converting string to int
	istringstream iss (s);
	iss >> value;
	

}
Number::~Number(){

}
unsigned int Number::getvalue()
{
	return value;
}