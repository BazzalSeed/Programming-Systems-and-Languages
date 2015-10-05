#pragma once
#include "ASTnode.h"

class Predicate;


class Body : public ASTNode
{
public:
	Body(std::string s);
	~Body();

	void visit();
	void AdoptSibling(shared_ptr<Body> brother);
	void AdoptLHSChild(shared_ptr<Predicate> predicate_lhs);
	void AdoptRHSChild(shared_ptr<Predicate> predicate_rhs);
private:


	void VisitSiblings();
	void Body::visitSib();

	vector<shared_ptr<Body>> siblings;
	vector<shared_ptr<Predicate>> lhs_children;
	vector<shared_ptr<Predicate>> rhs_children;
};
