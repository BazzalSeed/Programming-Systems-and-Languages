#include "stdafx.h"
#include "BodyAST.h"
#include "PredicateAST.h"

Body::Body(std::string name) : ASTNode(name)
{

}

Body::~Body()
{

}

void Body::visit()
{
	cout << "(";
	for (auto p_lhs : lhs_children)
	{
		p_lhs->visit();
	}
	for (auto p_rhs : rhs_children)
	{
		p_rhs->visit();
	}
	VisitSiblings();
	cout << ") ";
}

void Body::visitSib()
{
	for (auto p_lhs : lhs_children)
	{
		p_lhs->visit();
	}
	for (auto p_rhs : rhs_children)
	{
		p_rhs->visit();
	}
	VisitSiblings();
}

void Body::AdoptSibling(shared_ptr<Body> brother)
{
	siblings.push_back(brother);
}

void Body::VisitSiblings()
{
	for (auto ele : siblings)
	{
		ele->visitSib();
	}
}

void Body::AdoptLHSChild(shared_ptr<Predicate> predicate_lhs)
{
	lhs_children.push_back(predicate_lhs);
}
void Body::AdoptRHSChild(shared_ptr<Predicate> predicate_rhs)
{
	rhs_children.push_back(predicate_rhs);
}