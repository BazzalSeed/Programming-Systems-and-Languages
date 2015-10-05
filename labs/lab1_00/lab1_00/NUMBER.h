#include "token.h"

struct Number : public Token{

	unsigned int value;
	Number(const string & s);


};