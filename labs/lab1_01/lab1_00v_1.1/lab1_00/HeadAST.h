#pragma once
#include "ASTnode.h"

class Predicate;

class Head : public ASTNode
{
public:
	Head(std::string s);
	~Head();

	void visit();
	void AdoptSibling(shared_ptr<Head> brother);
	void AdoptLHSChild(shared_ptr<Predicate> predicate_node);
private:

	void VisitSiblings();
	vector<shared_ptr<Head>> siblings;
	vector<shared_ptr<Predicate>> lhs_children;
};
