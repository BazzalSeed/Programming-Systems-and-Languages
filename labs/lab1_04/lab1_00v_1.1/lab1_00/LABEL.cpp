/*
Function definitions for the Label. 
*/
#include"stdafx.h"
#include "LABEL.h"
Label::Label(const string & s)
: Token(LABEL, s)
{


}
string Label::getstring(){
	return token_value;
}