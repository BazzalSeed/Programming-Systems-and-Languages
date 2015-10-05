#include "stdafx.h"
#include "TerminalsAST.h"
#include "PredicateAST.h"

Predicate::Predicate(std::string name, shared_ptr<ASTNode> & parent) : ASTNode(name, parent)
{

}

Predicate::~Predicate()
{

}

void Predicate::visit(set<string>& valid_label, set<unsigned int>& valid_number)
{  
	string leftparen = "(";
	if ((parent->NodeType) == BODY){
		leftparen = " ( ";
	}
	cout << leftparen;
	for (auto child : children)
	{
		shared_ptr<Terminals>predicate_child = dynamic_pointer_cast<Terminals>(child);
		predicate_child->visit(valid_label,valid_number);
	}
	string rightparen = ")";
	if ((parent->NodeType) == BODY){
		rightparen = " ) ";
	}
	cout << rightparen;
}
