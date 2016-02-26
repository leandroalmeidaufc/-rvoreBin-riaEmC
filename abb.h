typedef struct ArvoreBinariaDeBusca {
	int chave;
	float val;
	struct ArvoreBinariaDeBusca *dir;
	struct ArvoreBinariaDeBusca *esq;
} ArvoreBB;

void inicializar (ArvoreBB **);

void inserir_interativo (ArvoreBB **, int, float);

void inserir_recursivo (ArvoreBB **, int, float);

float buscar_interativo (ArvoreBB *, int);

float buscar_recursivo (ArvoreBB *, int);

void listar_elementos (ArvoreBB *);
