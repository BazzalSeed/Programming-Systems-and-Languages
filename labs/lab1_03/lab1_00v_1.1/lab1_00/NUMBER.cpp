#include"stdafx.h"
#include "NUMBER.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
Number::Number(const string & s):Token(NUMBER,s)
{
	//not checking whether it is a valid "number" We should then do the possible throw outside

	istringstream iss (s);
	iss >> value;
	

}

unsigned int Number::getvalue()
{
	return value;
}