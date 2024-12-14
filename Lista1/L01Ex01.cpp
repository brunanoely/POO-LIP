#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Livro
{
public:

 char titulo[20];
 char autor[30];

};

 int main() {
    Livro p;
    char nomeAutor[30];
    char tituloLivro[30];

    //printf("digite o nome do livro:");
    fgets(tituloLivro, 30, stdin);
    //printf("digite o preço do livro:");
     fgets(nomeAutor, 30, stdin);
    strcpy(p.titulo,tituloLivro);
    strcpy(p.autor, nomeAutor);

    printf("Titulo: %s",p.titulo);
    printf("Autor: %s",p.autor);

    return 0;
}
