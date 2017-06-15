#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEZ 10 //tamanho da matriz do caça palavras
char matriz[DEZ][DEZ]; //matriz do caça palavras

//preenche a matriz com zeros, evitando lixos de memoria
void inicializa_matriz() {
	for(int i = 0; i < 10; i++){
		memset(matriz[i], 0, DEZ);
	}
}

char gera_letra_aleatoria() {
    char alfabeto[26] = {'A', 'B', 'C', 'D', 'E','F', 'G', 'H', 'I', 'J','K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int indice_letra = rand() % 26;
    return alfabeto[indice_letra];
}

void preenche_matriz_com_letras(){
    for (int i= 0; i < DEZ; i++) {
        for (int j= 0; j < DEZ; j++) {
            char letra;
            letra = gera_letra_aleatoria();
            if(matriz[i][j] == 0)
                matriz[i][j] = letra;
        }
    }
}

void imprime_caca_palavras(){
	for(int i = 0; i < DEZ; i++){
            for(int j = 0; j < DEZ; j++)
                printf("%c|", matriz[i][j]);
                
            printf("\n");	
        }	
}

void coloca_palavra_diagonal_decrescente(char palavra[DEZ]){
    int i = rand() % (DEZ - strlen(palavra)); //linha da primeira letra da palavra
    int j = rand() % (DEZ - strlen(palavra)); //coluna da primeira letra da palavra
    
    while (matriz[i][j] != 0) {
        i = rand() % (DEZ - strlen(palavra));
        j = rand() % (DEZ - strlen(palavra));
    }
    
    for(int k =0; k < strlen(palavra); k++) {
        matriz[i][j] = palavra[k];
        i++; j++;
    }
}

void coloca_palavra_diagonal_crescente(char palavra[DEZ]){
    int i = strlen(palavra) + (rand() % (DEZ - strlen(palavra))); //linha da primeira letra da palavra
    int j = rand() % (DEZ - strlen(palavra)); //coluna da primeira letra da palavra
    
     while (matriz[i][j] != 0) {
         i = strlen(palavra) + (rand() % (DEZ - strlen(palavra)));
         j = rand() % (DEZ - strlen(palavra));   
     }
    
    for(int k =0; k < strlen(palavra); k++) {
        matriz[i][j] = palavra[k];
        i--; j++;
    }
}

char* inverte_palavra(char palavra[10]){
     char *palavra_invertida = malloc(10*sizeof(char));
     int i;
     int f = 0;
     for (i = (strlen(palavra)-1); i>=0; i--){
              palavra_invertida[f] = palavra[i];  
              f++;
         } 
     return palavra_invertida;
}

int main() {
    
    srand(time(NULL));
    inicializa_matriz();
    
    char palavra1[10] = "raquel";
    char *palavra1_invertida = inverte_palavra(palavra1);

    coloca_palavra_diagonal_decrescente(palavra1);
    coloca_palavra_diagonal_crescente(palavra1_invertida);
    preenche_matriz_com_letras();
    imprime_caca_palavras(); 
   
    return 0;
}


