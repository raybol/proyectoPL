#include"LexicalAnalizerFunctions.h"

bool isUnsignedInteger(const MyString & cadena) {
	//verifica si es entero signo
	bool valid = true;

	//loop verifica que la cadena solo contiene digitos
	for (int i = 0; cadena[i] != '\0'&&valid; i++) {
		if (cadena[i]<'0' || cadena[i]>'9')
			valid = false;
	}
	return valid;
}
bool  isInteger(const MyString & cadena) {
	//verifica si es un entero(puede tener signo)
	bool valid = false;
	//solo puede comenzar con +,-, o un digito
	if (cadena[0] == '+' || cadena[0] == '-' || (cadena[0] >= '0' && cadena[0] <= '9'))
		valid = true;
	//resto de la cadena es solo digitos
	//loop verifica esto
	if (cadena.len() == 1)
		valid = false;
	for (int i = 1; cadena[i] != '\0' && valid; i++) {
		if (cadena[i]<'0' || cadena[i]>'9')
			valid = false;
	}
	return valid;
}
bool  isReal(const MyString & cadena) {
	//verifica si es un numero real/ tiene punto decimal
	bool valid = true;
	//cotejo inicial
	//cadea no puede ser solo +,- o .
	//tampoco pueda ser "+." o "-."
	//solo pueda empezar con +,-,., o un digito
	if (((cadena[0] == '+' || cadena[0] == '-' || cadena[0] == '.') && (cadena.len() == 1)) ||
		((cadena[0] == '+' || cadena[0] == '-') && (cadena[1] == '.') && (cadena.len() == 2)) ||
		((cadena[0]<'0' || cadena[0]>'9') && !(cadena[0] == '+' || cadena[0] == '-' || cadena[0] == '.'))
		)
		valid = false;

	int points = 0;
	//resto de la cadea es solo digitos pero puede haber un punto decimal
	//cotejos anteriores verificaron el punto al principio si esta entre los digitos solo puede haber 1
	for (int i = 1; cadena[i] != '\0' && valid &&points < 2; i++) {
		if (cadena[i] == '.')
			points++;
		else if (cadena[i]<'0' || cadena[i]>'9')
			valid = false;
	}
	return valid;
}

bool  isRealwExp(const MyString & cadena) {
	//verifica si es un numero real que puede tener exponente
	int i = 0;
	int puntos = 0;
	bool valid = false;
	bool hasE = false;//condicion para salir del ciclo si se encuente 'e' o 'E' en la cadena

	//cotejo inicial
	//cadena tiene que empezar con +,-,. o digito 0-9
	//si cadena empieza con digito se descarta un comienzo 
	//con punto o signo haci que pasa a verificar el resto de la cadena
	if ((cadena[i] >= '0' && cadena[i] <= '9')) {
		valid = true;
		i++;
	}
	else if (cadena[i] == '+' || cadena[i] == '-') {
		if (cadena.len() > 1) {
			valid = true;
			i++;
			if (cadena[i] == '.') {
				puntos++;
				if (cadena[i + 1] == 'e' || cadena.len() == 2)
					valid = false;
				else
					i++;
			}
			else if (cadena[i]<'0' || cadena[i]>'9')
				valid = false;
		}
	}
	else if (cadena[i] == '.') {
		if (cadena.len() > 1) {
			valid = true;
			i++;
			puntos++;
			if (cadena[i]<'0' || cadena[i]>'9')
				valid = false;
		}
	}
	//ciclo verifica que la cadena contenga solo digitos y la posibilidad de un punto decimal
	//si se encuentra 'e' o 'E' se sale del ciclo para ejecutar otro procedimiento
	for (i; cadena[i] != '\0' && valid && (puntos < 2); i++) {
		if (cadena[i] == 'e' || cadena[i] == 'E') {
			//se sale del ciclo como ya se verifico esta poscicion se incrementa i por 1
			hasE = true;
			i++;
			break;
		}
		else if (cadena[i] == '.') {
			puntos++;
			if (puntos > 1)
				valid = false;
		}
		else if (cadena[i]<'0' || cadena[i]>'9')
			valid = false;
	}
	if (hasE) {
		//cadena luego del exponente solo puede comenzar con signo o digito
		if (!(cadena[i] == '+' || cadena[i] == '-' || (cadena[i] >= '0' && cadena[0] <= '9'))) {
			valid = false;
		}
		i++;//se verifico una posicion haci que se incrementa
		if ((cadena[i - 1] == '+' || cadena[i - 1] == '-') && cadena[i] == '\0')
			valid = false;
		else {
			for (i; cadena[i] != '\0' && valid; i++) {
				//resto de la cadena tiene que ser digitos
				if (cadena[i]<'0' || cadena[i]>'9')
					valid = false;
			}
		}
	}
	return valid;
}

bool isKeyWord(const MyString & cadena) {
	const int size = 6;
	char* opList[size] = { "IF", "THEN", "READ", "PRINT",  "END.","REM" };
	bool valid = false;
	for (int i = 0; i < size; i++) {
		if (cadena.toUpper() == opList[i])
			valid = true;
	}
	return valid;
}

bool isAssignment(const MyString & cadena) {
	return MyString(cadena) == "=";
}

bool isOperator(const MyString & cadena) {
	return isRelationalOperator(cadena) ||
		isLogicalOperator(cadena) ||
		isArithmeticOperator(cadena);
}

bool isRelationalOperator(const MyString & cadena) {
	const int size = 6;
	char* opList[size] = { ".gt.", ".lt." ,".eq." , ".ge." , ".le.", ".ne." };
	bool valid = false;
	for (int i = 0; i < size; i++) {
		if (cadena.toLower() == opList[i])
			valid = true;
	}
	return valid;
}

bool isLogicalOperator(const MyString & cadena) {
	const int size = 3;
	char* opList[size] = { ".or.", ".and.",".not." };
	bool valid = false;
	for (int i = 0; i < size; i++) {
		if (cadena.toLower() == opList[i])
			valid = true;
	}
	return valid;
}
bool isArithmeticOperator(const MyString & cadena) {
	const int size = 4;
	char* opList[size] = { ".add.", ".sub.",".mul.",".div." };
	bool valid = false;
	for (int i = 0; i < size; i++) {
		if (cadena.toLower() == opList[i])
			valid = true;
	}
	return valid;
}

bool isIntVariable(const MyString & cadena)
{
	bool valid = true;
	for (int i = 0; cadena[i] != '\0' && valid; i++)
	{
		if (!((cadena[i] >= 'A' && cadena[i] <= 'F') || (cadena[i] >= 'a' && cadena[i] <= 'f')))
			valid = false;
	}
	return valid;
}

bool isRealVariable(const MyString & cadena)
{
	bool valid = true;
	for (int i = 0; cadena[i] != '\0' && valid; i++)
	{
		if (!((cadena[0] >= 'G' && cadena[0] <= 'N') || (cadena[0] >= 'g' && cadena[0] <= 'n')))
			valid = false;
	}
	return valid;
}

bool isStringVariable(const MyString & cadena)
{
	bool valid = true;
	for (int i = 0; cadena[i] != '\0' && valid; i++)
	{
		if (!((cadena[0] >= 'O' && cadena[0] <= 'Z') || (cadena[0] >= 'o' && cadena[0] <= 'z')))
			valid = false;
	}
	return valid;
}


bool isString(const MyString & cadena)
{
	bool valid = false;

	if (cadena[0] == '"' && cadena[cadena.len() - 1] == '"')
	{
		valid = true;
	}
	return valid;
}

bool isArithmeticExpression(const vector<MyString> & statement) {
	vector<MyString>::const_iterator it = statement.begin() + 2;
	int i = 0;

	for (it; it != statement.end(); ++it, i++) {
		if ((isUnsignedInteger(statement[i])) ||
			(isInteger(statement[i])) ||
			(isIntVariable(statement[i])) ||
			(isReal(statement[i])) ||
			(isRealwExp(statement[i])) ||
			(isRealVariable(statement[i]))
			) {
			if (!(
				(isLogicalOperator(statement[i + 1])) ||
				(isRelationalOperator(statement[i + 1])) ||
				(isArithmeticOperator(statement[i + 1]))
				)
				) {
				cout << "error expected operator" << endl;
				break;
			}
		}
		else if ((isReal(statement[i])) ||
			(isRealwExp(statement[i])) ||
			isRealVariable(statement[i])) {
			if (!(
				(isLogicalOperator(statement[i + 1])) ||
				(isRelationalOperator(statement[i + 1])) ||
				(isArithmeticOperator(statement[i + 1]))
				)
				) {
				cout << "error expected operator" << endl;
				break;
			}
		}
		else if (isStringVariable(statement[i]) ||
			isString(statement[i])
			) {
		}
		else if (isLogicalOperator(statement[i])) {}
		else if (isRelationalOperator(statement[i])) {}
		else if (isArithmeticOperator(statement[i])) {}




		/*if (statement[i] == ".add." || statement[i].toLower() == ".sub.") {
			break;
		}*/
	}
	return true;
}
bool isVariable(const MyString & cadena) {
	return isStringVariable(cadena) || isIntVariable(cadena) || isRealVariable(cadena);
}

//bool isCommentStatement(const vector<MyString> & statement) {
//	if (isKeyWord(statement[0])) {
//
//
//	}
//	else if ((isIntVariable(statement[0])) ||
//		(isRealVariable(statement[0])) ||
//		(isStringVariable(statement[0]))) {
//		if (statement[1] != '=') {
//			cout << "error" << endl;
//		}
//		else {
//
//		}
//
//
//	}
//	return true;
//}

vector<MyString> tokenizer(const MyString & statement)
{
	vector<MyString> tokens;
	MyString temp;
	for (int i = 0; statement[i] != '\0'; i++) {
		temp = "";
		if (statement[i] == '"') {
			temp += statement[i];
			i++;
			for (int j = i; statement[j] != '"' && statement[j] != '\0'; j++) {
				temp += statement[j];
				i = j;
			}
			if (statement[i + 1] == '"') {
				temp += statement[i + 1];
				i++;
			}
		}
		else {
			for (int j = i; statement[j] != ' ' && statement[j] != '\0'; j++) {
				//cout << "holA" <<j<< endl;
				temp += statement[j];
				i = j;
			}
		}
		if (temp != "") {
			tokens.push_back(temp);
		}
	}
	return tokens;
}




//bool isRelationalexpression(const vector<MyString> & statement) {
//	bool twoParts = false;
//	MyString op;
//	vector<MyString>::const_iterator it = statement.begin();
//	int i = 0;
//	for (it; it != statement.end(); ++it, i++) {
//		if (statement[i] == ".lt." || statement[i].toLower() == ".le." || statement[i].toLower() == ".gt." || statement[i].toLower() == ".ge.") {
//			break;
//		}
//	}
//
//	if (it != statement.end()) {
//		op = it->toLower();
//		/*if (isStringVariable(*(it - 1)) || isString(*(it - 1)) || isStringVariable(*(it + 1)) || isString(*(it + 1)))
//		{
//			if (!((isStringVariable(*(it - 1)) || isString(*(it - 1))) && (isStringVariable(*(it + 1)) || isString(*(it + 1))))) {
//				cout << "logical opertator: " << *it << " wrong operand data type" << endl;
//				return false;
//			}
//
//		}*/
//		vector<MyString> exp(statement.begin(), it);
//		vector<MyString> factor(it + 1, statement.end());
//		if (exp.size() == 0 || factor.size() == 0) {
//
//			cout << "expected an expression" << endl;
//			return false;
//		}
//		return isRelationalexpression(exp) && isExpression(factor);
//	}
//	else {
//		return isExpression(statement,start,end);
//	}
//	return true;
//}



bool validation(const vector<MyString> & statement) {
	int i = 0;
	vector<MyString>::const_iterator it = statement.begin();
	for (it; it != statement.end(); ++it, i++) {
		if (!(
			(isKeyWord(*it)) ||
			(isLogicalOperator(*it)) ||
			(isRelationalOperator(*it)) ||
			(isArithmeticOperator(*it)) ||
			(isAssignment(*it)) ||
			(isUnsignedInteger(*it)) ||
			(isInteger(*it)) ||
			(isReal(*it)) ||
			(isRealwExp(*it)) ||
			(isIntVariable(*it)) ||
			(isRealVariable(*it)) ||
			(isStringVariable(*it)) ||
			(isString(*it))
			)) {
			cout << "ERROR\nunkown identifier: " << *it << endl;
			return false;
		}
	}
	return true;
}

