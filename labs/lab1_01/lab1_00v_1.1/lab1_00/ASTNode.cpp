#include"stdafx.h"
#include "ASTnode.h"

ASTNode::ASTNode(std::string s) :name(s), NodeType(Translate(s))
{

}

ASTNode::~ASTNode()
{
	
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