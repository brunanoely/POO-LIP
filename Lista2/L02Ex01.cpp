#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

class Produto {
    public:
    string nome;
    float preco;

    //construtor
    Produto() {

        if (cin.peek() == '\n') cin.ignore();
        getline(std::cin, nome);
        nome.erase(std::remove(nome.begin(), nome.end(), '\r'), nome.end());

        cin >> preco;

        cout << "Produto criado: " << nome << " - Preco: "  << fixed << setprecision(2) << preco << endl;
    }

    //destrutor 
    ~Produto() {
        cout << "Produto destruido: " << nome << endl;
    }
};

int main() {
    Produto p;
    return 0;
}