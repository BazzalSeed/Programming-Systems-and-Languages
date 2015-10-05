#include "stdafx.h"
#include "BodyAST.h"
#include "PredicateAST.h"

/*Default Constructor*/
Body::Body(std::string name, shared_ptr<ASTNode> & parent) : ASTNode(name,parent)
{

}

Body::~Body()
{

}

/*
This is the visit method for the Body Node. 
In this method we first emit the left paren and then visit all the children. 
Which we expect to be Predicates.
Finally emit the closing right paren.
*/
void Body::visit(set<string>& valid_label, set<unsigned int>& valid_number)
{
	cout << " (";
	for (auto child : children)
	{
		shared_ptr<Predicate>predicate_child = dynamic_pointer_cast<Predicate>(child);
		predicate_child->visit(valid_label,valid_number);
	}

	cout << ")";
}


