
#include<iostream>
#include<string>
#include"MyString.h"
#include"LexicalAnalizerFunctions.h"
using namespace std;
int main() {
	double x = 4.e5;
	char string[40];
	int conitnuar = 0;
	while (conitnuar != 1) {
		cout << "word: ";
		cin >> string;
		if (isKeyWord(string)) {
			cout << "valid" << endl;
			cout << "keyword" << endl << endl;
		}
		else if (isLogicalOperator(string))
		{
			cout << "valid" << endl;
			cout << "logical operator" << endl << endl;
		}
		else if (isRelationalOperator(string))
		{
			cout << "valid" << endl;
			cout << "relational operator" << endl << endl;
		}
		else if (isArithmeticOperator(string))
		{
			cout << "valid" << endl;
			cout << "arithmetic operator" << endl << endl;
		}
		else if (isVariable(string))
		{
			cout << "valid" << endl;
			if ((string[0] >= 'A' && string[0] <= 'F') || (string[0] >= 'a' && string[0] <= 'f'))
				cout << "integer " ;
			else if ((string[0] >= 'G' && string[0] <= 'N') || (string[0] >= 'g' && string[0] <= 'n'))
				cout << "real " ;
			else if ((string[0] >= 'O' && string[0] <= 'Z') || (string[0] >= 'o' && string[0] <= 'z'))
				cout << "string " ;
			cout << "variable" << endl;
			cout << endl;
		}
		else if (isAssignment(string))
		{
			cout << "valid" << endl;
			cout << "assingment operator" << endl << endl;
		}
		else if (isUnsignedInteger(string))
		{
			cout << "valid" << endl;
			cout << "unsigned integer" << endl << endl;
		}
		else if (isInteger(string))
		{
			cout << "valid" << endl;
			cout << "integer" << endl << endl;
		}
		else if (isReal(string))
		{
			cout << "valid" << endl;
			cout << "real number" << endl << endl;
		}

		else if (isRealwExp(string))
		{
			cout << "valid" << endl;
			cout << "real number with exponent" << endl << endl;
		}
		else if (isString(string))
		{
			cout << "valid" << endl;
			cout << "string" << endl << endl;
		}

		else
			cout << "not valid" << endl << endl;
		cout << "1 to exist else to continue: ";
		cin >> conitnuar;
	}
}