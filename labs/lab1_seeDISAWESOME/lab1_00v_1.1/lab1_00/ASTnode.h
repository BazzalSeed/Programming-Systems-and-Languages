/*
Abstract Node class

This is the base class for all of our Nodes. In addition we have a enum of all the Nodes that are currently in our grammar. 
By implementing our lab in this manner it allows for future abstraction. We can easily add features to our grammar. 
This base class helps make up our Abstract Syntax Tree, with the nodes of the tree being derived classes of this one.
*/

#pragma once

#include <deque>
#include <string>
#include <vector>
#include <set>
#include <memory>
#include <iostream>
#include "token.h"
#include "NUMBER.h"
#include "LABEL.h"

using namespace std;
/*
This an enum of all the Nodes that currently exist in our tree.
Capitalized words are Non-Terminals in our grammar and Lower Case nodes are Terminals.
We make heavy use of this class and reflection within our project to make sure that we provide an
appropriate level of abstraction. This allows us to make functions thate are not heavily dependent upon the 
grammar we are provided. 
*/
enum ASTNodeType
{
	ABSTRACT,
	HORNCLAUSE,
	HEAD,
	BODY,
	PREDICATE,
	label,
	number
};

/*
Abstract class of for all of our nodes. 
the parent node is to deal with the body/head/ node self-recursion 
*/
class ASTNode
{
public:
	ASTNode(std::string s, shared_ptr<ASTNode>  & parent);
	virtual ~ASTNode();

	/*
	We use the Base class to store all of the Derived class's Children. 
	This allows for a greater level of abstraction and allows us to not have to hard code the grammar into each Dervied Class.
	*/
	void adoptChild(shared_ptr<ASTNode> & n);

	/*
	This method is defined by the children. Each Child has different things to print out when being visited.
	Thus it is the responsibilty of the child to print out, and since each child must have a visit method. We
	employ this.
	*/
	virtual void visit() ;
	ASTNodeType NodeType;
	std::string name;
	shared_ptr<ASTNode> parent;
	vector<shared_ptr<ASTNode>>children;

protected:
	ASTNodeType Translate(std::string s);

};


