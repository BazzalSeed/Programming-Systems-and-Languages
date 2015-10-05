#include "ASTnode.h"


class Terminals : public ASTNode
{
public:
	Terminals(std::string s, const Token  & t);
	~Terminals();

	void visit();

private :
	Token token;
};

