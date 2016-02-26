#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./abb.h"

void inicializar (ArvoreBB **a) {
	(*a) = NULL;
	int chave;
	float val;
	int i;

	for (i = 0;i < 200; i++) {
		chave = rand();
		val = (float)rand()/200;
		inserir_recursivo (a, chave, val);
	}
}

void inserir_interativo (ArvoreBB **a, int chave, float val) {
	ArvoreBB *novo, *aux, *anterior;
	novo = (ArvoreBB*)malloc(sizeof(ArvoreBB));
	novo->chave = chave;
	novo->val = val;
	novo->dir = NULL;
	novo->esq = NULL;

	anterior = NULL;
	aux = (*a);

	while (aux != NULL) {
		anterior = aux;
		if (novo->chave < aux->chave) {
			aux = aux->esq;
		}
		else {
			aux = aux->dir;
		}
	}
	if (anterior == NULL) {
		(*a) = novo;
	}
	else {
		if (novo->chave < anterior->chave) {
			anterior->esq = novo;
		}
		else {
			anterior->dir = novo;
		}
	}
}

void inserir_recursivo (ArvoreBB **a, int chave, float val) {
	ArvoreBB *aux;

	if ((*a) == NULL) {
		aux = (ArvoreBB*)malloc(sizeof(ArvoreBB));
		aux->val = val;
		aux->chave = chave;
		aux->dir = aux->esq = NULL;
		(*a) = aux;
		return;
	}
	if (chave < (*a)->chave) {
		inserir_recursivo (&(*a)->esq, chave, val);
		return;
	}
	if (chave > (*a)->chave) {
		inserir_recursivo (&(*a)->dir, chave, val);
		return;
	}
}

float buscar_interativo (ArvoreBB *a, int chave) {
	while ((a != NULL) && (a->chave != chave)) {
		if (chave < a->chave) {
			a = a->esq;
		}
		else {
			a = a->dir;
		}

	if(a== NULL){
		printf ("Chave não encontrada!\n");
		return -99999.99;
	}
}
}

float buscar_recursivo (ArvoreBB *a, int chave) {
	if ((a != NULL) && (a->chave != chave)) {
		if (chave < a->chave) {
			buscar_recursivo (a->esq, chave);
		}
		else {
			buscar_recursivo (a->dir, chave);
		}
	}
	if (a != NULL) {
		return a->val;
	}
	else {
		printf ("Chave não encontrada!\n");
		return -99999.99;
	}
}

void listar_elementos (ArvoreBB *a) {
	if (a != NULL) {
		listar_elementos(a->esq);
		printf ("%d => %f\n", a->chave, a->val);
		listar_elementos(a->dir);
	}
	
}

