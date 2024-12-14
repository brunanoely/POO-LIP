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
        getline(cin, nome);
        cin >> preco;
        cin.ignore(); 
        contador++;
        cout << "Produto criado: " << nome << endl;
        cout << "Preco: " << fixed << setprecision(2) << preco << endl;
        cout << "Total de produtos: " << contador << endl;
    }

    Produto(string n, float p) : nome(n), preco(p) {
        contador++;
        cout << "Produto criado: " << nome << endl;
        cout << "Preco: " << fixed << setprecision(2) << preco << endl;
        cout << "Total de produtos: " << contador << endl;
    }

    // Destrutor
    ~Produto() {
        cout << "Produto destruido: " << nome << endl;
        contador--;
        cout << "Total de produtos: " << contador << endl;
    }
};

int Produto::contador = 0;

int main() {

    Produto produto1;

    string nomeProduto2;
    float precoProduto2;

    cin.ignore(); 
    getline(cin, nomeProduto2);

    cin >> precoProduto2;

    Produto produto2(nomeProduto2, precoProduto2);

    return 0; 
}
