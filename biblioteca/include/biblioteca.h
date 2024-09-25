#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "livro.h"
#include "usuario.h"
#include "emprestimo.h"

void inicializarSistema();
void salvarDados(Livro* livros, int totalLivros, Usuario* usuarios, int totalUsuarios, Emprestimo* emprestimos, int totalEmprestimos);
void carregarDados(Livro* livros, int* totalLivros, Usuario* usuarios, int* totalUsuarios, Emprestimo* emprestimos, int* totalEmprestimos);

#endif
