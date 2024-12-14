#include <iostream>
#include <string>

using namespace std;

class Livro {
private:
    string titulo;
    int numPaginas;

public:
    Livro(string titulo, int numPaginas) : titulo(""), numPaginas(0) {}

    string getTitulo() {
        return titulo;
    }

    void setTitulo(string novotitulo) {
        titulo = novotitulo;
    }

    int getNumeroPaginas() {
        return numPaginas;
    }

    void setNumeroPaginas(int novoNum) {
        numPaginas = novoNum;
    }

    void exibirDetalhes() {
        cout << "Titulo: " << titulo << endl;
        cout << "Numero de Paginas: " << numPaginas << endl;
    }
};

int main() {
    string titulo;
    int numeroPaginas;

    if (cin.peek() == '\n') cin.ignore();
        getline(cin, titulo);
    
    cin >> numeroPaginas;
    cin.ignore();

    Livro livro(titulo, numeroPaginas);

    cout << "Detalhes iniciais do livro:" << endl;
    livro.exibirDetalhes();

    string subtitulo = "romance realista publicado em 1899";
    livro.setTitulo(livro.getTitulo() + ": " + subtitulo);

    livro.setNumeroPaginas(livro.getNumeroPaginas() + 50);

    cout << "Detalhes modificados do livro:" << endl;
    livro.exibirDetalhes();

    return 0;
}