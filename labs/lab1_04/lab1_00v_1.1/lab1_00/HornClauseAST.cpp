#include "stdafx.h"

#include "HeadAST.h"
#include "BodyAST.h"
#include "HornClauseAST.h"

Hornclause::Hornclause(std::string name, shared_ptr<ASTNode> & parent) : ASTNode(name, parent)
{

}

Hornclause::~Hornclause()
{
	
}

void Hornclause::visit(set<string>& valid_label, set<unsigned int>& valid_number)
{
	cout << " ( ";
	for (auto child : children)
	{
		if ((child)->NodeType == BODY)  
		{
			shared_ptr<Body>body_child = dynamic_pointer_cast<Body>(child);
			body_child->visit(valid_label,valid_number);
		}
		else
		{
			shared_ptr<Head>head_child = dynamic_pointer_cast<Head>(child);
			head_child->visit(valid_label, valid_number);
		}
	}
	cout << " ) " << endl;
}
