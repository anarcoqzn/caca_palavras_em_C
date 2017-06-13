/* Mainara + Anarco */


#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <string.h>

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

void preenche_matriz_com_letras(char matriz[10][10]){
	char alfabeto[26] = {'A', 'B', 'C', 'D', 'E','F', 'G', 'H', 'I', 'J','K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

	//preenche a matriz com as letras do array alfabeto
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			int indice = rand() % 26; //aqui eu gero um valor aleatorio entre 0 e 25. Os indices do array
			if(matriz[i][j] == 0){
				matriz[i][j] = alfabeto[indice];	
			}
		}
	}
}

void imprime_caca_palavras(char matriz[10][10]){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			printf("%c ", matriz[i][j]);
		}
		printf("\n");
	}
}

void encaixar_palavra_vertical(char matriz[10][10], string palavra){
	strupr(palavra);
	int i = rand() % 10;
	int j = rand() % 10;
	int check = 0;
	int tamanho_palavra = palavra.size();
	while(check == 0){
		while (i > (10 - tamanho_palavra)){
			i = rand() % 10;
		}
		for(int i1 = i; i1 < tamanho_palavra; i1++){
			if(matriz[i1][j] != 0){
				check = 2;
				break;
			}
		}
		if(check == 2){
			j = rand() % 10; 
			check = 0;
		}else{
			check = 1;
		}
	}
	
	for(int k = 0;k < tamanho_palavra;k++){
		matriz[i][j] = palavra[k];
		i++;
	}
}

void encaixar_palavra_horizontal(char matriz[10][10], string palavra, int metodo){
	strupr(palavra);
	int i = rand() % 10;
	int j = rand() % 10;
	int check = 0;
	int tamanho_palavra = palavra.size();
	while(check == 0){
		while (j > (10 - tamanho_palavra)){
			j = rand() % 10;
		}
		for(int j1 = j; j1 < tamanho_palavra; j1++){
			if(matriz[i][j1] != 0){
				check = 2;
				break;
			}
		}
		if(check == 2){
			i = rand() % 10; 
			check = 0;
		}else{
			check = 1;
		}
	}
	
	for(int k = 0;k < tamanho_palavra;k++){
		matriz[i][j] = palavra[k];
		j++;
	}
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
	
	
	char caca_palavras[10][10];
	
	//preenche a matriz com zeros, evitando lixos de memoria
	for(int i = 0; i < 10; i++){
		memset(caca_palavras[i], 0, 10);
	}
	srand(time(NULL)); // funcao que prepara a funcao rand() para gerar valores aleatorios
	
	for (int i = 0; i < count; i++){
		encaixar_palavra_vertical(caca_palavras, palavras[i]);
	}
	
	preenche_matriz_com_letras(caca_palavras);
	imprime_caca_palavras(caca_palavras);
}

