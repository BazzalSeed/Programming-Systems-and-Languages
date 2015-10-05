#include <deque>
#include <string>
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

	void adoptChild(ASTNode node);
	void MakeSibling(ASTNode node);
	virtual void visit(){};

protected:
	std::string name;
	ASTNodeType NodeType;
	std::deque<ASTNode*> children;
	std::deque<ASTNode*> sibiling;

private:
	ASTNodeType Translate(std::string s);
};


class Hornclause : public ASTNode
{
public:
	Hornclause(std::string s)
		:ASTNode(s)
	{

	}

	void visit(){
		cout << "(";
		for (auto i : children){
			i->visit();
		}
		cout << ")" << endl;
	}
};

class Head : public ASTNode
{
public:
	Head(std::string s)
		:ASTNode(s)
	{

	}

	void visit(){
		
		for (auto i : children){
			i->visit();
		}
	}
};


class Body : public ASTNode
{
public:
	Body(std::string s)
		:ASTNode(s)
	{

	}
	void visit(){
		cout << "(";
		for (auto i : children){
			i->visit();
		}
		cout << ")" << endl;
	}
};


class Predicate : public ASTNode
{
public:
	Predicate(std::string s)
		:ASTNode(s)
	{

	}

	void visit(){
		cout << "(";
		for (auto i : children){
			i->visit();
		}
		cout << ")" << endl;
	}

};



class Label : public ASTNode
{
public:

	
	Token token;
	Label(std::string s, const Token & t)
		:ASTNode(s)
	{
		token = t;
	}

	void visit(){
		cout << token.token_value;
	}
	

};


class Number : public ASTNode
{
public:
	Token token;
	Number(std::string s, const Token & t)
		:ASTNode(s)
	{
		token = t;
	}
	void visit(){
		cout << token.token_value;
	}
};