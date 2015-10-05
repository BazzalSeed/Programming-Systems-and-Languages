// studio4_semantics_I.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "SymbolTable.h"
using namespace std;



int main(int argc, char* argv[])


{

	Test test = Test();
	//cout << "member int a: " << test.a << endl;
	//cout << "member int b: " << test.b << endl;
	// Question 4
	Attribute a1 = Attribute();
	a1.name = "type";
	a1.info = "int";

	Attribute a2 = Attribute();
	a2.name = "value";

	stringstream ss;
	ss <<argc  ;
	string str = ss.str();
	a2.info = str;

	Attribute a3 = Attribute();
	a3.name = "type";
	a3.info = "array";

	Identifier i1 = Identifier();
	Identifier i2 = Identifier();
	i1.iden = "argc";
	i1.info.push_back(a1);
	i1.info.push_back(a2);

	i2.iden = "argv";
	i2.info.push_back(a3);

	cout << i1 << endl;
	cout << i2 << endl;


	return 0;
}


