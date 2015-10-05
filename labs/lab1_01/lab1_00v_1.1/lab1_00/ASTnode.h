#pragma once

#include <deque>
#include <string>
#include <vector>
#include <memory>
#include "token.h"
#include <iostream>

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
	ASTNode(std::string n);
	virtual ~ASTNode();

	void adoptChild();
	void MakeSibling();
	virtual void visit(){};

protected:
	std::string name;
	ASTNodeType NodeType;


private:
	ASTNodeType Translate(std::string s);
};


