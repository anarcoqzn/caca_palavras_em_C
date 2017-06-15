#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEZ 10
char matriz[DEZ][DEZ];


void inicializa_matriz() {
    //preenche a matriz com zeros, evitando lixos de memoria
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

void coloca_palavra_diagonal_crescente(char palavra[DEZ]){
    int tamanho_palavra = strlen(palavra);
    int linha_primeira_letra_palavra = rand() % (DEZ - tamanho_palavra);
    int coluna_primeira_letra_palavra = rand() % (DEZ - tamanho_palavra);
    
    while (matriz[linha_primeira_letra_palavra][coluna_primeira_letra_palavra] != 0) {
        linha_primeira_letra_palavra = rand() % (DEZ - tamanho_palavra);
        coluna_primeira_letra_palavra = rand() % (DEZ - tamanho_palavra);
    }
    printf("Inicio da palavra, linha: %d coluna: %d \n",linha_primeira_letra_palavra+1, coluna_primeira_letra_palavra+1);
    
    for(int i =0; i < tamanho_palavra; i++) {
        matriz[linha_primeira_letra_palavra][coluna_primeira_letra_palavra] = palavra[i];
        linha_primeira_letra_palavra++;coluna_primeira_letra_palavra++;
    }
}

void coloca_palavra_diagonal_decrescente(char palavra[DEZ]){
    int tamanho_palavra = strlen(palavra);
    int linha_primeira_letra_palavra = tamanho_palavra + (rand() % (DEZ-tamanho_palavra));
    int coluna_primeira_letra_palavra = rand() % (DEZ-tamanho_palavra);
    
     while (matriz[linha_primeira_letra_palavra][coluna_primeira_letra_palavra] != 0) {
         linha_primeira_letra_palavra = tamanho_palavra + (rand() % (DEZ-tamanho_palavra));
         coluna_primeira_letra_palavra = rand() % (DEZ-tamanho_palavra);   
     }
    
    printf("Inicio da palavra, linha: %d coluna: %d \n",linha_primeira_letra_palavra+1, coluna_primeira_letra_palavra+1);
    
    for(int i =0; i < tamanho_palavra; i++) {
        matriz[linha_primeira_letra_palavra][coluna_primeira_letra_palavra] = palavra[i];
        linha_primeira_letra_palavra--;coluna_primeira_letra_palavra++;
    }
}

char* inverter(char palavra[10]){
     char *array_dinamico = malloc(10*sizeof(char));
     int i;
     int f = 0;
     for (i = (strlen(palavra)-1); i>=0; i--){
              array_dinamico[f] = palavra[i];  
              f++;
         } 
     return array_dinamico;
}

int main() {
    
    srand(time(NULL));
    inicializa_matriz();
    char palavra1[10] = "raquel";
    char palavra2[10] = "ambrozio";
    char palavra3[10] = "da";
    char palavra4[10] = "fonseca";
    coloca_palavra_diagonal_crescente(palavra1);
    coloca_palavra_diagonal_crescente(palavra2);
    coloca_palavra_diagonal_crescente(palavra3);
    coloca_palavra_diagonal_crescente(palavra4);
    preenche_matriz_com_letras();
    imprime_caca_palavras();
    
    /*char palavraa[10] = "raquel";
    char *oi = inverter(palavraa);
    printf("%s",oi);
    

    preenche_matriz();
    imprime_caca_palavras();
    printf("\n");*/
    
    
    
    /*coloca_palavra_diagonal_decrescente(palavra);
    printf("\n");
    imprime_caca_palavras();

    
    /*char letra = gera_letra_aleatoria();
    char letras[TAMANHOMATRIZ][TAMANHOMATRIZ];
    letras[1][1] = letra;
    printf("%c \n", letras[1][1]);*/

    return 0;
}

