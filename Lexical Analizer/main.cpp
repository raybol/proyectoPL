
#include<iostream>
#include<string>
#include<vector>
#include"MyString.h"
#include"LexicalAnalizerFunctions.h"
#include"Parser.h"
using namespace std;
int main() {

	vector<MyString> tokens;
	int selection = 0;

	MyString statement,temp;
	do {
		cout << "Enter statement" << endl;
		cin >> statement;
		tokens.push_back(statement);
		tokens = tokenizer(statement);
		int start, end;
		start = 0;
		end = int(tokens.size() - 1);

		if (tokens[0].toLower() == "rem") {
			cout << "comment statement" << endl;
			isCommentStatement(tokens, start, end);
		}
		else if (tokens[0].toLower() == "print") {
			cout << "print statement" << endl;
			isPrintStatement(tokens, start, end);
		}
		else if (tokens[0].toLower() == "read") {
			cout << "read statement" << endl;
			isReadStatement(tokens, start, end);
		}
		else if (tokens[0].toLower() == "if") {
			cout << "if statement" << endl;
			isIfStatement(tokens, start, end);
		}
		else if (tokens[0].toLower() == "end.") {
			cout << "end statement" << endl;
			isEndStatement(tokens, start, end);
		}
		else if (isVariable(statement[start])) {
			cout << "assingment statement" << endl;
			isAssigmentStatement(tokens, start, end);
		}
		else
			cout << "unknown statement" << endl;
		tokens.clear();
		cout << "1 to exit any other to continue"<<endl;
		cin >> selection;
		cout << endl;
	} while (selection != 1);
	return 0;
}