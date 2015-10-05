// Studio6_Semantic_Analysis.cpp : Defines the entry point for the console application.
//


//Need Question 5
#include "stdafx.h"
#include "Complex.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>

using namespace std;
int main(int argc, char* argv[])
{
	/*
	//Questio 1 - 3

	Complex chris(1, 1);
	Complex seed(2, 5);
	Complex mengna;
	cout << "Constructions" << endl;
	cout << chris << endl;
	cout << seed << endl;
	cout << mengna << endl;
	cout << "Mulp and Addition" << endl;
	cout <<"chris * Seed: "<< chris*seed << endl;
	cout << "Chris + seed: " << chris + seed << endl;

	
	*/

	
	/*
	//Question 4
	
	vector<int> vec;
	for (int i = 0; i < argc ; i++){
		if (isdigit(*argv[i]) ){
			vec.push_back(atoi(argv[i]));
		}
	}

	for (auto i : vec){
		cout << i << endl;
	}
	//parsing the vec
	vector< tuple<double,double> > vector_tuple;
	int position = 0;
	int i = 0;
	
	while(i <= vec.size()){
		
		if ( (i + 1) <= (vec.size() - 1) ){
			tuple<double, double> complex = make_tuple(vec[i]+0.00, vec[i + 1]+0.00);
			vector_tuple.push_back(complex);
			i = i + 2;
		}
		else{
			
			i++;
		}
	}
	vector<Complex> vec_Complex;
	
	for (int i = 0; i < vector_tuple.size(); i++){
		double x = get<0>(vector_tuple[i]);
		double y = get<1>(vector_tuple[i]);
		Complex newComplex = Complex(x, y);
		vec_Complex.push_back(newComplex);
		
	}
	for (Complex i : vec_Complex){
		cout << i << endl;

	}
	*/

	
	//Question 5
	vector<int> vec;
	vector< tuple<double, double> > vector_tuple;
	vector<Complex> vec_Complex;
	vector<char*> addOperation_vector;
	vector<tuple<double, double>> addoperation_reductionStack;

	for (int i = 0; i < argc; i++){
		if (isdigit(*argv[i])){
			vec.push_back(atoi(argv[i]));
		}
		else if (*argv[i] == '+' || *argv[i] == '*'){
			addOperation_vector.push_back( argv[i]);
		}
	}
	
	for (auto i : vec){
		cout << i << endl;
	}
	
	int position = 0;
	int i = 0;

	while (i <= vec.size()){

		if ((i + 1) <= (vec.size() - 1)){
			tuple<double, double> complex = make_tuple(vec[i] + 0.00, vec[i + 1] + 0.00);
			vector_tuple.insert(vector_tuple.begin(),complex);
			i = i + 2;
		}
		else{

			i++;
		}
	}
	
	for (int i = 0; i < vector_tuple.size(); i++){
		double x = get<0>(vector_tuple[i]);
		double y = get<1>(vector_tuple[i]);
		Complex newComplex = Complex(x, y);
		vec_Complex.push_back(newComplex);

	}


	cout << "Testing builidng of the two vectors" << endl;
	for (auto i : vec_Complex){
		cout << i << endl;
	}
	for (auto i : addOperation_vector){
		cout << i << endl;
	}
	cout << "=====================================" << endl;
	for (auto i : addOperation_vector){
		if (*i == '+'){
			try{
				if (vec_Complex.empty()){

					cout << "not a valid fking thing dumbass" << endl;
					return -1;
				}
				Complex add1 (vec_Complex.back());
				vec_Complex.pop_back();
				if (vec_Complex.empty()){

					cout << "not a valid fking thing dumbass" << endl;
					return -1;
				}
				Complex add2 (vec_Complex.back());
				vec_Complex.pop_back();

				cout << "seed is here: " << vec_Complex.size() << endl;

				Complex newComplex(add1 + add2);
				vec_Complex.push_back(newComplex);
			}
			catch (...){
				cout << "not a valid fking thing dumbass" << endl;
				return -1;
			}
		}
		else{
			try{
				if (vec_Complex.empty()){

					cout << "not a valid fking thing dumbass" << endl;
					return -1;
				}
				Complex mul1(vec_Complex.back());
				vec_Complex.pop_back();
				if (vec_Complex.empty()){

					cout << "not a valid fking thing dumbass" << endl;
					return -1;
				}
				Complex mul2(vec_Complex.back());
				vec_Complex.pop_back();
	
				
				Complex newComplex(mul1 * mul2);
				vec_Complex.push_back(newComplex);
			}
			catch (...){
				cout << "not a valid fking thing dumbass" << endl;
				return -1;
			}
		}
	}

	try{
		cout << "final result: " << vec_Complex.back() << endl;
	}
	catch (...){
		cout << "Chris is a jackass" << endl;
		return -1;
	}
	
}

