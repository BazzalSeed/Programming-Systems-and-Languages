#pragma once
#include "ASTnode.h"

class Body;
class Head;

class Hornclause : public ASTNode
{
public:
	Hornclause(std::string s, shared_ptr<ASTNode> & parent);
	~Hornclause();
	void visit();
	void adoptChildren(shared_ptr<ASTNode> n);

};