#pragma once
#include <string>

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
	TOKENS token_type;
	std::string token_name;
	std::string token_value;
	bool valid_token;
};