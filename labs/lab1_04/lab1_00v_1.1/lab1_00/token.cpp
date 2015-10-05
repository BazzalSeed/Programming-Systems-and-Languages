#include "stdafx.h"
#include "token.h"
using namespace std;
Token::Token()
{
	token_type = TOKENS::UNKNOWN;
	token_name = "";
	token_value = "";
	valid_token = false;
}
Token::Token(TOKENS t, const string & s){
	token_type = t;
	token_name = translate(t);
	token_value = s;
	valid_token = false;
}
string Token::translate(const TOKENS & t){
	switch (t)
	{
	case AND:
		return "AND";
		
	case COMMA:
		return "COMMA";
	case LABEL:
		return "LABEL";
	case LEFTPAREN:
		return "LEFTPAREN";
	case NUMBER:
		return 	"NUMBER";
	case RIGHTPAREN:
		return "RIGHTPAREN";
	case SEPARATOR:
		return "SEPERATOR";
	case UNKNOWN:
		return "UNKOWN";

	default:
		return "stfu";
	}

}