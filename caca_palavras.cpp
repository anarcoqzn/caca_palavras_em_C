#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int main(){
	
	char palavra[26] = {'A', 'B', 'C', 'D', 'E','F', 'G', 'H', 'I', 'J','K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	
	
	char caca_palavras[10][10];
	srand(time(NULL));
	
	for(int i = 0; i < 10; i++){
		memset(caca_palavras[i], 0, 10);
	}
	
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			int indice = rand() % 26 + 1;
			if(palavra[indice] != '@'){
				caca_palavras[i][j] = palavra[indice]; 
			}else{
				j = j -1;
			}
		}
	}
	
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			printf("%c ", caca_palavras[i][j]);
		}
		printf("\n");
	}

return 0;
}
