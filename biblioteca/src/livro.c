#include <stdio.h>
#include <string.h>
#include "livro.h"

void adicionarLivro(Livro* livros, int* totalLivros) {
    int ano;

    livros[*(totalLivros)].id = *(totalLivros);

    printf("\n\nTítulo: ");
    __fpurge(stdin);
    gets(livros[*(totalLivros)].titulo);
    
    printf("Autor: ");
    __fpurge(stdin);
    gets(livros[*(totalLivros)].autor);
    
    printf("Ano: ");
    scanf("%d", &ano);
    livros[*(totalLivros)].ano = ano;
    
    printf("Gênero: ");
    __fpurge(stdin);
    gets(livros[*(totalLivros)].genero);
    
    livros[*(totalLivros)].disponivel = 1;
    *(totalLivros) = *(totalLivros) + 1;
    printf("Livro adicionado.\n\n");
}

void listarLivros(Livro *livros, int totalLivros) {
    int i;
    printf("\n\nLista de livros:\n");
    for(i=0; i<totalLivros; i++)
        printf("%d. %s\n", livros[i].id, livros[i].titulo);
    printf("Fim\n\n");
}

void buscarLivro(Livro *livros, int totalLivros, char *titulo) {
    int i, encontrado = 0;
    printf("Buscando livro \"%s\"...\n", titulo);
    for(i=0; i<totalLivros; i++) {
        if(strcmp(livros[i].titulo, titulo) == 0) {
            printf("Encontrado\n");
            encontrado = 1;
            printf("-Id: %d\n", livros[i].id);
            printf("-Título: %s\n", livros[i].titulo);
            printf("-Autor: %s\n", livros[i].autor);
            printf("-Ano: %d\n", livros[i].ano);
            printf("-Gênero: %s\n", livros[i].genero);
            printf("-Disponível: %s\n", (livros[i].disponivel==1? "Sim":"Não"));
        }
    }
    if(!encontrado)
        printf("Não encontrado\n");
    printf("\n");
}

void salvarLivro(Livro *livros, int totalLivros, char *filename) {
    FILE *fp;
    int i;
    if(!(fp = fopen(filename, "w"))) {
        printf("Erro na abertura do arquivo\n");
        return;
    }
    for(i=0; i<totalLivros; i++) {
        fprintf(fp, "%d\n", livros[i].id);
        fprintf(fp, "%s\n", livros[i].titulo);
        fprintf(fp, "%s\n", livros[i].autor);
        fprintf(fp, "%d\n", livros[i].ano);
        fprintf(fp, "%s\n", livros[i].genero);
        fprintf(fp, "%d\n", livros[i].disponivel);
    }
    fclose(fp);
    printf("Salvo com sucesso\n");
}

