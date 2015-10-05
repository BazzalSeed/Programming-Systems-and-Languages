/*
This is the Body Node of our Grammar. 
We expect its children to currently be Predicates.
The parent of this node is expected to be a Hornclause.
*/
#pragma once
#include "ASTnode.h"

class Predicate;


class Body : public ASTNode
{
public:
	Body(std::string s, shared_ptr<ASTNode> & parent);
	~Body();

	void visit(set<string>& valid_label, set<unsigned int>& valid_number);

};
