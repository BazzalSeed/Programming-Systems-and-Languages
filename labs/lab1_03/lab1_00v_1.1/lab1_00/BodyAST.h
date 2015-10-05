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
