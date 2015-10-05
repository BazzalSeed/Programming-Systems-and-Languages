// Studio1-Intro.cpp : Defines the entry point for the console application.
#pragma once
#include "stdafx.h"
#include <iostream>
#include "Adder.h"
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	
	cout << "Hello, World!" << endl;
	const int chris = 2;
	const int seed = 3;
	int sum = 0;
	//sum = chris + seed;
	Adder a(sum);
	a(chris);
	a(seed);
	cout << "chris(Wang Jiji): " << chris << endl;
	cout << "seed(2b): " << seed << endl;
	a.printOut();
	
	/*
	int sum = 6;
	Adder a(sum);

	
	std::vector<int> vec;
	vec.push_back(2);
	std::cout << vec[0] << std::endl;
	//a.printOut();
	for_each(vec.begin(), vec.end(), a);
	a.printOut();
	*/
	return 0;
}

