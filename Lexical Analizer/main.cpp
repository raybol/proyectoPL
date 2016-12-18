#include<iostream>
#include<string>
#include"MyString.h"
#include"LexicalAnalizerFunctions.h"
using namespace std;
int main() {
	double x = 4.e5;
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