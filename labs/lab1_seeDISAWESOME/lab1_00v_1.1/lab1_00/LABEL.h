/*
This is the Label struct that inherits from the Token Struct.
It has no child and is a leaf node.
*/
#pragma once
#include "token.h"

struct Label : public Token
{
	Label(const string & s);
	~Label();
	virtual string getstring();

};