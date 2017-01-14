#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"MyString.h"
using namespace std;
bool isUnsignedInteger(const char *cadena);
bool isInteger(const char *cadena);
bool isReal(const char *cadena);
bool isRealwExp(const char *cadena);
bool isKeyWord(const char *cadena); 
bool isAssignment(const char *cadena);
bool isRelationalOperator(const char *cadena);
bool isLogicalOperator(const char *cadena);
bool isVariable(const char *cadena);
bool isString(const char *cadena);
bool isArithmeticOperator(const char *cadena);
vector<MyString> tokenizer(const MyString & statement);