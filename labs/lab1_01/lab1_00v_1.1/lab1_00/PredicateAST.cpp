#include "stdafx.h"
#include "TerminalsAST.h"
#include "PredicateAST.h"

Predicate::Predicate(std::string s) : ASTNode(s)
{

}

Predicate::~Predicate()
{

}

void Predicate::visit()
{
	cout << "( ";
	for (auto term_ : terminals)
	{
		term_->visit();
		std::cout << " ";
	}
	cout << ")";
}
void Predicate::AdoptTerminal(shared_ptr<Terminals> term)
{
	terminals.push_back(term);
}
