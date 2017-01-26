#pragma once
#include"LexicalAnalizerFunctions.h"
#include<iostream>
#include<string>
#include<vector>
#include"MyString.h"
bool parse(const vector<MyString> & statement, int start, int end);
bool isExpression(const vector<MyString> & statement, int start, int end);
bool isFactor(const vector<MyString> & statement, int start, int end);
bool isTerm(const vector<MyString> & statement, int start, int end);
bool isPrintStatement(const vector<MyString> & statement);
bool isReadStatement(const vector<MyString> & statement);
bool isIfStatement(const vector<MyString> & statement);
bool isEndStatement(const vector<MyString> & statement);
