#pragma once
#include "ASTnode.h"

class Body;
class Head;

class Hornclause : public ASTNode
{
public:
	Hornclause(std::string s);
	~Hornclause();
	void visit();
	void AdoptRHSChild(shared_ptr<Body> body_node);
	void AdoptLHSChild(shared_ptr<Head>  head_node);

private:
	vector<shared_ptr<Head>> lhs_children;
	vector<shared_ptr<Body>> rhs_children;
};