#include "stdafx.h"
#include "HeadAST.h"
#include "PredicateAST.h"

Head::Head(std::string name, shared_ptr<ASTNode> & parent) : ASTNode(name, parent)
{

}

Head::~Head()
{
	
}

void Head::visit()
{
	for (auto child : children)
	{   
		shared_ptr<Predicate>predicate_child = dynamic_pointer_cast<Predicate>(child);
		predicate_child->visit();
	}
	
}

