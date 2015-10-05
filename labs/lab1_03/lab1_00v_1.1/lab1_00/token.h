#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <memory>
using namespace std;


enum TOKENS
{
	AND,
	COMMA,
	LABEL,
	LEFTPAREN,
	NUMBER,
	RIGHTPAREN,
	SEPARATOR,
	UNKNOWN
};

struct Token
{
public:

	Token();
	Token(TOKENS t, const std::string & s);
	~Token(){};
	TOKENS token_type;
	std::string token_name;
	std::string token_value;
	bool valid_token;
	virtual unsigned int getvalue()
	{ 
	istringstream is(token_value);
	unsigned int i;
	is >> i;
	return i;
	};
	virtual string getstring()
	{
		return token_value; };
private:
	string translate(const TOKENS & t);

};