#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include "livro.h"
#include "usuario.h"

typedef struct {
    int idLivro;
    int idUsuario;
    char dataEmprestimo[11];
    char dataDevolucao[11];
} Emprestimo;

void realizarEmprestimo(Emprestimo* emprestimos, int* totalEmprestimos, Livro* livros, int totalLivros, Usuario* usuarios, int totalUsuarios);
void devolverEmprestimo(Emprestimo* emprestimos, int* totalEmprestimos, Livro* livros, int totalLivros, int idLivro);
void listarEmprestimos(Emprestimo* emprestimos, int totalEmprestimos, Livro* livros, Usuario* usuarios);

#endif
