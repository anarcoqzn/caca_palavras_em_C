
/* Caca palavras */

#include <stdio.h>
#include <iostream>
#include <string>	
using namespace std;

bool existe_inteiro(string palavra) {
	bool existe_inteiro = false;
	int n = palavra.size();
	for (int i = 0; i < n; i++){
		if ((palavra[i] == '0') | (palavra[i] == '1') | (palavra[i] == '2') | 
			(palavra[i] == '3') | (palavra[i] == '4') | (palavra[i] == '5') |
			(palavra[i] == '6') | (palavra[i] == '7') | (palavra[i] == '8') |
			(palavra[i] == '9')){
			existe_inteiro = true;
		}
	}
	return existe_inteiro;
}

bool existe_palavra(string palavras[], string palavra, int count){
	bool existe_palavra = false;
	for (int i = 0; i < count; i++) {
		if (palavras[i] == palavra)
			existe_palavra = true;
	}
	return existe_palavra;
} 

bool valida_palavra(string palavras[], string palavra, int count) {
	bool incrementa_n = false;
	if ((palavra.size() > 10) | (palavra.size() < 2)) {
		string erro = "A palavra deve possuir entre 2 e 10 letras, tente outra palavra.\n";
		cout << erro;
		incrementa_n = true;
	}
	if (existe_inteiro(palavra)){
		string erro = "A palavra não deve possuir inteiros, tente outra palavra.\n";
		cout << erro;
		incrementa_n = true;
	}
	if (existe_palavra(palavras, palavra, count)){
		string erro = "A palavra já está no caça-palavras, tente outra palavra.\n";
		cout << erro;
		incrementa_n = true;
	}
	return incrementa_n;
}


int main() {
	
	int n;
	cin >> n;
	string palavras[n];
	int count = 0;
	for (int i = 0; i < n; i++){
		string palavra;
		cin >> palavra;
		if (valida_palavra(palavras, palavra, count)){
			n += 1;
		}
		else {
			palavras[count] = palavra;
			count++;
		}
	}
		
}

