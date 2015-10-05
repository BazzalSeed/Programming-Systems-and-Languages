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


class ASTNode
{
public:
	ASTNode(std::string s, shared_ptr<ASTNode>  & parent);
	virtual ~ASTNode();

	void adoptChild(shared_ptr<ASTNode> & n);
	virtual void visit(){};
	vector<shared_ptr<ASTNode>>children;

	std::string name;
	ASTNodeType NodeType;
	shared_ptr<ASTNode> parent;



	ASTNodeType Translate(std::string s);
};


