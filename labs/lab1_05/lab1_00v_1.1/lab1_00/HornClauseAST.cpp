/*
Definitions for Head(node) ASTNode-derived class
Notice that used initializer list for constructor
*/


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
/*
Overriding visit method for hornclause node

*/
void Hornclause::visit(set<string>& valid_label, set<unsigned int>& valid_number)
{
	cout << " ( ";
	for (auto child : children)
	{	
		//dynamic cast pointer to base class to correct sublcass to invoke the proper visit method
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

