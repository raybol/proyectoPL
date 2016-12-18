#pragma once
#include<iostream>
#include<string>
#include"MyString.h"
using namespace std;
bool isUnsignedInteger(const char *cadena);
bool isInteger(const char *cadena);
bool isReal(const char *cadena);
bool isRealwExp(const char *cadena);
bool isKeyWord(const char *cadena); 
bool isAssigment(const char *cadena);
bool isRelationalOperator(const char *cadena);
bool isLogicalOperator(const char *cadena);
