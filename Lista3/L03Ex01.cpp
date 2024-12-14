#include <iostream>
#include <string>
using namespace std;

class Pessoa {
private:
    string nome;
    int idade;

public:
    // Construtor
    Pessoa(string n, int i) : nome(n), idade(i) {}

    // Métodos get
    string getNome() const {
        return nome;
    }

    int getIdade() const {
        return idade;
    }

    // Métodos set
    void setNome(const string& novoNome) {
        nome = novoNome;
    }

    void setIdade(int novaIdade) {
        idade = novaIdade;
    }
};

int main() {

    string nomeInicial;
    int idadeInicial;

    cin >> nomeInicial;

    cin >> idadeInicial;

    Pessoa pessoa(nomeInicial, idadeInicial);

    cout << "Dados iniciais da pessoa:" << endl;
    cout << "Nome: " << pessoa.getNome() << endl;
    cout << "Idade: " << pessoa.getIdade() << endl;

    string sobrenome;
    cin >> sobrenome;

    pessoa.setNome(pessoa.getNome() + " " + sobrenome);
    pessoa.setIdade(pessoa.getIdade() + 1);

    cout << "Dados modificados da pessoa:" << endl;
    cout << "Nome: " << pessoa.getNome() << endl;
    cout << "Idade: " << pessoa.getIdade() << endl;

    return 0;
}
