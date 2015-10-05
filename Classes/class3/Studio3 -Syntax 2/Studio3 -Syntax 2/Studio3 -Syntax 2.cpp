// Studio3 -Syntax 2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>

void Parse(std::string s, std::vector<std::string> & vec);
void PrintOut(const std::vector<std::string> & vec);
bool CheckPlus(const std::string & s);
bool CheckInt(const std::string & s);
bool CheckLeftPa(const std::string &s);
bool CheckRightPa(const std::string &s);
bool CheckComma(const std::string &s);
bool CheckLabel(const std::string &s);

std::vector<std::vector<std::string>, std::vector<std::string>> ScanString(std::vector<std::string> &  vec);
void PrintNum(const std::vector<std::string> & vec);
void PrintPlus(const std::vector<std::string> & vec);
int PrefixAdd(std::vector<std::string> v, int & curr, int last, int & index);

enum MyEnum
{
	FUCK_YOU = -9999, not_valid

};

int main(int argc, char * argv[])
{
	int valid_index = 0;
	int curr = 0;

	std::ifstream file("test.txt");
	std::string s;
	std::vector<  std::vector<std::string>  > ChrisJJ;
	std::vector<  std::vector<std::string>  > valid;
	std::vector<  std::vector<std::string>  > invalid;
	if (file.is_open())
	{
		while (std::getline(file, s))
		{
			std::vector<std::string> string_vec;
			Parse(s, string_vec);

			ChrisJJ.push_back(string_vec);

			/*
			Parse(s, string_vec);
			try
			{
				PrefixAdd(string_vec, curr, string_vec.size() - 1, valid_index);
				valid.push_back(string_vec);
			}

			catch (...)

			{
				auto begin = string_vec.begin() + valid_index + 1;
				auto end = string_vec.end();

				std::vector<std::string> newvec(begin, end);
				invalid.push_back(newvec);

			}
			string_vec.clear();
			*/
		}

		std::cout << "Raw Parsing" << std::endl;
		for (size_t i = 0; i < ChrisJJ.size(); i++)
		{
			std::cout << "number " << i + 1 << "---" << std::endl;
			PrintOut(ChrisJJ[i]);
			std::cout << "-------------" << std::endl;
		}


		/*
		std::cout << "VALID FUCKIN SHIT" << std::endl;
		for (size_t i = 0; i < valid.size(); i++)
		{
			std::cout << "number " << i + 1 << "---" << std::endl;
			PrintOut(valid[i]);
			std::cout << "-------------" << std::endl;
		}
		std::cout << "INVALID FUCKIN SHIT" << std::endl;
		for (size_t i = 0; i < invalid.size(); i++)
		{
			std::cout << "number " << i + 1 << "---" << std::endl;
			PrintOut(invalid[i]);
			std::cout << "-------------" << std::endl;
		}
		*/

	}
	file.close();
	//PrintOut(string_vec);
	//PrintNum(string_vec);
	//PrintPlus(string_vec);
	return 0;
}

void Parse(std::string s, std::vector<std::string> & vec)
{
	std::stringstream iss(s);
	std::string temp;
	while (iss >> temp)
	{
		//std::cout << "check label result: " << CheckLabel(temp);
		if (CheckPlus(temp) || CheckInt(temp) || CheckLeftPa(temp) || CheckRightPa(temp) || CheckComma(temp) || CheckLabel(temp)){
		vec.push_back(temp);
		std::cout << "haha" << std::endl;
	}
		

	}
	return;
}

void PrintOut(const std::vector<std::string> & vec)
{
	for (auto ele : vec)
	{
		std::cout << ele << std::endl;
	}
}

void PrintPlus(const std::vector<std::string> & vec)
{
	std::cout << "Plus Print Out" << std::endl;
	for (auto ele : vec)
	{
		if (CheckPlus(ele)){ std::cout << ele << std::endl; }
	}
}

void PrintNum(const std::vector<std::string> & vec)
{
	std::cout << "Num(Int) Print Out" << std::endl;
	for (auto ele : vec)
	{
		if (CheckInt(ele)){ std::cout << ele << std::endl; }
	}
}


bool CheckPlus(const std::string & s)
{
	if (s.compare("+") == 0){ return true; }
	return false;
}

bool CheckInt(const std::string & s)
{
	if (int(s.size()) == 0){ return false; };
	for (int i = 0; i < int(s.size()); i++)
	{
		if (s[i] < 48 || s[i] > 57)
		{
			return false;
		}
	}
	return true;
}


bool CheckLeftPa(const std::string &s){
	if (s.compare("(") == 0){ return true; }
	return false;
}
bool CheckRightPa(const std::string &s){
	if (s.compare(")") == 0){ return true; }
	return false;
}
bool CheckComma(const std::string &s){

	if (s.compare(",") == 0){ return true; }
	return false;
}

bool CheckLabel(const std::string &s){
	for (auto str : s)
	{
		if (!(str >= 65 && str <= 122))
		{
			return false;
		}
	}
	return true;
}

int PrefixAdd(std::vector<std::string> v, int & curr, int last, int & index)
{
	if (curr > last)
	{

		throw not_valid;

	}



	if (CheckPlus(v[curr]))
	{
		int first_operand = PrefixAdd(v, ++curr, last, index);
		int second_operand = PrefixAdd(v, curr, last, index);
		int result = first_operand + second_operand;
		std::cout << result << std::endl;
		return result;
	}

	else{
		int result;
		std::istringstream i(v[curr++]);
		i >> result;

		return result;
	}

	throw FUCK_YOU;
}

std::vector<std::vector<std::string>, std::vector<std::string>> ScanString(std::vector<std::string> &  vec)
{
	try
	{


	}
	catch (int i)
	{


	}

	std::string str = "";
	std::vector<std::vector<std::string>, std::vector<std::string>> ret;


	return ret;
}
