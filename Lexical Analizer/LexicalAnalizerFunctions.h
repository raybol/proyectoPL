#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"MyString.h"
using namespace std;
bool isUnsignedInteger(const MyString & cadena);
bool isInteger(const MyString & cadena);
bool isReal(const MyString & cadena);
bool isRealwExp(const MyString & cadena);
bool isKeyWord(const MyString & cadena);
bool isAssignment(const MyString & cadena);
bool isRelationalOperator(const MyString & cadena);
bool isLogicalOperator(const MyString & cadena);
bool isIntVariable(const MyString & cadena);
bool isRealVariable(const MyString & cadena);
bool isStringVariable(const MyString & cadena);
bool isString(const MyString & cadena);
bool isArithmeticOperator(const MyString & cadena);
vector<MyString> tokenizer(const MyString & statement);
bool isRelationalexpression(const vector<MyString> & statement);
bool isExpression(const vector<MyString> & statement);
bool isFactor(const vector<MyString> & statement);
bool isTerm(const vector<MyString> & statement);
bool validation(const vector<MyString> & statement);