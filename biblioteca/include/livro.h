#ifndef LIVRO_H
#define LIVRO_H

typedef struct {
    int id;
    char titulo[100];
    char autor[100];
    int ano;
    char genero[50];
    int disponivel; // 1 se disponível, 0 se não
} Livro;

void adicionarLivro(Livro *livros, int *totalLivros);
void listarLivros(Livro *livros, int totalLivros);
void buscarLivro(Livro *livros, int totalLivros, char *titulo);
void salvarLivros(Livro *livros, int totalLivros, char *filename);
void carregarLivros(Livro *livros, int *totalLivros, char *filename);

#endif
