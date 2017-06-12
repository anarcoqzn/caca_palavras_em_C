#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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

void encaixar_palavra_vertical(char matriz[10][10], char palavra[]){
	strupr(palavra);
	int i = rand() % 10;
	int j = rand() % 10;
	int check = 0;
	
	while(check == 0){
		while (i > (10 - strlen(palavra))){
			i = rand() % 10;
		}
		for(int i1 = i; i1 < strlen(palavra); i1++){
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
	
	for(int k = 0;k < strlen(palavra);k++){
		matriz[i][j] = palavra[k];
		i++;
	}
}

void encaixar_palavra_horizontal(char matriz[10][10], char palavra[], int metodo){
	strupr(palavra);
	int i = rand() % 10;
	int j = rand() % 10;
	int check = 0;
	
	while(check == 0){
		while (j > (10 - strlen(palavra))){
			j = rand() % 10;
		}
		for(int j1 = j; j1 < strlen(palavra); j1++){
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
	
	for(int k = 0;k < strlen(palavra);k++){
		matriz[i][j] = palavra[k];
		j++;
	}
}

int main(){
	
	char palavra0[] = "uvinha";
	char palavra1[] = "bolacha";
	char palavra2[] = "flor";
	char palavra3[] = "violao";
	char palavra4[] = "galinha";
	char palavra5[] = "foguete";
	char palavra6[] = "soldado";
	char palavra7[] = "bomba";
	char palavra8[] = "carro";
	char palavra9[] = "gol";
	
	char caca_palavras[10][10];
	
	//preenche a matriz com zeros, evitando lixos de memoria
	for(int i = 0; i < 10; i++){
		memset(caca_palavras[i], 0, 10);
	}
	srand(time(NULL)); // funcao que prepara a funcao rand() para gerar valores aleatorios
	
	encaixar_palavra_vertical(caca_palavras, palavra0);
	encaixar_palavra_vertical(caca_palavras, palavra1);
	encaixar_palavra_vertical(caca_palavras, palavra2);
	encaixar_palavra_vertical(caca_palavras, palavra3);
	encaixar_palavra_vertical(caca_palavras, palavra4);
	encaixar_palavra_vertical(caca_palavras, palavra5);
	encaixar_palavra_vertical(caca_palavras, palavra6);
	encaixar_palavra_vertical(caca_palavras, palavra7);
	encaixar_palavra_vertical(caca_palavras, palavra8);
	encaixar_palavra_vertical(caca_palavras, palavra9);
	
	preenche_matriz_com_letras(caca_palavras);
	imprime_caca_palavras(caca_palavras);
	
	system("PAUSE");
	return 0;
}
