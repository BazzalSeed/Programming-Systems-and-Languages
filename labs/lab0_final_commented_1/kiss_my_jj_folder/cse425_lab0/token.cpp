#include "stdafx.h"
#include "token.h"

Token::Token()
{
	token_type = TOKENS::UNKNOWN;
	token_name = "";
	token_value = "";
	valid_token = false;
}