#pragma once
#include "ASTnode.h"

class Predicate;

class Head : public ASTNode
{
public:
	Head(std::string s, shared_ptr<ASTNode> & parent);
	~Head();

	void visit();

	
};
