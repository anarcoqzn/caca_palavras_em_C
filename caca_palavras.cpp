
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <iostream>
#include <string>	
using namespace std;

#define DEZ 10
char caca_palavras[10][10];

string strupr(string str){
	int tamanho = str.size();
	for(int i = 0; i < tamanho; i++){
		str[i] = toupper(str[i]);
	}
	return str;
}

string strlwr(string str){
	int tamanho = str.size();
	for(int i = 0; i < tamanho; i++){
		str[i] = tolower(str[i]);
	}
	return str;
}

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

void preenche_matriz_com_letras(){
	char alfabeto[26] = {'A', 'B', 'C', 'D', 'E','F', 'G', 'H', 'I', 'J','K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

	//preenche a matriz com as letras do array alfabeto
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			int indice = rand() % 26; //aqui eu gero um valor aleatorio entre 0 e 25. Os indices do array
			if(caca_palavras[i][j] == 0){
				caca_palavras[i][j] = alfabeto[indice];	
			}
		}
	}
}

void imprime_caca_palavras(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			printf("%c ", caca_palavras[i][j]);
		}
		printf("\n");
	}
}

void encaixar_palavra_diagonal_crescente(string palavra){
	palavra = strupr(palavra);
    int tamanho_palavra = palavra.size();
    int linha_primeira_letra_palavra = rand() % (DEZ - tamanho_palavra);
    int coluna_primeira_letra_palavra = rand() % (DEZ - tamanho_palavra);
    
    while (caca_palavras[linha_primeira_letra_palavra][coluna_primeira_letra_palavra] != 0) {
        linha_primeira_letra_palavra = rand() % (DEZ - tamanho_palavra);
        coluna_primeira_letra_palavra = rand() % (DEZ - tamanho_palavra);
    }
    
    
    for(int i =0; i < tamanho_palavra; i++) {
        caca_palavras[linha_primeira_letra_palavra][coluna_primeira_letra_palavra] = palavra[i];
        linha_primeira_letra_palavra++;coluna_primeira_letra_palavra++;
    }
}

void encaixar_palavra_diagonal_decrescente(string palavra){
	palavra = strupr(palavra);
    int tamanho_palavra = palavra.size();
    int linha_primeira_letra_palavra = tamanho_palavra + (rand() % (DEZ-tamanho_palavra));
    int coluna_primeira_letra_palavra = rand() % (DEZ-tamanho_palavra);
    
     while (caca_palavras[linha_primeira_letra_palavra][coluna_primeira_letra_palavra] != 0) {
         linha_primeira_letra_palavra = tamanho_palavra + (rand() % (DEZ-tamanho_palavra));
         coluna_primeira_letra_palavra = rand() % (DEZ-tamanho_palavra);   
     }
    
       
    for(int i =0; i < tamanho_palavra; i++) {
        caca_palavras[linha_primeira_letra_palavra][coluna_primeira_letra_palavra] = palavra[i];
        linha_primeira_letra_palavra--;coluna_primeira_letra_palavra++;
    }
}

void encaixar_palavra_vertical(string palavra){
	palavra = strupr(palavra);
	int i = rand() % 10;
	int j = rand() % 10;
	int check = 0;
	int tamanho_palavra = palavra.size();
	while(check == 0){
		while (i > (10 - tamanho_palavra)){
			i = rand() % 10;
		}
		for(int i1 = i; i1 < tamanho_palavra; i1++){
			if(caca_palavras[i1][j] != 0){
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
		caca_palavras[i][j] = palavra[k];
		i++;
	}
}

void encaixar_palavra_horizontal(string palavra){
	palavra = strupr(palavra);
	int i = rand() % 10;
	int j = rand() % 10;
	int check = 0;
	int tamanho_palavra = palavra.size();
	while(check == 0){
		while (j > (10 - tamanho_palavra)){
			j = rand() % 10;
		}
		for(int j1 = j; j1 < tamanho_palavra; j1++){
			if(caca_palavras[i][j1] != 0){
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
		caca_palavras[i][j] = palavra[k];
		j++;
	}
}

/*
string determina_palavras_cruzadas(string palavras[], int count){
	
	string palavras_cruzadas[2];
	
	for(int i = 0;i < count - 1; i++){
		string palavra1 = palavras[i];
		string palavra2 = palavras[i+1];	
		int tamanho = palavra1.size();
		int j = 0;
		for(; j < tamanho; j++){
			if(palavra1[i] == palavra2[j]){
				palavras_cruzadas[0] = palavra1;
				palavras_cruzadas[1] = palavra2;
				break;
			}
		}
		if(j < tamanho){
			break;
		}
	}
	return *palavras_cruzadas;
}
*/

int calcula_dez_porcento(int n){
	int dez_porcento = (n/100)*10;
	return dez_porcento;
}

string inverte(string palavra){
	 string inverso = "";
	 int tamanho = palavra.size();
	 int n = 0;
	 for (int i=tamanho; i >= 0; i--)
      {
		 
		  
          inverso += palavra[i];
          n++;
      } 
      return inverso;
}

void encaixar_palavra_invertida(string palavra){
	palavra = inverte(palavra);
	encaixar_palavra_horizontal(palavra);
}

bool valida_n(int n){
	bool n_valido = true;
	if (n < 4){
		cout << "A quantidade de palavras deve ser maior que 4, tente outra quantidade." << endl;
		n_valido = false;
	}
	else if (n > 25){
		 cout << "A quantidade de palavras deve ser menor que 25, tente outra quantidade." << endl;
		n_valido = false;
	}
	return n_valido;
}

// Verifica se a palavra formada está no array
int search_array(string* array, string word){
	word = strlwr(word);
	size_t i;
	for (i = 0; i < sizeof(array); i++){
		if( word == strlwr(array[i])){
			return i;
		}
	}
	return -1;
}

// Remove um elemento de um array
string* remove(string* list, int index_element){
	size_t i;
	for (i = index_element; i <  sizeof(list); ++i){
		list[i] = list[i + 1];
	}
	return list;
}

// Encontra palavra
bool search_word(string secret_words[]){
	bool achou = false;
	string word;
	string ask;
	do{
		int line,column;
	
		cout << "Digite a linha: " << endl;
		cin >> line;
		cout << "Digite a coluna: " <<endl;
		cin >> column;
	
		word += caca_palavras[line-1][column-1];
	
		cout << word << endl;
	
		cout << "A palavra já foi formada para ser procurada? (S/N)" << endl;
		cin >> ask;
		cout << endl;
	}while(ask == "S" || ask == "s");
	
	
	int index_element = search_array(secret_words, word);
	cout << index_element << endl;
	if( index_element != -1){
		cout << "PARABÉNS, VOCÊ ENCONTROU A PALAVRA!" << endl;
		
		achou = true;
	}else{
		cout << "PALAVRA NÃO ENCONTRADA" << endl;
		achou = false;
	}		
	return achou;
}

void inicializa(){
	cout << "JOGO DE CAÇA PALAVRAS" << endl;
	cout << "Intruções: " << endl;
	cout << "1 - Você irá digitar o número de palavras que devem ser" << endl;
	cout << "    escondidas no caça palavras." << endl;
	cout << "2 - Você deverá digitar as palavras que serão escondidas," << endl; 
	cout << "    uma por vez." << endl;
	cout << "3 - Para procurar as palavras você irá precisar informar" << endl;
	cout << "    as linhas e as colunas das palavras que será formada." << endl;
	cout << "4 - O jogo será finalizado quando todas as palavras forem encontradas." << endl;
	
	cout << "Digite a quantidade de palavras que serão escondidas:" << endl;
}


int main() {
	inicializa();
	int n;
	cin >> n;
	while (!valida_n(n)){
		cin >> n;
	}
	string palavras[n];
	int count = 0;
	for (int i = 0; i < n; i++){
		cout << "Digite a palavra:" << endl;
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
	
	int dez_porcento = calcula_dez_porcento(count);
	
	//preenche a matriz com zeros, evitando lixos de memoria
	for(int i = 0; i < 10; i++){
		memset(caca_palavras[i], 0, 10);
	}
	srand(time(NULL)); // funcao que prepara a funcao rand() para gerar valores aleatorios
	
	
	if (dez_porcento == 0){
		encaixar_palavra_diagonal_crescente(palavras[0]);
		
	}
	else {
		for (int i = 0; i < dez_porcento; i++){
			encaixar_palavra_diagonal_decrescente(palavras[i]);
			
		}
	}
	
	if (dez_porcento == 0){
		encaixar_palavra_invertida(palavras[1]);
		
	}
	for (int i = dez_porcento; i < 2*dez_porcento; i++){
		encaixar_palavra_invertida(palavras[i]);
		
	}
	
	// a palavra da segunda posicao nao esta sendo colocada porque vai ser 
	// colocada no metodo de cima q ainda nao foi implementado
	if (dez_porcento == 0){
		for (int i = 2; i < count; i++){
			if(i%2 == 0){
				encaixar_palavra_vertical(palavras[i]);
				
			}else{
				encaixar_palavra_horizontal(palavras[i]);
				
			}
		}
	}
	else{ 
		for (int i = 2*dez_porcento; i < count; i++){
			if(i%2 == 0){
				encaixar_palavra_vertical(palavras[i]);
				
			}else{
				encaixar_palavra_horizontal(palavras[i]);
				
			}
		}
	}
	
	cout << endl;
	cout << "   CAÇA PALAVRAS" << endl;
	cout << endl;
	preenche_matriz_com_letras();
	imprime_caca_palavras();
	
	cout << endl;
	cout << "Agora encontre as palavras" << endl;
	cout << endl;
	
	while (count > 0){
		bool achou_palavra = search_word(palavras);
		if (achou_palavra){
			count--;
		}	
	}
	
	cout << "Jogo finalizado, você encontrou todas as palavras, parabéns!" << endl;
	
}

