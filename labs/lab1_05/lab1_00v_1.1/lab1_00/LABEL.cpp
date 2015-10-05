/*
 definitions for the Label (token) derived class 
*/
#include"stdafx.h"
#include "LABEL.h"
Label::Label(const string & s)
: Token(LABEL, s)
{


}
Label::~Label()
{

}
string Label::getstring(){
	return token_value;
}