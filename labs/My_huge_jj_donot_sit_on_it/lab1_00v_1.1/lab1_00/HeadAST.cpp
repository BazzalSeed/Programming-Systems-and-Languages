/*
Definitions for Head(node) ASTNode-derived class
Notice that used initializer list for constructor
*/
#include "stdafx.h"
#include "HeadAST.h"
#include "PredicateAST.h"

Head::Head(std::string name, shared_ptr<ASTNode> & parent) : ASTNode(name, parent)
{

}

Head::~Head()
{
	
}
/*
Overriding visit method for head node
*/

void Head::visit(set<string>& valid_label, set<unsigned int>& valid_number)

{
	

	//dynamic cast pointer to base class to correct sublcass to invoke the proper visit method
	
	for (auto child : children)
	{   
		shared_ptr<Predicate>predicate_child = dynamic_pointer_cast<Predicate>(child);
		predicate_child->visit(valid_label,valid_number);
	}
	
}

