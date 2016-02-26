#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./abb.h"


int main (int narg, char * argv[]) {
	ArvoreBB *a;
	int chave;
	float val;

	inicializar (&a);

	char opc;
	system("clear");

	while ((opc != 'S') && (opc != 's')) {

		printf("'C' para inicializar a Arvore\n");
		printf("'I' para inserir novo registro de forma interativa\n");
		printf("'i' para inserir novo registro de forma recursiva\n");
		printf("'B' para buscar begistro de forma interativa\n");
		printf("'b' para buscar registro de forma recursiva\n");
		printf("'L' para utilizar a função Listar\n");
		printf("'S' para sair\n\n");
		printf("Sua escolha: ");
		scanf(" %c", &opc);

		system("clear");

		switch (opc) {
			case ('C'):
				inicializar (&a);
				break;

			case ('I'):
				chave = rand();
				val = (float)rand()/200;
				inserir_interativo (&a, chave, val);
				break;
			case ('i'):
				chave = rand();
				val = (float)rand()/200;
				inserir_recursivo (&a, chave, val);
				break;

			case ('B'):
				printf("Digite a chave que deseja buscar: ");
				scanf("%d", &chave);
				printf ("%f\n", buscar_interativo (a, chave));
				break;
			case ('b'):
				printf("Digite a chave que deseja buscar: ");
				scanf("%d", &chave);
				printf ("%f\n", buscar_recursivo (a, chave));
				break;

			case ('L'):
				listar_elementos(a);
				break;
		}
	}


	return EXIT_SUCCESS;
}
