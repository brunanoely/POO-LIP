#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Produto {
private:
    string nome;
    float preco;

public:
    
    Produto() {
        if (cin.peek() == '\n') cin.ignore();
        getline(cin, nome);  
        cin >> preco;  
        cin.ignore(); 
        cout << "Produto criado: " << nome << endl;
        cout << "Preco: " << fixed << setprecision(2) << preco << endl;
    }

    Produto(string nome, float preco) {
        this->nome = nome;
        this->preco = preco;
        cout << "Produto criado: " << nome << endl;
        cout << "Preco: " << fixed << setprecision(2) << preco << endl;
    }

    ~Produto() {
        cout << "Produto destruido: " << nome << endl;
    }
};

int main() {

    string prod;
    float preco;
    Produto produto1;

    if (cin.peek() == '\n') cin.ignore();
        getline(cin, prod);
    
    cin >> preco;

    
    Produto produto2(prod, preco);



    return 0;
}
