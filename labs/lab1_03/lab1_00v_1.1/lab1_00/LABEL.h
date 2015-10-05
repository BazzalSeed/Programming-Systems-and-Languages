#pragma once
#include "token.h"

struct Label : public Token
{
	Label(const string & s);
	~Label(){};
	virtual string getstring();

};