#include "stdafx.h"
#include "BodyAST.h"
#include "PredicateAST.h"

Body::Body(std::string name, shared_ptr<ASTNode> & parent) : ASTNode(name,parent)
{

}

Body::~Body()
{

}

void Body::visit()
{
	cout << " (";
	for (auto child : children)
	{
		shared_ptr<Predicate>predicate_child = dynamic_pointer_cast<Predicate>(child);
		predicate_child->visit();
	}

	cout << ")";
}


