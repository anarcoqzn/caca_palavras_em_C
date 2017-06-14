#include <iostream>
#include <string>

using namespace std;



//OBS: Falta saber se a sequencia de indices esta correta


// Verifica se a palavra formada está no array
int search_array(string* array, string word){
	for (int i = 0; i < sizeof(array); i++){
		if( word == array[i]){
			return i;
		}
	}
	return -1;
}

// Remove um elemento de um array
string* remove(string* list, int index_element){
	for (int i = index_element; i <  sizeof(list); ++i){
		list[i] = list[i + 1];
	}
	return list;
}

// Encontra palavra
void search_word(string mtrx[10][10], string* secret_words){

	string word;
	string ask;
	
	do{
		int line,column;
	
		cout << "Digite a linha: ";
		cin >> line;
		cout << "Digite a coluna: ";
		cin >> column;
	
		word += mtrx[line-1][column-1];
	
		cout << word << endl;
	
		cout << "Continuar? ";
		cin >> ask;
		cout << endl;
	}while(ask == "SIM");
	
	
	int index_element = search_array(secret_words, word);
	
	if( index_element != -1){
		cout << "PALAVRA ENCONTRADA";
		secret_words = remove(secret_words,index_element);
	}else{
		cout << "PALAVRA NÃO ENCONTRADA";
	}		
}

//teste
int main(){
	string matriz[10][10] = { {"A","B","C","E","U"},{"F","G","Z","D","E"} };
	string palavras_escondidas[] = {"CEU"};	
	search_word(matriz,palavras_escondidas);
	return 0;
}