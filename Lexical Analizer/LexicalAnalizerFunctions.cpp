#include<iostream>
#include<string>
#include"MyString.h"
using namespace std;
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

bool  isRealwExp(const char *cadena) {
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
		if (strlen(cadena) > 1) {
			valid = true;
			i++;
			if (cadena[i] == '.') {
				puntos++;
				if (cadena[i + 1] == 'e' || strlen(cadena) == 2)
					valid = false;
				else
					i++;
			}
			else if (cadena[i]<'0' || cadena[i]>'9')
				valid = false;
		}
	}
	else if (cadena[i] == '.') {
		if (strlen(cadena) > 1) {
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
	const int size = 5;
	char* opList[size] = { "IF", "THEN", "READ", "PRINT",  "END" };
	bool valid = false;
	for (int i = 0; i < size; i++) {
		if (op.toUpper() == opList[i])
			valid = true;
	}
	return valid;
}

bool isAssigment(const char *cadena) {
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

