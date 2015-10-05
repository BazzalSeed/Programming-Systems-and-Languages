
/*
Definitions for bdoy(node) ASTNode-derived class
Notice that used initializer list for constructor
*/
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
Overriding visit method for hornclause node
*/
void Body::visit(set<string>& valid_label, set<unsigned int>& valid_number)
{
	//dynamic cast pointer to base class to correct sublcass to invoke the proper visit method
	cout << " (";
	for (auto child : children)
	{
		shared_ptr<Predicate>predicate_child = dynamic_pointer_cast<Predicate>(child);
		predicate_child->visit(valid_label,valid_number);
	}

	cout << ")";
}


