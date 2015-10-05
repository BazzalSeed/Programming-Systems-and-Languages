/*
This is the Number struct that inherits from the Token Struct. 
It has no child and is a leaf node.
*/
#pragma once
#include "token.h"


struct Number : public Token
{
	unsigned int value;
	Number(const string & s);
	~Number();
	virtual unsigned int getvalue();

};