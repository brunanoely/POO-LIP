#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Produto {
private:
    string nome;
    float preco;

public:
    static int contador;

    Produto() {
        if (cin.peek() == '\n') cin.ignore();
        getline(cin, nome);
        cin >> preco;
        cin.ignore();
        contador++;
        cout << "Produto criado: " << nome << endl;
        cout << "Preco: " << fixed << setprecision(2) << preco << endl;
        cout << "Total de produtos: " << contador << endl;
    }

    Produto(const Produto& outro) : nome("(copia)" + outro.nome), preco(outro.preco) {
        contador++;
        cout << "Produto criado copia: " << nome << endl;
        cout << "Preco: " << fixed << setprecision(2) << preco << endl;
        cout << "Total de produtos: " << contador << endl;
    }

    ~Produto() {
        cout << "Produto destruido: " << nome << endl;
        contador--;
        cout << "Total de produtos: " << contador << endl;
    }
};

int Produto::contador = 0;

int main() {
    Produto p1; 
    Produto p2; 
    Produto p3 = p1; 

    return 0;
}



