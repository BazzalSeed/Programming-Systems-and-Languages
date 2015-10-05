#pragma once
#include "token.h"

struct Number : public Token{

	unsigned int value;
	Number(const string & s);
	~Number(){};
	virtual unsigned int getvalue();

};