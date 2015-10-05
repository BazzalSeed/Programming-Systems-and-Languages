#include "stdafx.h"
#include "TerminalsAST.h"

Terminals::Terminals(std::string name, const Token & t, shared_ptr<ASTNode> & parent) : ASTNode(name, parent)
{
	token = t;
}

Terminals::~Terminals()
{
	
}

void Terminals::visit(vector<Token> & leaves)
{
	cout <<" "<< token.token_value<<" ";
	leaves.push_back(token);
}



