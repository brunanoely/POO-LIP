#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Produto {
private:
    string nome;
    float preco;

public:
   
    Produto(string nomeInicial, float precoInicial) : nome(nomeInicial), preco(precoInicial) {}

    string getNome() const {
        return nome;
    }

    void setNome(const string& novoNome) {
        nome = novoNome;
    }

    float getPreco() const {
        return preco;
    }

    void setPreco(float novoPreco) {
        if (novoPreco >= 0) {
            preco = novoPreco;
        } 
    }

    void exibirDetalhes() const {
        cout << "Nome: " << nome << endl;
        cout << "Preco: " << fixed << setprecision(2) << preco << endl;
    }
};

int main() {
    string nomeProduto;
    float precoProduto;

    getline(cin, nomeProduto);
    cin >> precoProduto;
    cin.ignore();


    Produto produto(nomeProduto, precoProduto);

    cout << "Detalhes iniciais do produto:" << endl;
    produto.exibirDetalhes();


    if (cin.peek() == '\n') cin.ignore();
        getline(cin, nomeProduto);
    produto.setNome(nomeProduto);

    produto.setPreco(produto.getPreco() * 1.10);

    cout << "Detalhes modificados do produto:" << endl;
    produto.exibirDetalhes();

    return 0;
}
