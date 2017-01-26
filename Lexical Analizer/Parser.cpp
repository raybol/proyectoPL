#include"Parser.h"

bool parse(const vector<MyString> & statement, int start, int end) {
	if (isOperator(statement[start]) || isOperator(statement[end]))
		return false;
	return isExpression(statement, start, end);
}
bool isCommentStatement(const vector<MyString> & statement) {
	if (statement[0].toLower() == "rem")
		return true;
	return false;
}

bool isAssigmentStatement(const vector<MyString> & statement) {
	return false;
	/*if (isIntVariable(statement[0]) ||
	isRealVariable(statement[0]) ||
	isStringtVariable(statement[0])) {
	if (statement[1] != '=')
	return false;
	}
	else
	return false;
	if (isIntVariable(statement[0])) {

	}
	else if (isRealVariable(statement[0])) {

	}
	else if (isStringtVariable(statement[0])) {

	}

	return isArithmeticExpression(statement);*/

}
bool isPrintStatement(const vector<MyString> & statement) {
	if (statement[0].toLower() == "print") {
		if (statement.size() == 1)
			return true;
		else if (statement.size() == 2)
			if (isVariable(statement[1]) || isRealwExp(statement[1]) || isString(statement[1]))
				return true;
	}
	return false;
}

bool isReadStatement(const vector<MyString> & statement) {
	if (statement[0].toLower() == "read") {
		if (statement.size() == 1)
			return true;
		else if (statement.size() == 2)
			if (isVariable(statement[1]))
				return true;
	}
	return false;
}
bool isIfStatement(const vector<MyString> & statement) { return false; }
bool isEndStatement(const vector<MyString> & statement) { 
	if (statement[0].toLower() == "end.") {
			return true;
	}
	return false;
}

bool isExpression(const vector<MyString> & statement, int start, int end) {
	if (isOperator(statement[start]) || isOperator(statement[end]))
		return false;

	int i = start;
	bool hasOP = false;
	for (i; i < end; i++) {
		if (statement[i].toLower() == ".add." || statement[i].toLower() == ".sub.") {
			hasOP = true;
			break;
		}
	}

	if (hasOP) {
		if (i == start || i == end) {
			cout << "expected an expression un +/- de mas" << endl;
			return false;
		}
		return isExpression(statement, start, i - 1) && isFactor(statement, i + 1, end);
	}
	else {
		if (isOperator(statement[i])) {
			cout << "error 2ops de corrido" << endl;
			return false;
		}

		else
			return isFactor(statement, start, end);
	}
	//return true;
}

bool isFactor(const vector<MyString> & statement, int start, int end) {
	if (isOperator(statement[start]) || isOperator(statement[end]))
		return false;
	bool hasOP = false;
	int i = start;
	for (i; i < end; i++) {
		if (statement[i].toLower() == ".mul." || statement[i].toLower() == ".div.") {
			hasOP = true;
			break;
		}
	}

	if (hasOP) {

		if (isStringVariable((statement[i + 1])) || isStringVariable((statement[i - 1])) || isString((statement[i + 1])) || isString((statement[i - 1]))) {
			cout << "opertator: " << statement[i] << " wrong operand data type" << endl;
			return false;
		}

		if (i == start || i == end) {
			cout << "missing operation" << endl;
			return false;
		}

		return isFactor(statement, start, i - 1) && isTerm(statement, i + 1, end);
	}
	else {
		/*	if (isOperator(statement[i + 1])) {
		cout << "error 2ops de corrido" << endl;
		return false;
		}
		else*/
		return isTerm(statement, start, end);
	}
	//return true;
}

bool isTerm(const vector<MyString> & statement, int start, int end) {
	if (isOperator(statement[start]) || isOperator(statement[end]))
		return false;
	if (start < end) {
		if (isArithmeticOperator(statement[1])) {
			return isExpression(statement, start, end);
		}
		else {
			cout << "expected an expression term mal" << endl;
			return false;
		}
	}

	else {
		return isRealwExp(statement[0]) ||
			isIntVariable(statement[0]) ||
			isRealVariable(statement[0]) ||
			isStringVariable(statement[0]) ||
			isString(statement[0]);
	}
}