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

void Hornclause::visit()
{
	cout << " ( ";
	for (auto child : children)
	{
		if ((child)->NodeType == BODY)  {
			shared_ptr<Body>body_child = dynamic_pointer_cast<Body>(child);
			body_child->visit();
		}
		else{
			shared_ptr<Head>head_child = dynamic_pointer_cast<Head>(child);
			head_child->visit();
		}
	}
	cout << " ) " << endl;
}

