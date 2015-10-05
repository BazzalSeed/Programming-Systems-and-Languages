#include "stdafx.h"
#include "HeadAST.h"
#include "PredicateAST.h"

Head::Head(std::string s) : ASTNode(s)
{

}

Head::~Head()
{
	
}

void Head::visit()
{
	for (auto p : lhs_children)
	{
		p->visit();
	}
	VisitSiblings();
}

void Head::AdoptLHSChild(shared_ptr<Predicate> predicate_node)
{
	lhs_children.push_back(predicate_node);
}


void Head::AdoptSibling(shared_ptr<Head> brother)
{
	siblings.push_back(brother);
}

void Head::VisitSiblings()
{
	for (auto ele : siblings)
	{
		ele->visit();
	}
}