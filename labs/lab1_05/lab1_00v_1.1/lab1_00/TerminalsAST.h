/*
This is the derived class of abstract ASTNode for terminal node(directly contains token)
*/
#pragma once
#include "ASTnode.h"


class Terminals : public ASTNode
{
public:
	Terminals(std::string s, shared_ptr<Token>  & t, shared_ptr<ASTNode> & parent);
	~Terminals();

	void visit(set<string>& valid_label, set<unsigned int>& valid_number);

private :
	shared_ptr<Token> token;
};

