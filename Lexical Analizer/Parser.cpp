#include"Parser.h"
void printStatement(const vector<MyString> & statement, int end) {
	cout << "ERROR" << endl;
	for (int i = 0; i <= end; i++)
		cout << statement[i] << " ";
	cout << endl;
}

bool parse(const vector<MyString> & statement, int start, int end) {
	if (isOperator(statement[start]) || isOperator(statement[end]))
		return false;
	return isExpression(statement, start, end);
}

bool isCommentStatement(const vector<MyString> & statement,int start,int end) {
	if (statement[start].toLower() == "rem")
		return true;
	return false;
}

bool isAssigmentStatement(const vector<MyString> & statement, int start, int end) {
	if (!(isVariable(statement[start]))) {
		return false;
	}
	if (statement[start+1] != "=") {
		return false;
	}
	return isExpression(statement,  start+2,  end);
}

bool isPrintStatement(const vector<MyString> & statement, int start, int end) {
	if (statement[start].toLower() == "print") {
		if ((end - start) == 1) {
			if (isVariable(statement[start + 1]) || isRealwExp(statement[start + 1]) || isString(statement[start + 1]))
				return true;
		}
		else if (end == start) {
			return true;
		}
	}
	return false;
}

bool isReadStatement(const vector<MyString> & statement, int start, int end) {
	if (statement[start].toLower() == "read") {
		if ((end - start) == 1)
			if (isVariable(statement[start + 1]))
				return true;
	}
	return false;
}

bool isIfStatement(const vector<MyString> & statement, int start, int end) {
	//If
	if (!(statement[start].toLower() == "if")) {
		return false;
	}

	int i = start;
	bool hasThen = false;
	for (i; i < end; i++) {
		if (statement[i].toLower() == "then") {
			hasThen = true;
			break;
		}
	}
	if (!hasThen) {
		printStatement(statement,i);
		cout << "missing then part" << endl;
		return false;
	}
	if (i == end) {
		printStatement(statement, i);
		cout << "missing condition" << endl;
		return false;
	}

	//condition
	if (isConditionalExpression(statement, start + 1, i - 1)) {
		if (statement[i + 1].toLower() == "read") {
			return isReadStatement(statement, i + 1, end);
		}
		else if (statement[i + 1].toLower() == "print") {
			return isPrintStatement(statement, i + 1, end);
		}
		else if (isVariable(statement[i + 1])) {
			return isAssigmentStatement(statement, i + 1, end);
		}
	}

	return false; 
}

bool isEndStatement(const vector<MyString> & statement, int start, int end) {
	if (start == end) {
		if (statement[start].toLower() == "end.") {
			return true;
		}
	}
	return false;
}

bool isConditionalExpression(const vector<MyString> & statement, int start, int end) {
	if (isOperator(statement[end])) {
		printStatement(statement, end);
		cout << "missing operand";
		return false;
	}
	bool hasOp = false;
	for (int i = start; i <= end && !hasOp; i++) {
		if (isRelationalOperator(statement[i]) || isLogicalOperator(statement[i])) {
			hasOp = true;
		}			
	}

	if (!hasOp) {
		printStatement(statement, end);
		cout << "missing logical or relation operator";
		return false;
	}
	return isLogicalExpression(statement, start, end);
}


bool isLogicalExpression(const vector<MyString> & statement, int start, int end) {

	bool hasOP = false;
	int i = start;
	//for (it; it != statement.end(); ++it, i++) 
	for (i; i < end; i++) {
		if (statement[i] == ".and." || statement[i] == ".or.") {
			hasOP = true;
			break;
		}
	}

	if (hasOP) {

		return isLogicalExpression(statement, start, i - 1) && isNeg(statement, i + 1, end);
	}
	else {
		return isNeg(statement, start, end);
	}

}

bool isNeg(const vector<MyString> & statement, int start, int end) {

	bool hasOP = false;
	int i = start;
	//for (it; it != statement.end(); ++it, i++) 
	for (i; i < end; i++) {
		if (statement[i] == ".not.") {
			hasOP = true;
			break;
		}
	}

	if (hasOP) {
		return isNeg(statement, i + 1, end);
	}
	else {
		return isEQExpression(statement, start, end);
	}
	return true;
}


bool isEQExpression(const vector<MyString> & statement, int start, int end) {

	bool hasOP = false;
	int i = start;

	for (i; i < end; i++) {
		if (statement[i] == ".eq." || statement[i] == ".ne.") {
			hasOP = true;
			break;
		}
	}

	if (hasOP) {
		return isEQExpression(statement, start, i - 1) && isRelationalexpression(statement, i + 1, end);
	}
	else {
		return isRelationalexpression(statement, start, end);
	}

}

bool isRelationalexpression(const vector<MyString> & statement, int start, int end) {

	bool hasOP = false;
	int i = start;
	//for (it; it != statement.end(); ++it, i++) 
	for (i; i < end; i++) {
		if (statement[i] == ".lt." || statement[i].toLower() == ".le." || statement[i].toLower() == ".gt." || statement[i].toLower() == ".ge.") {
			hasOP = true;
			break;
		}
	}

	if (hasOP) {

		if (isStringVariable((statement[i + 1])) || isStringVariable((statement[i - 1])) || isString((statement[i + 1])) || isString((statement[i - 1]))) {
			printStatement(statement, i);
			cout << "opertator: " << statement[i] << " wrong operand data type" << endl;
			return false;
		}
		/*if (isStringVariable(*(it - 1)) || isString(*(it - 1)) || isStringVariable(*(it + 1)) || isString(*(it + 1)))
		{
			if (!((isStringVariable(*(it - 1)) || isString(*(it - 1))) && (isStringVariable(*(it + 1)) || isString(*(it + 1))))) {
				cout << "logical opertator: " << *it << " wrong operand data type" << endl;
				return false;
			}

		}*/
		return isRelationalexpression(statement, start, i - 1) && isExpression(statement, i + 1, end);
	}
	else {
		return isExpression(statement, start, end);
	}
	return true;
}

bool isExpression(const vector<MyString> & statement, int start, int end) {

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
		/*	if (isOperator(statement[i])) {
				cout << "error 2ops de corrido" << endl;
				return false;
			}

			else*/
		return isFactor(statement, start, end);
	}
	//return true;
}

bool isLogicFactor(const vector<MyString> & statement, int start, int end) {

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
			printStatement(statement, i);
			cout << "opertator: " << statement[i] << " wrong operand data type" << endl;
			return false;
		}

		/*if (i == start || i == end) {
			cout << "missing operation" << endl;
			return false;
		}*/

		return isLogicFactor(statement, start, i - 1) && isLogicTerm(statement, i + 1, end);
	}
	else {
		/*	if (isOperator(statement[i + 1])) {
		cout << "error 2ops de corrido" << endl;
		return false;
		}
		else*/
		return isLogicTerm(statement, start, end);
	}
	//return true;
}
bool isFactor(const vector<MyString> & statement, int start, int end) {

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
			printStatement(statement, i);
			cout << "opertator: " << statement[i] << " wrong operand data type" << endl;
			return false;
		}

		/*if (i == start || i == end) {
			cout << "missing operation" << endl;
			return false;
		}*/

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


bool isLogicTerm(const vector<MyString> & statement, int start, int end) {
	/*if (isOperator(statement[start]) || isOperator(statement[end]))
	return false;*/
	if (start < end) {
		if (isArithmeticOperator(statement[start + 1]) || isRelationalOperator(statement[start + 1]) ||
			statement[start + 1] == ".or." || statement[start + 1] == ".and."
			) {
			return isLogicalExpression(statement, start, end);
		}
		else {
			printStatement(statement, end);
			cout << "missing operand" << endl;
			return false;
		}
	}

	else {
		if (isRealwExp(statement[start]) ||
			isIntVariable(statement[start]) ||
			isRealVariable(statement[start]) ||
			isStringVariable(statement[start]) ||
			isString(statement[start])) {
			return true;
		}
		else {
			printStatement(statement, end);
			cout << "\nerror expected variable" << endl;
			return false;
		}
	}
}

bool isTerm(const vector<MyString> & statement, int start, int end) {
	/*if (isOperator(statement[start]) || isOperator(statement[end]))
		return false;*/
	if (start < end) {
		if (isArithmeticOperator(statement[start + 1]) || isRelationalOperator(statement[start + 1]) ||
			statement[start + 1] == ".or." || statement[start + 1] == ".and."
			) {
			return isExpression(statement, start, end);
		}
		else {
			printStatement(statement, end);
			cout << "missing operand" << endl;
			return false;
		}
	}

	else {
		if (isRealwExp(statement[start]) ||
			isIntVariable(statement[start]) ||
			isRealVariable(statement[start]) ||
			isStringVariable(statement[start]) ||
			isString(statement[start])) {
			return true;
		}
		else {
			printStatement(statement, end);
			cout << "expected variable, string or number" << endl;
			return false;
		}
	}
}