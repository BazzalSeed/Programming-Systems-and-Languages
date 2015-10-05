#pragma once
#include <string>
#include <iostream>
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
	TOKENS token_type;
	std::string token_name;
	std::string token_value;
	bool valid_token;
private:
	string translate(const TOKENS & t);

};