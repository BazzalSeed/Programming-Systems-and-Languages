// lab1_00.cpp : Defines the entry point for the console application.
//

// cse425_lab0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "scanner.h"
#include "token.h"
#include "LABEL.h"
#include "NUMBER.h"
#include "ASTnode.h"
#include "BodyAST.h"
#include "HeadAST.h"
#include "PredicateAST.h"
#include "TerminalsAST.h"
#include "HornClauseAST.h"
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <set>
using namespace std;
enum ReturnValues{ SUCESS, INCORRECT_ARGS_NUM, INFILE_ERROR, OUTFILE_ERROR, SOMETHING_WENT_WRONG };
enum ExpectedArgs{ ArgNumber = 3 };
std::ifstream in_file;
std::ofstream out_file;

/*
The opps function is used to error out from the recursion ( for LL(1) parser) and prints out useful
erro message
*/
void oops(std::string s, Scanner & scanner, std::string expect)
{

	cout << endl;
	cout << "<-----Error Message----->" << std::endl;
	cout << "From: " << s << " " << scanner.Peek().token_name << " is coming in. Delinquent token is: " << scanner.Peek().token_value << endl;
	cout << "We expected " << expect << std::endl;
	cout << "Production up until error: ";
	scanner.PrintError();
	cout << "<-----End Error Message----->" << std::endl;
	cout << endl;
	throw TOKEN_MISMATCH;
}


/*
A collection of recursive functions to achive the LL(1) parsing (Recursive Descent Parsing) of the horn-clause grammar
Following is the grammar

note: (1) $ is the end of file
(2) This grammar is LL(1) parsable


hornclause --> head x_1 $
x_1        --> SEPERATOR body
|  LAMDA
head       --> predicate x_6
x_6        --> AND head
|  LAMDA
body       --> predicate x_2
x_2        --> AND　body
predicate  --> name x_3
x_3        --> LEFTPAREN x_4
x_4        --> RIGHTPAREN
|  args RIGHTPAREN
name       --> LABEL
args       --> symbol x_5
x_5        --> comma args
|  LAMDA
symbol     --> LABEL
| NUMBER
*/
//Every function corresponds to a non-terminal in the BNF, if statement represents a production the else statement represents an error.
void hornclause(Scanner & s);
void x_1(Scanner & s);
void head(Scanner & s);
//x_6 is made for extra credit
void x_6(Scanner & s);

void body(Scanner & s);
void x_2(Scanner & s);
void predicate(Scanner & s);
void x_3(Scanner & s);
void x_4(Scanner & s);
void name(Scanner & s);
void args(Scanner & s);
void x_5(Scanner & s);
void symbol(Scanner & s);

void hornclause(Scanner & s)
{
	if (s.Peek().token_type == TOKENS::LABEL)
	{
		head(s);
		x_1(s);
	}
	else
	{
		oops("hornclause", s, "LABEL");
	}
}


void x_1(Scanner & s)
{
	if (s.Peek().token_type == TOKENS::SEPARATOR)
	{
		s.Match(TOKENS::SEPARATOR);
		body(s);
	}
	else
	{
		oops("x_1", s, "SEPARATOR");
	}
}

void head(Scanner & s)
{
	if (s.Peek().token_type == TOKENS::LABEL)
	{
		predicate(s);
		x_6(s);
	}
	else
	{
		oops("head", s, "LABEL");
	}
}

void x_6(Scanner & s){

	if (s.Peek().token_type == TOKENS::AND)
	{
		s.Match((TOKENS::AND));
		head(s);
	}
	else if (s.End() || s.Peek().token_type == TOKENS::SEPARATOR)
	{
		return;
	}
	else
	{
		oops("x_6", s, "AND or SEPARATOR");
	}
}

void body(Scanner & s)
{
	if (s.Peek().token_type == TOKENS::LABEL)
	{
		predicate(s);
		x_2(s);
	}
	else
	{
		oops("body", s, "LABEL");
	}
}

void x_2(Scanner & s)
{
	if (s.Peek().token_type == TOKENS::AND)
	{
		s.Match((TOKENS::AND));
		body(s);
	}
	else if (s.End())
	{
		return;
	}
	else
	{
		oops("x_2", s, "AND");
	}
}

void predicate(Scanner & s)
{
	if (s.Peek().token_type == TOKENS::LABEL)
	{
		name(s);
		x_3(s);
	}
	else
	{
		oops("predicate", s, "LABEL");
	}
}


void x_3(Scanner & s)
{
	if (s.Peek().token_type == TOKENS::LEFTPAREN)
	{
		s.Match(TOKENS::LEFTPAREN);
		x_4(s);
	}
	else
	{
		oops("x_3", s, "LEFTPAREN");
	}

}
void x_4(Scanner & s)
{
	if (s.Peek().token_type == TOKENS::RIGHTPAREN)
	{
		s.Match(TOKENS::RIGHTPAREN);
		Token temp_t;
		s.SetValidIndex();
	}
	else if ((s.Peek().token_type == TOKENS::LABEL) || (s.Peek().token_type == TOKENS::NUMBER))
	{
		args(s);
		s.Match(TOKENS::RIGHTPAREN);
		s.SetValidIndex();
	}
	else
	{
		oops("x_4", s, "RIGHTPAREN, LABEL, or NUMBER");
	}
}

void name(Scanner & s)
{
	if (s.Peek().token_type == TOKENS::LABEL)
	{
		s.Match(TOKENS::LABEL);
	}
	else
	{
		oops("name", s, "LABEL");
	}
}

void args(Scanner & s)
{

	if ((s.Peek().token_type == TOKENS::LABEL) || (s.Peek().token_type == TOKENS::NUMBER))
	{
		symbol(s);
		x_5(s);

	}
	else{
		oops("args", s, "LABEL or NUMBER");

	}
}

void x_5(Scanner & s){
	if (s.Peek().token_type == TOKENS::COMMA)
	{
		s.Match(TOKENS::COMMA);
		args(s);
	}
	else if ((s.Peek().token_type == TOKENS::RIGHTPAREN)){
		return;
	}
	else{
		oops("x_5", s, "COMMA or RIGHTPAREN");

	}

}

void symbol(Scanner & s)
{
	if (s.Peek().token_type == TOKENS::LABEL)
	{
		s.Match(TOKENS::LABEL);
	}
	else if (s.Peek().token_type == TOKENS::NUMBER)
	{
		s.Match(TOKENS::NUMBER);
	}
	else
	{
		oops("symbol", s, "LABEL or NUMBER");
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Collection of recursive functions to create the AST 
1. Since we assume we have all valid hornclauses given by the first parsing phase, we donot need to use the scanner to drive the parsing. but 
simply increase the index on our own. So we have to take in a reference to vecotr of shared_ptr to token and a index
2. We create every node on the heap and pass it down the recursive function. Then in proper recursive function, it adpots the newly created node to the proper parent (that is passed down)
3. There are two cases we have to handle carefully
(a) when body goes back to body
(b) head goes back to head
Then when constructing head and body we check if the node is a body/head, we let the parent of the node to adopt the newly constructed node
*/
void _hornclause(vector<shared_ptr<Token> > & vec, shared_ptr<ASTNode> & n, int & index);
void _head(vector<shared_ptr<Token> > & vec, shared_ptr<ASTNode> & n, int & index);
void _predicate(vector<shared_ptr<Token> > & vec, shared_ptr<ASTNode> & n, int & index);
void _name(vector<shared_ptr<Token> > & vec, shared_ptr<ASTNode> & n, int & index);
void _x_3(vector<shared_ptr<Token> > & vec, shared_ptr<ASTNode> & n, int & index);
void _x_4(vector<shared_ptr<Token> > & vec, shared_ptr<ASTNode> & n, int & index);
void _args(vector<shared_ptr<Token> > & vec, shared_ptr<ASTNode> & n, int & index);
void _symbol(vector<shared_ptr<Token> > & vec, shared_ptr<ASTNode> & n , int & index);
void _x_5(vector<shared_ptr<Token> > & vec, shared_ptr<ASTNode> & n, int & index);
void _x_1(vector<shared_ptr<Token>> & vec, shared_ptr<ASTNode> & n, int & index);
void _x_2(vector<shared_ptr<Token>> & vec, shared_ptr<ASTNode> & n, int & index);
void _x_6(vector<shared_ptr<Token> > & vec, shared_ptr<ASTNode> & n, int & index);
void _body(vector<shared_ptr<Token>> & vec, shared_ptr<ASTNode> & n, int & index);

void _hornclause(vector<shared_ptr<Token>> & vec, shared_ptr<ASTNode> & n, int & index)
{
	unsigned int peek = index + 1;
	if (peek >= vec.size())
	{
		throw INDEX_OUT_OF_BOUNDS;
	}
	else if (vec[peek]->token_type == TOKENS::LABEL)
	{
		_head(vec, n , index);
		_x_1(vec, n, index);
	}
}


void _x_1(vector<shared_ptr<Token>> & vec, shared_ptr<ASTNode> & n, int & index)
{
	unsigned int peek = index + 1;
	if (peek >= vec.size())
	{
		throw INDEX_OUT_OF_BOUNDS;
	}
	else if (vec[peek]->token_type == TOKENS::SEPARATOR)
	{
		index += 1;
		_body(vec, n, index);
	}
}



void _body(vector<shared_ptr<Token>> & vec, shared_ptr<ASTNode> & n, int & index)
{
	unsigned int peek = index + 1;
	if (peek >= vec.size())
	{
		throw INDEX_OUT_OF_BOUNDS;
	}
	else if (vec[peek]->token_type == TOKENS::LABEL)
	{
		shared_ptr<ASTNode> adopt_my_sexy_body;
		//Dealing with the recursion by checking what is passed in 
		if (n->NodeType == HORNCLAUSE)
		{
			adopt_my_sexy_body = make_shared<Body>("body", n);
			n->adoptChild(adopt_my_sexy_body);
		}
		else if (n->NodeType == BODY)
		{
			adopt_my_sexy_body = make_shared<Body>("body",n->parent);
			n->parent->adoptChild(adopt_my_sexy_body);
		}
		else
		{
			std::cout << "Something went fucking terribly wrong" << std::endl;
			throw SOMETHING_WENT_WRONG;
		}
		_predicate(vec, adopt_my_sexy_body, index);
		_x_2(vec, adopt_my_sexy_body, index);
	}
}


void _x_2(vector<shared_ptr<Token>> & vec, shared_ptr<ASTNode> & n, int & index)
{
	unsigned int peek = index + 1;
	if (peek >= vec.size())
	{
		return;
		
	}
	else if (vec[peek]->token_type == TOKENS::AND)
	{
		index += 1;
		_body(vec,n,index);;
	}
	else
	{
		return;
	}
}

void _head(vector<shared_ptr<Token> > & vec, shared_ptr<ASTNode> & n, int & index)
{
	unsigned int peek = index + 1;
	if (peek >= vec.size())
	{
		throw INDEX_OUT_OF_BOUNDS;
	}

	//Dealing with the recursion by checking what is passed in 
	else if (vec[peek]->token_type == TOKENS::LABEL)
	{
		shared_ptr<ASTNode> adopt_my_sexy_head;
		if (n->NodeType == HORNCLAUSE)
		{
			adopt_my_sexy_head = make_shared<Head>("head", n);
			n->adoptChild(adopt_my_sexy_head);
		}
		else if (n->NodeType == HEAD)
		{
			adopt_my_sexy_head = make_shared<Head>("head",n->parent);
			n->parent->adoptChild(adopt_my_sexy_head);
		}
		else
		{
			std::cout << "Something went fucking terribly wrong" << std::endl;
			throw SOMETHING_WENT_WRONG;
		}
		_predicate(vec, adopt_my_sexy_head, index);
		_x_6(vec, adopt_my_sexy_head, index);
	}
}

void _x_6(vector<shared_ptr<Token> > & vec, shared_ptr<ASTNode> & n, int & index)
{
	unsigned int peek = index + 1;
	if (peek >= vec.size())
	{
		return;
		//throw INDEX_OUT_OF_BOUNDS;
	}
	else if (vec[peek]->token_type == TOKENS::AND)
	{
		index += 1;
		_head(vec, n, index);
	}
	else if (vec[peek]->token_type == TOKENS::SEPARATOR)
	{
		return;
	}
	else
	{
		return;
	}
}

void _predicate(vector<shared_ptr<Token> > & vec, shared_ptr<ASTNode> & n, int & index)
{
	unsigned int peek = index + 1;
	if (peek >= vec.size())
	{
		throw INDEX_OUT_OF_BOUNDS;
	}
	else if (vec[peek]->token_type == TOKENS::LABEL)
	{
		shared_ptr<ASTNode> adopt_my_sexy_predicate = make_shared<Predicate>("predicate",n);
		n->adoptChild(adopt_my_sexy_predicate);
		_name(vec, adopt_my_sexy_predicate, index);
		_x_3(vec, adopt_my_sexy_predicate, index);
	}
}

void _name(vector<shared_ptr<Token> > & vec, shared_ptr<ASTNode> & n, int & index)
{
	unsigned int peek = index + 1;
	if (peek >= vec.size())
	{
		throw INDEX_OUT_OF_BOUNDS;
	}
	else if (vec[peek]->token_type == TOKENS::LABEL)
	{
		index += 1;
		shared_ptr<ASTNode> adopt_my_sexy_terminal = make_shared<Terminals>("LABEL", (vec[index]),n);
		n->adoptChild(adopt_my_sexy_terminal);
	}
}

void _x_3(vector<shared_ptr<Token> > & vec, shared_ptr<ASTNode> & n, int & index)
{
	unsigned int peek = index + 1;
	if (peek >= vec.size())
	{
		throw INDEX_OUT_OF_BOUNDS;
	}
	else if (vec[peek]->token_type == TOKENS::LEFTPAREN)
	{
		index += 1;
		_x_4(vec, n, index);
	}

}
void _x_4(vector<shared_ptr<Token> > & vec, shared_ptr<ASTNode> & n, int & index)
{
	unsigned int peek = index + 1;
	if (peek >= vec.size())
	{
		throw INDEX_OUT_OF_BOUNDS;
	}
	else if (vec[peek]->token_type == TOKENS::RIGHTPAREN)
	{
		index += 1;
		return;
	}
	else if ((vec[peek]->token_type == TOKENS::LABEL) || (vec[peek]->token_type == TOKENS::NUMBER))
	{
		_args(vec, n, index);
		index += 1;
	}
}

void _args(vector<shared_ptr<Token> > & vec, shared_ptr<ASTNode> & n, int & index)
{
	unsigned int peek = index + 1;
	if (peek >= vec.size())
	{
		throw INDEX_OUT_OF_BOUNDS;
	}
	else if ((vec[peek]->token_type == TOKENS::LABEL) || (vec[peek]->token_type == TOKENS::NUMBER))
	{
		_symbol(vec, n, index);
		_x_5(vec, n, index);
	}
}

void _symbol(vector<shared_ptr<Token> > & vec, shared_ptr<ASTNode> & n, int & index)
{
	unsigned int peek = index + 1;
	if (peek >= vec.size())
	{
		throw INDEX_OUT_OF_BOUNDS;
	}
	else if (vec[peek]->token_type == TOKENS::LABEL)
	{
		index += 1;
		shared_ptr<ASTNode> adopt_my_sexy_terminal = make_shared<Terminals>("LABEL", (vec[index]), n);
		n->adoptChild(adopt_my_sexy_terminal);
	}
	else if (vec[peek]->token_type == TOKENS::NUMBER)
	{
		index += 1;
		shared_ptr<ASTNode> adopt_my_sexy_terminal = make_shared<Terminals>("LABEL", (vec[index]), n);
		n->adoptChild(adopt_my_sexy_terminal);
	}
}

void _x_5(vector<shared_ptr<Token> > & vec, shared_ptr<ASTNode> & n, int & index)
{
	unsigned int peek = index + 1;
	if (peek >= vec.size())
	{
		throw INDEX_OUT_OF_BOUNDS;
	}
	else if (vec[peek]->token_type == TOKENS::COMMA)
	{
		index += 1;
		_args(vec, n, index);
	}
	else if ((vec[peek]->token_type == TOKENS::RIGHTPAREN)){
		return;
	}
}




void HelpMessage(std::string program_name)
{
	std::cout << "usage: " << program_name << " <input_file_name> <output_file_name>" << std::endl;
}


void ErrorCodePrintOut(int num)
{
	switch (num)
	{
	case (INFILE_ERROR + OUTFILE_ERROR) :
	{
											std::cout << "There was an error opening both the input and output files." << std::endl;
											break;
	}
	case INFILE_ERROR:
	{
						 std::cout << "Could not open the provided input file" << std::endl;
						 out_file.close();
						 break;
	}
	case OUTFILE_ERROR:
	{
						  std::cout << "Could not open the provided output file or do not have write permission" << std::endl;
						  in_file.close();
						  break;
	}
	default:
		break;
	}
}

/*
The main driver for
(1) Scanning
(2) Parsing
*/
int OpenIO(std::string input, std::string output)
{
	in_file.open(input);
	out_file.open(output);
	int error_lvl = SUCESS;
	if (!(in_file.is_open()))
	{
		error_lvl += INFILE_ERROR;
	}
	if (!(out_file.is_open()))
	{
		error_lvl += OUTFILE_ERROR;
	}
	if (error_lvl != 0)
	{
		return error_lvl;
	}

	/*
	Scanner first takes in whole string from file stream.
	In each iteration of while loop
	1. we construct a new token object on the heap and use insertion method of scanner to set value 
	2. change it to sub_class pointer if approporiate
	*/
	Scanner s(in_file);
	std::vector<shared_ptr<Token>> token_vec;
	while (s.CanRead())
	{
		shared_ptr<Token> t = make_shared<Token>();
		
		s >> (*t);
		if (t->token_type == LABEL){
			t = make_shared<Label>(t->token_value);
			t->valid_token = true;
		}
		if (t->token_type == NUMBER){
			t = make_shared<Number>(t->token_value);
			t->valid_token = true;
		}

		if (t->valid_token)
		{
			token_vec.push_back(t);
		}
		
	}
	s.AdoptVector(token_vec);
	// The while loop drives the parsing process
	vector<vector<shared_ptr<Token> >> valid_vectors;
	while (!s.End()){
		try
		{
			hornclause(s);
		}
		catch (Throws)
		{

			s.PrintOut(out_file,valid_vectors);
			//This if block is made to deal with the fact that we donot care about lines in the file.
			//So one valid hornclause (Label) come in immediately after another
			if ((!s.End()) && s.Peek().token_type != TOKENS::LABEL)
			{
				s.Advance();
			}
			s.SetStartIndex();
		}
	}
	std::vector<shared_ptr<ASTNode>> tree_vec;
	// The hornclause's parent is an empty ASTNode (cannot directly use nullptr)
	shared_ptr<ASTNode> horn_head;
	for (auto vec : valid_vectors)
	{
		shared_ptr<ASTNode> root = std::make_shared<Hornclause>("hornclause", horn_head);
		try
		{
			int index = StartIndices::PEEK_START_INDEX;
			_hornclause(vec,root,index);
		}
		catch (...)
		{

		}
		tree_vec.push_back(root);
	}

	set<unsigned int>valid_numbers;
	set<string>valid_labels;
	for (auto ele : tree_vec)
	{
		shared_ptr<Hornclause> top_lvl = dynamic_pointer_cast<Hornclause>(ele);
		top_lvl->visit(valid_labels,valid_numbers); 
	}
	cout << "Numbers from valid horn clause" << endl;
	for (auto number : valid_numbers){
		cout << number << endl;
	}
	cout << "Strings from valid horn clause" << endl;
	//cout << valid_strings.size() << endl;

	for (auto label : valid_labels){
		cout << label << endl;
	}
	return error_lvl;
}

int main(int argc, char * argv[])
{
	if (argc != ExpectedArgs::ArgNumber)
	{
		HelpMessage(std::string(argv[0]));
		return INCORRECT_ARGS_NUM;
	}
	int open_ret = OpenIO(std::string(argv[1]), argv[2]);
	if (open_ret != SUCESS)
	{
		ErrorCodePrintOut(open_ret);
		return open_ret;
	}


	in_file.close();
	out_file.close();
	return SUCESS;	
}