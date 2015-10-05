#pragma once
#include "ASTnode.h"


class Terminals;

class Predicate : public ASTNode
{
public:
	Predicate(std::string s);
	~Predicate();
	void visit();
	void AdoptTerminal(shared_ptr<Terminals> term);
private:
	std::vector<shared_ptr<Terminals>> terminals;
};
