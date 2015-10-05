#include "stdafx.h"

#include "HeadAST.h"
#include "BodyAST.h"
#include "HornClauseAST.h"

Hornclause::Hornclause(std::string s) : ASTNode(s)
{

}

Hornclause::~Hornclause()
{
	
}

void Hornclause::visit()
{
	cout << "( ";
	for (auto h : lhs_children)
	{
		h->visit();
	}
	for (auto b : rhs_children)
	{
		b->visit();
	}
	cout << " )" << endl;
}

void Hornclause::AdoptLHSChild(shared_ptr<Head>  head_node)
{
	lhs_children.push_back(head_node);
}

void Hornclause::AdoptRHSChild(shared_ptr<Body> body_node)
{
	rhs_children.push_back(body_node);
}