#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	
	char nome[5][30], aux[30];
	int i = 0;
    int j;
    int numPalavras = 0;
    char *palavras[50];
    char line[50];

    FILE *arquivo;
    arquivo = fopen("aps.txt", "r+");

    if (arquivo == NULL) {
	    return EXIT_FAILURE;
	}

    while(fgets(line, sizeof line, arquivo) != NULL) {
        //Adiciona cada palavra no vetor
        palavras[i] = strdup(line);

        i++;

        //Conta a quantidade de palavras
        numPalavras++;
    }
    printf("Dados do arquivo:\n");
    
    for(j = 0; j < numPalavras; j++) {
		printf("\n%s", palavras[j]); //Exibi as palavras que estao no vetor.		
	}
	
	for(j = 1; j < numPalavras; j++) {
		
		strcpy(aux,palavras[j]);
		i = j - 1;
	
		while(i >= 0 && strcmp(palavras[i], aux) > 0) {
			strcpy(palavras[i+1],palavras[i]);
			i--;
		}
		strcpy(palavras[i+1],aux);
	}
	printf("\n\n\-----------------------\n\n");
	printf("\n\nDADOS ORDENADOS\n");
	printf("\n\n-----------------------\n\n");

	for(i = 0; i < numPalavras; i++){
		printf("\n%s",palavras[i]);
	}
return 0;
}
