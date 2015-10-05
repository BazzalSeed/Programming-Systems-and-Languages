/*
Definitions for Predicate(node) ASTNode-derived class 
*/
#include "stdafx.h"
#include "TerminalsAST.h"
#include "PredicateAST.h"

Predicate::Predicate(std::string name, shared_ptr<ASTNode> & parent) : ASTNode(name, parent)
{

}

Predicate::~Predicate()
{

}
/*
Overriding visit method for Predicate node
*/
void Predicate::visit(set<string>& valid_label, set<unsigned int>& valid_number)
{  
	/*This is to deal with the spacing issue. when predicate region follows another predicate region, we donot want the double space.
	So we only give it extra space when we see the parent of this node is a body 
	*/
	string leftparen = "(";
	if ((parent->NodeType) == BODY){
		leftparen = " ( ";
	}
	cout << leftparen;
	//Dynamic cast the pointer to base class to correct sublcass to invoke proper visit method
	for (auto child : children)
	{
		shared_ptr<Terminals>predicate_child = dynamic_pointer_cast<Terminals>(child);
		predicate_child->visit(valid_label,valid_number);
	}
	string rightparen = ")";
	if ((parent->NodeType) == BODY)
	{
		rightparen = " ) ";
	}
	cout << rightparen;
}
