/*
Definitions for terminal(node) ASTNode-derived class
Notice that used initializer list for constructor
*/

#include "stdafx.h"
#include "TerminalsAST.h"

Terminals::Terminals(std::string name, shared_ptr<Token> & t, shared_ptr<ASTNode> & parent) : token(t),ASTNode(name, parent)
{

}

Terminals::~Terminals()
{
	
}

/*
Overriding visit method for terminal node
*/
void Terminals::visit(set<string>& valid_label, set<unsigned int>& valid_number)
{
	cout <<" "<< token->token_value <<" ";


	//Puts string and number contained in the leaf nodes to corresponding vectors
	if (token->token_type == NUMBER)
	{
		//dynamic cast to correct pointer to subclass to invoke the correct subclass method
		shared_ptr<Number> number_ptr = dynamic_pointer_cast<Number>(token);
		valid_number.insert(number_ptr->getvalue());
	}
	else
	{
		//dynamic cast to correct pointer to subclass to invoke the correct subclass method
		shared_ptr<Label> string_ptr = dynamic_pointer_cast<Label>(token);
		valid_label.insert(string_ptr->getstring());
	}
}



