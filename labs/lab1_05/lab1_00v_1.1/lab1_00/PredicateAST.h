/*
This is the predicate node.
The parent of this node is expected to be either body or head.
The children of this node are Label or Number Nodes.
*/
#pragma once
#include "ASTnode.h"


class Terminals;

class Predicate : public ASTNode
{
public:
	Predicate(std::string s, shared_ptr<ASTNode> & parent);
	~Predicate();
	void visit(set<string>& valid_label, set<unsigned int>& valid_number);
	
};