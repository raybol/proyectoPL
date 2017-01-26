#pragma once
#include"LexicalAnalizerFunctions.h"
#include<iostream>
#include<string>
#include<vector>
#include"MyString.h"
bool parse(const vector<MyString> & statement, int start, int end);
bool isCommentStatement(const vector<MyString> & statement, int start, int end);
bool isAssigmentStatement(const vector<MyString> & statement, int start, int end);
bool isConditionalExpression(const vector<MyString> & statement, int start, int end);
bool isLogicalExpression(const vector<MyString> & statement, int start, int end);
bool isEQExpression(const vector<MyString> & statement, int start, int end);
bool isNeg(const vector<MyString> & statement, int start, int end);
bool isRelationalexpression(const vector<MyString> & statement, int start, int end);
bool isExpression(const vector<MyString> & statement, int start, int end);
bool isFactor(const vector<MyString> & statement, int start, int end);
bool isLogicFactor(const vector<MyString> & statement, int start, int end);
bool isTerm(const vector<MyString> & statement, int start, int end);
bool isLogicTerm(const vector<MyString> & statement, int start, int end);
bool isPrintStatement(const vector<MyString> & statement, int start, int end);
bool isReadStatement(const vector<MyString> & statement, int start, int end);
bool isIfStatement(const vector<MyString> & statement, int start, int end);
bool isEndStatement(const vector<MyString> & statement, int start, int end);
