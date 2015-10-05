/*
This is the derived class of abstract ASTNode for head node
*/
#pragma once
#include "ASTnode.h"

class Predicate;

class Head : public ASTNode
{
public:
	Head(std::string s, shared_ptr<ASTNode> & parent);
	~Head();

	void visit(set<string>& valid_label, set<unsigned int>& valid_number);

	
};
