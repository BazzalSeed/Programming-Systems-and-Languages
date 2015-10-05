#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
struct Test
{
	Test()
	{

	}
	int a;
	int b;
	void test(){
		a = 0;
		b = 0;
	}


};


struct Attribute
{
	friend std::ostream & operator<<(std::ostream & o, const Attribute & st);
	Attribute(){}
	std::string name;
	std::string info;
	
};


struct Identifier
{
	friend std::ostream & operator<<(std::ostream & o, const Identifier & st);
	Identifier()
	{

	}
	std::string iden;
	std::vector<Attribute> info;


};

class ST
{

	friend std::ostream & operator<<(std::ostream & o, const ST & st);

public:
	ST & operator<<(const Identifier & i)
	{
		vec.push_back(i);
		return *this;
	}
private:
	std::vector<Identifier> vec;
};


//  insertion operator overloads for ostream
std::ostream & operator<<(std::ostream & os, const ST & st)
{

	os << "test" << std::endl;
	return os;
}

std::ostream & operator<<(std::ostream & os, const Attribute & st){

	stringstream a_string;
	a_string << st.name << ":" << st.info << endl;
	string s = a_string.str();

	os << s;
	return os;

}

std::ostream & operator<<(std::ostream & os, const Identifier & st){
	stringstream a_string;
	a_string << "name is: " << st.iden << ";" << "info is: ";
	for (auto i : st.info){
		a_string << i;
	}
	string s = a_string.str();

	os << s << std::endl;
	return os;
}

