#pragma once 
#include <iostream>
#include <fstream>
#include "token.h"
#include <regex>


/*
type of throws that we use to control the flow of recurision (for LL(1) parser) for two purposes 
1. erroring out the recursion 
2. help to maintain the valid_index (keeping track of the current largets valid hornclause so far)

*/
enum Throws
{
	ARRAY_OUT_OF_BOUNDS,
	INDEX_OUT_OF_BOUNDS,
	TOKEN_MISMATCH,
	FOUND_AND_VALID_HORNCLAUSE
};

enum StartIndex
{
	PEEK_START_INDEX = -1,
	ARRAY_START_INDEX = 0
};

/*
The scanner class are responsible for
# for scanning
0. Take in the stream of characters from the file
1. check whether characters from the file are syntacally correct
2. adopt the valid character and put them into a vector (held by scanner)
-----------------------------------------------------------------------------
# for parsing
0. peek( ) the next character (in the vector) 
1. advancing the index (drive the parsing forward)
2. maintain the valid_index and start_index of the current maximum parse tree

*/

class Scanner
{
public:
	Scanner(std::ifstream & r);
	~Scanner();

	void AdoptVector(std::vector<Token> & adopt_vec);
	void PrintOut(std::ostream & os);
	void Advance();
	void SetStartIndex();
	void SetValidIndex();
	void PrintError();

	bool CanRead();
	bool Match(TOKENS t);
	bool End();

	int getindex();

	Token Peek();
	Scanner & operator>> (Token & t);




private:

	void SetToken(Token & t, std::string & s);

	std::ifstream & iof;
	std::vector<Token> token_stream;

	int index;
	int start_index;
	int valid_index;
};