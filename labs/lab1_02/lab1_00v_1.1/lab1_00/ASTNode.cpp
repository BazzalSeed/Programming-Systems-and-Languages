#include"stdafx.h"
#include "ASTnode.h"

ASTNode::ASTNode(std::string s, shared_ptr<ASTNode> & parent) :name(s), NodeType(Translate(s)), parent(parent)
{

}

ASTNode::~ASTNode()
{
	
}
void ASTNode:: adoptChild(shared_ptr<ASTNode> & n)
{
	children.push_back(n);
}


ASTNodeType ASTNode::Translate(std::string s)
{
	if (s.compare("hornclause") == 0)
	{
		return HORNCLAUSE;
	}	
	if (s.compare("head") == 0)
	{
		return HEAD;
	}
	if (s.compare("body") == 0)
	{
		return BODY;
	}
	if (s.compare("predicate") == 0)
	{
		return PREDICATE;
	}

	if (s.compare("LABEL") == 0)
	{
		return label;
	}
	else
	{
		return number;
	}
}