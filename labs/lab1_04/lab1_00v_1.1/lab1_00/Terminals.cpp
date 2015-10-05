#include "stdafx.h"
#include "TerminalsAST.h"

Terminals::Terminals(std::string name, shared_ptr<Token> & t, shared_ptr<ASTNode> & parent) : token(t),ASTNode(name, parent)
{

}

Terminals::~Terminals()
{
	
}

void Terminals::visit(set<string>& valid_label, set<unsigned int>& valid_number)
{
	cout <<" "<< token->token_value <<" ";
	if (token->token_type == NUMBER)
	{
		shared_ptr<Number> number_ptr = dynamic_pointer_cast<Number>(token);
		valid_number.insert(number_ptr->getvalue());
	}
	else
	{
		shared_ptr<Label> string_ptr = dynamic_pointer_cast<Label>(token);
		valid_label.insert(string_ptr->getstring());
	}
}



