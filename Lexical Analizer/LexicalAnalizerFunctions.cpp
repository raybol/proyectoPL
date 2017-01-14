#include"LexicalAnalizerFunctions.h"

bool isUnsignedInteger(const char *cadena) {
	//verifica si es entero signo
	bool valid = true;

	//loop verifica que la cadena solo contiene digitos
	for (int i = 0; cadena[i] != '\0'&&valid; i++) {
		if (cadena[i]<'0' || cadena[i]>'9')
			valid = false;
	}
	return valid;
}
bool  isInteger(const char *cadena) {
	//verifica si es un entero(puede tener signo)
	bool valid = false;
	//solo puede comenzar con +,-, o un digito
	if (cadena[0] == '+' || cadena[0] == '-' || (cadena[0] >= '0' && cadena[0] <= '9'))
		valid = true;
	//resto de la cadena es solo digitos
	//loop verifica esto
	if (strlen(cadena) == 1)
		valid = false;
	for (int i = 1; cadena[i] != '\0' && valid; i++) {
		if (cadena[i]<'0' || cadena[i]>'9')
			valid = false;
	}
	return valid;
}
bool  isReal(const char *cadena) {
	//verifica si es un numero real/ tiene punto decimal
	bool valid = true;
	//cotejo inicial
	//cadea no puede ser solo +,- o .
	//tampoco pueda ser "+." o "-."
	//solo pueda empezar con +,-,., o un digito
	if (((cadena[0] == '+' || cadena[0] == '-' || cadena[0] == '.') && (strlen(cadena) == 1)) ||
		((cadena[0] == '+' || cadena[0] == '-') && (cadena[1] == '.') && (strlen(cadena) == 2)) ||
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

bool isKeyWord(const char *cadena) {
	MyString op;
	op = cadena;
	const int size = 6;
	char* opList[size] = { "IF", "THEN", "READ", "PRINT",  "END.","REM" };
	bool valid = false;
	for (int i = 0; i < size; i++) {
		if (op.toUpper() == opList[i])
			valid = true;
	}
	return valid;
}

bool isAssignment(const char *cadena) {
	return MyString(cadena) == "=";
}

bool isRelationalOperator(const char *cadena) {
	MyString op;
	op = cadena;
	const int size = 6;
	char* opList[size] = { ".gt.", ".lt." ,".eq." , ".ge." , ".le.", ".ne." };
	bool valid = false;
	for (int i = 0; i < size; i++) {
		if (op.toLower() == opList[i])
			valid = true;
	}
	return valid;
}

bool isLogicalOperator(const char *cadena) {
	MyString op;
	op = cadena;
	const int size = 3;
	char* opList[size] = { ".or.", ".and.",".not." };
	bool valid = false;
	for (int i = 0; i < size; i++) {
		if (op.toLower() == opList[i])
			valid = true;
	}
	return valid;
}
bool isArithmeticOperator(const char *cadena) {
	MyString op;
	op = cadena;
	const int size = 4;
	char* opList[size] = { ".add.", ".sub.",".mul.",".div." };
	bool valid = false;
	for (int i = 0; i < size; i++) {
		if (op.toLower() == opList[i])
			valid = true;
	}
	return valid;
}

bool isVariable(const MyString & cadena)
{
	bool valid = true;
	for (int i = 0; cadena[i] != '\0' && valid; i++)
	{
		if (!((cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= 'a' && cadena[i] <= 'z')))
			valid = false;
	}
	return valid;
}

bool isString(const char *cadena)
{
	bool valid = false;

	if (cadena[0] == '"' && cadena[strlen(cadena) - 1] == '"')
	{
		valid = true;
	}
	return valid;
}

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

bool isExpression(const vector<MyString> & statement) {
	bool twoParts = false;
	int i;
	MyString op;
	vector<MyString>::const_iterator  it;
	for (it = statement.begin(); it != statement.end() && it->toLower() != ".sub." && it->toLower() !=".add."; ++it) {}
	if (it != statement.end()) {
		op = statement[i];
		vector<MyString> exp(statement.begin(), it);
		vector<MyString> factor(it, statement.end());
		isExpression(exp);
		isFactor(factor);
	}
	else {
		isFactor(statement);
	}
}

bool isFactor(const vector<MyString> & statement) {
	MyString op;
	vector<MyString>::const_iterator  it;
	for (it = statement.begin(); it != statement.end() && it->toLower() != ".mul." && it->toLower() != ".div."; ++it) {}
	if (it != statement.end()) {
		op = it->toLower();
		vector<MyString> factor(statement.begin(), it);
		vector<MyString> term(it, statement.end());
		
		isFactor(factor);
		isTerm(term);
	}
	else {
		isTerm(statement);
	}

}

bool isTerm(const vector<MyString> & statement) {
	if (statement.size() > 1)
		isExpression(statement);
	else {		
		return isRealwExp(statement[0])||isVariable(statement[0]);
	}	
}
//void validation() {
//	char string[40];
//	int conitnuar = 0;
//
//	while (conitnuar != 1) {
//		cout << "word: ";
//		cin >> string;
//		if (isKeyWord(string)) {
//			cout << "valid" << endl;
//			cout << "keyword" << endl << endl;
//		}
//		else if (isLogicalOperator(string))
//		{
//			cout << "valid" << endl;
//			cout << "logical operator" << endl << endl;
//		}
//		else if (isRelationalOperator(string))
//		{
//			cout << "valid" << endl;
//			cout << "relational operator" << endl << endl;
//		}
//		else if (isArithmeticOperator(string))
//		{
//			cout << "valid" << endl;
//			cout << "arithmetic operator" << endl << endl;
//		}
//		else if (isVariable(string))
//		{
//			cout << "valid" << endl;
//			if ((string[0] >= 'A' && string[0] <= 'F') || (string[0] >= 'a' && string[0] <= 'f'))
//				cout << "integer ";
//			else if ((string[0] >= 'G' && string[0] <= 'N') || (string[0] >= 'g' && string[0] <= 'n'))
//				cout << "real ";
//			else if ((string[0] >= 'O' && string[0] <= 'Z') || (string[0] >= 'o' && string[0] <= 'z'))
//				cout << "string ";
//			cout << "variable" << endl;
//			cout << endl;
//		}
//		else if (isAssignment(string))
//		{
//			cout << "valid" << endl;
//			cout << "assingment operator" << endl << endl;
//		}
//		else if (isUnsignedInteger(string))
//		{
//			cout << "valid" << endl;
//			cout << "unsigned integer" << endl << endl;
//		}
//		else if (isInteger(string))
//		{
//			cout << "valid" << endl;
//			cout << "integer" << endl << endl;
//		}
//		else if (isReal(string))
//		{
//			cout << "valid" << endl;
//			cout << "real number" << endl << endl;
//		}
//
//		else if (isRealwExp(string))
//		{
//			cout << "valid" << endl;
//			cout << "real number with exponent" << endl << endl;
//		}
//		else if (isString(string))
//		{
//			cout << "valid" << endl;
//			cout << "string" << endl << endl;
//		}
//
//		else
//			cout << "not valid" << endl << endl;
//		cout << "1 to exist else to continue: ";
//		cin >> conitnuar;
//	}
//
//}

