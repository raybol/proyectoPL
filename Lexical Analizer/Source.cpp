#include<iostream>
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
	int i = 1;
	bool valid = true;
	//cotejo inicial
	//cadea no puede ser solo +,- o .
	//tampoco pueda ser "+." o "-."
	//no puede ser "+.e" o "-.e"
	//solo pueda empezar con +,-,., o un digito
	if (((cadena[0] == '+' || cadena[0] == '-' || cadena[0] == '.') && (strlen(cadena) == 1)) ||
		((cadena[0] == '+' || cadena[0] == '-') && (cadena[1] == '.') && (strlen(cadena) == 2)) ||
		((cadena[0] == '+' || cadena[0] == '-') && (cadena[1] == '.') && (cadena[2] == 'e' || cadena[2] == 'E')) ||
		((cadena[0]<'0' || cadena[0]>'9') && !(cadena[0] == '+' || cadena[0] == '-' || cadena[0] == '.'))
		)
		valid = false;
	//si cadea comienza con punto no pude volver a apareser
	int points;
	if (cadena[0] == '.')
		points = 1;
	else
		points = 0;
	//condicion para salir del ciclo si se encuente 'e' o 'E' en la cadena
	bool hasE = false;

	//ciclo verifica quela cadena contenga solo digitos y la posibilidad de un punto decimal
	//si se encuentra 'e' o 'E' se sale del ciclo para ejecutar otro procedimiento
	for (i; cadena[i] != '\0' && valid &&points < 2; i++) {
		if (cadena[i] == 'e' || cadena[i] == 'E') {
			//se sale del ciclo como ya se verifico esta poscicion se incrementa i por 1
			hasE = true;
			i++;
			break;
		}
		else if (cadena[i] == '.') {
			points++;
			if (points > 1)
				valid = false;
		}

		else if (cadena[i]<'0' || cadena[i]>'9')
			valid = false;
	}
	if (hasE) {
		//cadena luego del exponente solo puede tener signo o digitos
		if (!(cadena[i] == '+' || cadena[i] == '-' || (cadena[i] >= '0' && cadena[0] <= '9'))) {
			valid = false;

		}
		i++;//se verifico una posicion hacii que se incrementa

		for (i; cadena[i] != '\0' && valid; i++) {
			//resto de la cadena tiene que ser digitos
			if (cadena[i]<'0' || cadena[i]>'9')
				valid = false;
		}
	}
	return valid;
}

int main() {
	char string[40];
	int conitnuar = 1;
	while (conitnuar == 1) {
		cout << "cadena: ";
		cin >> string;
		if (isRealwExp(string))
			cout << "valido" << endl;
		else
			cout << "invalido" << endl;
		cout << "1 para continuar: ";
		cin >> conitnuar;
	}

}

