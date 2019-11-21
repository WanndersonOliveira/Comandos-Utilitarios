#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utilitarios.h"

#define MAXCHAR 100

int abrir(char *arquivo){
	FILE *file;
	char linha[MAXCHAR];
	int i;
	
	for(i = 0; i < 5; i++){
		printf("\n");
	}
	
	printf("Nome do arquivo: %s\n\n", arquivo);
	
	file = fopen(arquivo, "r");
	
	if(file == NULL){
		printf("Nao foi possivel abrir o arquivo %s", *arquivo);
		return 1;
	}
	
	while(fgets(linha, MAXCHAR, file) != NULL){
		printf("%s", linha);
	}
	
	fclose(file);
	
	for(i = 0; i < 5; i++){
		printf("\n");
	}
	
	return 0;
}

int copiar(char* fonte, char* dreno){
	// Abrindo o arquivo fonte

	FILE *source, *sink;
	char linha[MAXCHAR];
	int i;

	source = fopen(fonte, "r");
	sink = fopen(dreno, "w");
	
	if(source == NULL){
		printf("Nao foi possivel abrir o arquivo %s", *fonte);
		return 1;
	}

	printf("\tCopiando %s >> %s ...\n\n", fonte, dreno);

	while(fgets(linha, MAXCHAR, source) != NULL){
		fprintf(sink, "%s", linha);
	}

	fclose(source);
	fclose(sink);

	printf("\tDados copiados com sucesso!");

	return 0;
}

int mesclar(char* fonte1, char* fonte2, char* dreno){
	FILE *source1, *source2, *sink;

	char linha[MAXCHAR];

	source1 = fopen(fonte1, "r");
	source2 = fopen(fonte2, "r");
	sink = fopen(dreno, "w");

	if(source1 == NULL){
		printf("Nao foi possivel abrir o arquivo %s", *fonte1);
		return 1;
	}

	if(source2 == NULL){
		printf("Nao foi possivel abrir o arquivo %s", *fonte2);
		return 1;
	}

	if(dreno == NULL){
		printf("Nao foi possivel abrir o arquivo %s", *dreno);
		return 1;
	}

	printf("\tMesclando %s + %s >> %s ...\n\n", fonte1,fonte2,dreno);

	while(fgets(linha, MAXCHAR, source1) != NULL){
		fprintf(sink, "%s", linha);
	}

	while(fgets(linha, MAXCHAR, source2) != NULL){
		fprintf(sink, "%s", linha);
	}

	fclose(source1);
	fclose(source2);
	fclose(sink);

	printf("\tArquivos mesclados com sucesso!\n");

	return 0;
}

int remover(char* fonte){
	printf("\tRemovendo arquivo %s\n", *fonte);
	
	char comando[50] = "del ";

	strcat(comando, fonte);

	if(system(comando)!=0){
		return 1;
	} else {
		printf("Removido com sucesso!");
	}

	return 0;
}