#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int main(){
	
	char alfabeto[26] = {'A', 'B', 'C', 'D', 'E','F', 'G', 'H', 'I', 'J','K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	char caca_palavras[10][10];
	
	srand(time(NULL)); // funcao que prepara a funcao rand() para gerar valores aleatorios
	
	//preenche a matriz com zeros, evitando lixos de memoria
	for(int i = 0; i < 10; i++){
		memset(caca_palavras[i], 0, 10);
	}
	
	//preenche a matriz com as letras do array alfabeto
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			int indice = rand() % 26; //aqui eu gero um valor aleatorio entre 0 e 25. Os indices do array
			caca_palavras[i][j] = alfabeto[indice];
		}
	}
	
	//imprime a matriz, porque eu sou printador geral de matriz agora, segundo Raquel.
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			printf("%c ", caca_palavras[i][j]);
		}
		printf("\n");
	}

return 0;
}
