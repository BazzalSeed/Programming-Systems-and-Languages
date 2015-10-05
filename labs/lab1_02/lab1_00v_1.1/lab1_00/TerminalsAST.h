#include "ASTnode.h"


class Terminals : public ASTNode
{
public:
	Terminals(std::string s, const Token  & t, shared_ptr<ASTNode> & parent);
	~Terminals();

	void visit(vector<Token> &leaves);

private :
	Token token;
};

