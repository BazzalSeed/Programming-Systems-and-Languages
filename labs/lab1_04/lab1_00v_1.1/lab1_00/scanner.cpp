#include "stdafx.h"
#include "scanner.h"
#include  <sstream>

/*
Default Constructor
1. Sets the peek index equal to -1 since we want to look at index 0 first
2. Sets the index used to iterate through the array equal to 0 as well
*/
Scanner::Scanner(std::ifstream & r) : iof(r)
{
	start_index = valid_index = StartIndex::ARRAY_START_INDEX;
	index = StartIndex::PEEK_START_INDEX;
}

/*
Deconstructor does nothing in this case
*/
Scanner::~Scanner()
{
}

/*
Check
1. whether the file is open
2. whether it is at the end of the file
*/
bool Scanner::CanRead()
{
	return iof.is_open() && !(iof.eof()) ? true : false;
}

/*
Extraction Operator
checking the incoming token is valid or not. If valid, set the label and boolean value
*/
Scanner & Scanner::operator>> (Token & t)
{
	std::string temp;
	if (iof >> temp)
	{
		SetToken(t, temp);
	}
	return *this;
}

/*
Peek
Looks one token ahead and returns that token
*/
Token Scanner::Peek()
{
	int check = index + 1;
	if (check < int(token_stream.size()))
	{
		return *(token_stream[check]);
	}
	throw ARRAY_OUT_OF_BOUNDS;
}

/*
Advances our position in the array
*/
void Scanner::Advance()
{
	index += 1;
}

/*
PrintsOut whenever we see a valid token
*/
void Scanner::PrintOut(std::ostream & os, std::vector< vector<shared_ptr<Token> > > & valid_vectors) 
{
	if (valid_index <= start_index){ return; }
	std::cout << "<*****Valid Hornclause*****>" << std::endl;
	std::vector< shared_ptr<Token> > vector;
	for (int i = start_index; i < valid_index; i++)
	{
		vector.push_back(token_stream[i]);
		os << token_stream[i]->token_value << " ";
		std::cout << token_stream[i]->token_value << " ";
	}
	os << std::endl;
	valid_vectors.push_back( vector );
	std::cout << std::endl;
	std::cout << "<*****End Valid Hornclause*****>" << std::endl;
	SetStartIndex();
}

/*
Sets the start index to be one plus the current index.
*/
void Scanner::SetStartIndex()
{
	start_index = index + 1;
}

/*
Sets valid_index, the index we will print out up to
*/
void Scanner::SetValidIndex()
{
	valid_index = index + 1;
}

/*
Prints out an error we use less than equal to in order to print UP to
the erroring token.
*/
void Scanner::PrintError()
{
	int end = index + 1;
	if (end >= int(token_stream.size()))
	{
		end = index;
	}
	for (int i = start_index; i <= end; i++)
	{
		std::cout << token_stream[i]->token_value << " ";
	}
	std::cout << std::endl;
}

/*
Adopts the vector of Token Objects
*/
void Scanner::AdoptVector(vector<shared_ptr<Token> > & adopt_vec)
{

	token_stream = adopt_vec;
}

/*
Sets the token
*/
void Scanner::SetToken(Token & t, std::string & s)
{
	std::regex Alpha("[[:alpha:]]+");
	std::regex Digit("[[:digit:]]+");
	if (std::regex_match(s, Alpha))
	{
		t.token_name = "Label";
		t.token_type = TOKENS::LABEL;
		t.token_value = s;
		t.valid_token = true;
		return;
	}
	if (std::regex_match(s, Digit))
	{
		t.token_name = "Digit";
		t.token_type = TOKENS::NUMBER;
		t.token_value = s;
		t.valid_token = true;
		return;
	}
	if (s.compare("^") == 0)
	{
		t.token_name = "And";
		t.token_type = TOKENS::AND;
		t.token_value = s;
		t.valid_token = true;
		return;
	}
	if (s.compare(":-") == 0)
	{
		t.token_name = "Separator";
		t.token_type = TOKENS::SEPARATOR;
		t.token_value = s;
		t.valid_token = true;
		return;
	}
	if (s.compare("(") == 0)
	{
		t.token_name = "LeftParen";
		t.token_type = TOKENS::LEFTPAREN;
		t.token_value = s;
		t.valid_token = true;
		return;
	}
	if (s.compare(")") == 0)
	{
		t.token_name = "RightParen";
		t.token_type = TOKENS::RIGHTPAREN;
		t.token_value = s;
		t.valid_token = true;
		return;
	}
	if (s.compare(",") == 0)
	{
		t.token_name = "Comma";
		t.token_type = TOKENS::COMMA;
		t.token_value = s;
		t.valid_token = true;
		return;
	}
	t.token_name = "Unknown";
	t.token_type = TOKENS::UNKNOWN;
	t.token_value = s;
	t.valid_token = true;
}

/*
Advances the index and atches the incoming token and if it is not the expected token we throw an error
*/
bool Scanner::Match(TOKENS t)
{
	Advance();
	if (t == token_stream[index]->token_type)
	{
		return true;
	}
	else
	{
		std::cout << "Expected token: " << t << " but recieved token: " << token_stream[index]->token_type << " at position " << index << " delinquent token is " << token_stream[index]->token_value << std::endl;
		throw TOKEN_MISMATCH;
	}
}

/*
Method to check if we reached the end of the token stream
*/
bool Scanner::End()
{
	int pos = int(token_stream.size()) - 1;
	return index >= pos ? true : false;
}

/*
Returns the current index. Encaspualte our varaibles and make the user use a getter and setter.
*/
int Scanner::getindex()
{
	return index;
}