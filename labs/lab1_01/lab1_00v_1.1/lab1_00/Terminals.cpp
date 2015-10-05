#include "stdafx.h"
#include "TerminalsAST.h"

Terminals::Terminals(std::string s, const Token & t) : ASTNode(s)
{
	token = t;
}

Terminals::~Terminals()
{
	
}

void Terminals::visit()
{
	cout << token.token_value;
}



