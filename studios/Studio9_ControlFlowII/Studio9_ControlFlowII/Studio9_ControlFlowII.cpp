
#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <future>
#include <algorithm>
#include <numeric>
using namespace std;

int get_value(){
	string s;
	int value;
	cout << "Give me an int moron:  ";
	cin >> s;

	bool aredigits = true;
	for (auto i : s){
		if (!isdigit(i))
			aredigits = false;

	}
	if (aredigits){
		istringstream is(s);
		is >> value;
		return value;
	}
	else{
		cout << "are you as stupid as chris? i need an interger" << endl;
		int value = get_value();
		return value;
	}

}
int get_products(){
	int value1 = get_value();
	int value2 = get_value();
	return value1*value2;
}

bool isEven(int n){
	if (n < 0){
		return false;
	}
	else{
		if (n == 0){
			return true;
		}
		int remainder = n % 2;
		if (remainder != 0){
			return false;
		}
		else{
			isEven(n / 2);
			return true;
		}

	}
}
void givemeEven(){
	cout << "Give me an even number to escape the infinite loop" << endl;
	int value = get_value();
	if (isEven(value)){
		return;
	}
	else{
		cout << "Are you as stupid as Chris?" << endl;
		givemeEven();
	}
}

unsigned long DP_factorial(unsigned long n){

	cout << "DP calculating " << n << endl;
	if (n < 0){
		return -1;
	}
	if (n == 0){
		return 1;
	}
	else{
		vector<int>fac(n+1,0);
		fac[0] = 1;
		for (unsigned long i = 1; i < n + 1;i++){
			fac[i] = i*fac[i - 1];
		}
		return fac[n];
	}
	

}

unsigned long rec_factorial(unsigned long n){
	cout <<"recursive calculating"<< n << endl;
	if (n == 1){
		return 1;
	}
	else{
		return n*rec_factorial(n - 1);
	}
}
int main(int argc, char* argv[])
{


	/*
	//Question 2
	int product = get_products();
	cout << "The product is: " << product << endl;
	return 0;
	*/

	
	/*
	//QUestion 3
	
	while (true){
		cout << "Give me an even number to escape the infinite loop" << endl;
		int value = get_value();
		if (isEven(value)){
			break;
		}
		else{
			cout << "Are you as stupid as Chris?" << endl;
		}
	}
	
	*/
	/*
	//Question4
	givemeEven();
	*/
	
	/*
	//QUestion 5
	int x, y, z;
	async(DP_factorial, 10);
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	async(DP_factorial, 5);
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	async(DP_factorial, 3);
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	*/
	
	
	int x = 1;
	int y = 10;
	int z = 3;

	future<unsigned long> answer_for_x = std::async(DP_factorial, x);
	future<unsigned long> answer_for_y = std::async(rec_factorial, y);
	future<unsigned long> answer_for_z = std::async(DP_factorial, z);

	int fx = answer_for_x.get();
	int fy = answer_for_y.get();
	int fz = answer_for_z.get();
	
	

	}

