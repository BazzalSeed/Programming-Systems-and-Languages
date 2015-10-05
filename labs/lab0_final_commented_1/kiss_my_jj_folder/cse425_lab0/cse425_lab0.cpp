// cse425_lab0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include "scanner.h"
#include "token.h"
using namespace std;
enum ReturnValues{ SUCESS, INCORRECT_ARGS_NUM, INFILE_ERROR, OUTFILE_ERROR };
enum ExpectedArgs{ArgNumber = 3};
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
	else if (s.End() )
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

	Scanner s(in_file);
	std::vector<Token> token_vec;
	while (s.CanRead())
	{
		Token t;
		s >> t;
		if (t.valid_token)
		{
			token_vec.push_back(t);
		}
	}
	s.AdoptVector(token_vec);
	// The while loop drives the parsing process
	while (!s.End()){
		try
		{
			hornclause(s);
		}
		catch (Throws )
		{
			s.PrintOut(out_file);
			//This if block is made to deal with the fact that we donot care about lines in the file.
			//So one valid hornclause (Label) come in immediately after another
			if ((!s.End()) && s.Peek().token_type != TOKENS::LABEL)
			{
				s.Advance();
			}
			s.SetStartIndex();
		}
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