
/*
Definitions for AbstractNode(ASTNode) base class
Notice that used initializer list for constructor
*/
#include"stdafx.h"
#include "ASTnode.h"

//Default constructor for the Abstract Node.
ASTNode::ASTNode(std::string s, shared_ptr<ASTNode> & parent) :name(s), NodeType(Translate(s)), parent(parent)
{

}

ASTNode::~ASTNode()
{
	
}

/*
When constructing the tree this method allows us to store the current nodes children. We cast the node
up to its base class, but using reflection we can determine the type of the node when we actually visit it.
*/
void ASTNode:: adoptChild(shared_ptr<ASTNode> & n)
{
	children.push_back(n);
}

/*
Base class has empty visit method. Since this method is vritual all derived classes are expected to define the customized visit method
and we are always constructing subclass .
*/
void ASTNode::visit()
{

}

/*
When we create a node this allows to assign the NodeType.
*/
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