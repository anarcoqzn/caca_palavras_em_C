
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <iostream>
#include <string>

	
using namespace std;

#define TEN 10
char wordSearch[10][10];
int count = 0;

string strupr(string str){
	int size = str.size();
	for(int i = 0; i < size; i++){
		str[i] = toupper(str[i]);
	}
	return str;
}

string strlwr(string str){
	int size = str.size();
	for(int i = 0; i < size; i++){
		str[i] = tolower(str[i]);
	}
	return str;
}

bool has_int(string word) {
	bool has_int = false;
	int n = word.size();
	for (int i = 0; i < n; i++){
		if ((word[i] == '0') | (word[i] == '1') | (word[i] == '2') | 
			(word[i] == '3') | (word[i] == '4') | (word[i] == '5') |
			(word[i] == '6') | (word[i] == '7') | (word[i] == '8') |
			(word[i] == '9')){
			has_int = true;
		}
	}
	return has_int;
}

bool has_word(string words[], string word, int count){
	bool has_word = false;
	for (int i = 0; i < count; i++) {
		if (words[i] == word)
			has_word = true;
	}
	return has_word;
} 

bool validate_word(string words[], string word, int count) {
	bool increase_n = false;
	
	if (has_int(word)){
		string error = "A palavra não deve possuir inteiros, tente outra palavra.\n";
		cout << error;
		increase_n = true;
	}
	
	else if ((word.size() > 10) | (word.size() < 2)) {
		string error = "A palavra deve possuir entre 2 e 10 letras, tente outra palavra.\n";
		cout << error;
		increase_n = true;
	}
	
	else if (has_word(words, word, count)){
		string error = "A palavra já está no caça-palavras, tente outra palavra.\n";
		cout << error;
		increase_n = true;
	}
	return increase_n;
}

void fill_matrix_letters(){
	char alphabet[26] = {'A', 'B', 'C', 'D', 'E','F', 'G', 'H', 'I', 'J','K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

	//preenche a matriz com as letras do array alfabeto
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			int index = rand() % 26; //aqui eu gero um valor aleatorio entre 0 e 25. Os indices do array
			if(wordSearch[i][j] == 0){
				wordSearch[i][j] = alphabet[index];	
			}
		}
	}
}

void print_wordSearch(){
	
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			printf(" %c ", wordSearch[i][j]);
		}
		printf("\n");
	}
}


void fit_word_diagonal(string word){
	word = strupr(word);
    int size_word = word.size();
	int ok = 0;
	int i = 0;
	int j = 0;
	
	do{					
		i = rand() % TEN; //linha da primeira letra da palavra
		j = rand() % TEN; //coluna da primeira letra da palavra
		
		int i1 = 0;
		int i2 = i;
		int j2 = j;
		while(i1 < size_word && wordSearch[i2][j2] == 0){
			i1++;
			i2++;
		}
		
		if((i2 < 10) && (j2 < 10) && (i1 == size_word)){
			ok =1;
		}
		
    }while(ok == 0);
       
    for(int k =0; k < size_word; k++) {
        wordSearch[i][j] = word[k];
        i++;
        j++;
    }
}

void fit_word_vertical(string word){
	word = strupr(word);
	int size_word = word.size();
	int ok = 0;
	int i = 0;
	int j = 0;
	
	do{					
		i = rand() % TEN; //linha da primeira letra da palavra
		j = rand() % TEN; //coluna da primeira letra da palavra
		
		int i1 = 0;
		int i2 = i;
		while(i1 < size_word && wordSearch[i2][j] == 0){
			i1++;
			i2++;
		}
		
		if((i2 < 10) && (i1 == size_word)){
			ok = 1;
		}
		
    }while(ok == 0);
	
	for(int k = 0;k < size_word;k++){
		wordSearch[i][j] = word[k];
		i++;
	}
}

void fit_word_horizontal(string word){
	word = strupr(word);
	int size_word = word.size();
	int ok = 0;
	int i = 0;
	int j = 0;
	
	do{					
		i = rand() % TEN; //linha da primeira letra da palavra
		j = rand() % TEN; //coluna da primeira letra da palavra
		
		int i1 = 0;
		int j2 = j;
		while(i1 < size_word && wordSearch[i][j2] == 0){
			i1++;
			j2++;
		}
		
		if((j2 < 10) && (i1 == size_word)){
			ok = 1;
		}
		
    }while(ok == 0);
	
	for(int k = 0;k < size_word;k++){
		wordSearch[i][j] = word[k];
		j++;
	}
}



int calculate_ten_percent(int n){
	int ten_percent = (n/100)*TEN;
	return ten_percent;
}

string reverse(string word){
	 string reverse = "";
	 int size_word = word.size();
	 int n = 0;
	 for (int i=size_word; i >= 0; i--){
          reverse += word[i];
          n++;
     } 
     return reverse;
}

void fill_word_reverse(string word){
	word = reverse(word);
	fit_word_horizontal(word);
}

bool validate_n(int n){
	bool n_valid = true;
	if (n < 4){
		cout << "A quantidade de palavras deve ser maior ou igual a 4, tente outra quantidade." << endl;
		n_valid = false;
	}
	else if (n > 25){
		 cout << "A quantidade de palavras deve ser menor ou igual a 25, tente outra quantidade." << endl;
		n_valid = false;
	}
	return n_valid;
}

// Verifica se a palavra formada está no array
int search_array(string* array, string word){
	word = strlwr(word);
	
	for (int i = 0; i < count; i++){
		if( word == strlwr(array[i])){
			return i;
		}
	}
	return -1;
}

// Remove um elemento de um array
string* remove(string* list, int index_element){
	for (int i = index_element; i <  count; ++i){
		list[i] = list[i + 1];
	}
	count--;
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
	
		word += wordSearch[line-1][column-1];
	
		printf("\nPalavra: %s \n", word.c_str());
	
		cout << "Deseja continuar? (S/N)" << endl;
		cin >> ask;
		cout << endl;
		
	}while(ask == "S" || ask == "s");
	
	
	int index_element = search_array(secret_words, word);
	
	if( index_element != -1){
		printf("\nPARABÉNS, VOCÊ ENCONTROU A PALAVRA: %s\n", word.c_str());
		
		achou = true;
	}else{
		cout << "PALAVRA NÃO ENCONTRADA" << endl;
		achou = false;
	}		
	return achou;
}

void initialize(){
	cout << endl;
	cout << "*********************JOGO DE CAÇA PALAVRAS*********************" << endl;
	cout << endl;
	
	cout << "Intruções: " << endl;
	cout << "	1 - Você irá digitar o número de palavras que devem ser escondidas no caça palavras." << endl;
	cout << "	2 - Você deverá digitar as palavras que serão escondidas uma por vez." << endl;
	cout << "	3 - Para procurar as palavras você irá precisar informar as linhas e as colunas das palavras que será formada." << endl;
	cout << "	4 - O jogo será finalizado quando todas as palavras forem encontradas." << endl;
	cout << endl;
	cout << "Digite a quantidade de palavras que serão escondidas:" << endl;
	//preenche a matriz com zeros, evitando lixos de memoria
	for(int i = 0; i < 10; i++){
		memset(wordSearch[i], 0, 10);
	}
}


int main() {
	initialize();
	int n;
	cin >> n;
	while (!validate_n(n)){
		cin >> n;
	}
	string words[n];
	
	for (int i = 0; i < n; i++){
		cout << "Digite a palavra:" << endl;
		string word;
		cin >> word;
		if (validate_word(words, word, count)){
			n += 1;
		}
		else {
			words[count] = word;
			count++;
		}
	}
	
	int ten_percent = calculate_ten_percent(count);
	
	srand(time(NULL)); // funcao que prepara a funcao rand() para gerar valores aleatorios
	
	fit_word_diagonal(words[0]);
	
	if (ten_percent == 0){
		fill_word_reverse(words[1]);
		
	}
	for (int i = ten_percent; i < 2*ten_percent; i++){
		fill_word_reverse(words[i]);
		
	}
	
	// a palavra da segunda posicao nao esta sendo colocada porque vai ser 
	// colocada no metodo de cima q ainda nao foi implementado
	if (ten_percent == 0){
		for (int i = 2; i < count; i++){
			if(i%2 == 0){
				fit_word_vertical(words[i]);
				
			}else{
				fit_word_horizontal(words[i]);
				
			}
		}
	}
	else{ 
		for (int i = 2*ten_percent; i < count; i++){
			if(i%2 == 0){
				fit_word_vertical(words[i]);
				
			}else{
				fit_word_horizontal(words[i]);
				
			}
		}
	}
	
	cout << endl;
	cout << "   CAÇA PALAVRAS" << endl;
	cout << endl;
	fill_matrix_letters();
	print_wordSearch();
	
	cout << endl;
	cout << "Agora encontre as palavras" << endl;
	cout << endl;
	string ask = "S";
	
	while (ask == "S" && count > 0){
		
		bool find_word = search_word(words);
		if (find_word){
			count--;
		}else{
			cout << "Deseja continuar jogando? (S/N)"<< endl;
			cin >> ask;
			ask = strupr(ask);
		}
	}
	
	if(count == 0){
		cout << "Jogo finalizado, você encontrou todas as palavras, parabéns!" << endl;
	}
}
