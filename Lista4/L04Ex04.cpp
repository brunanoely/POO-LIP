#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

class Produto {
    private:
    string nome;
    float preco;

    public:

    Produto();
    Produto(string nome, float preco) {
        this->nome = nome;
        this->preco = preco;
    }

    string getNome() const {
        return nome;
    }

    void setNome(string novoNome) {
        nome = novoNome;
    }

    float getPreco() const {
        return preco;
    }

    void setPreco(float novoPreco) {
        preco = novoPreco;
    }

    void imprimirProduto() {
        cout << "Dados do Produto:" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Preco: " << fixed << setprecision(2) << preco << endl;
    }

};

class ProdutoEletronico : public Produto {
    private:
    int garantia;

    public:
    ProdutoEletronico();
    ProdutoEletronico(int garantia) {
        this->garantia = garantia;
    }

    int getGarantia() const {
        return garantia;
    }

    void setGarantia(int novaGarantia) {
        garantia = novaGarantia;
    }

    void imprimirGarantia() {
        Produto::imprimirProduto();
        cout << "Garantia: " << garantia << " meses" << endl;
    }

    void estenderGarantia(int adicional) {
        garantia += adicional;
        Produto::imprimirProduto();
        cout << "Garantia: " << garantia << " meses" << endl;
    }
};

Produto:: Produto() : nome(""), preco(0) {}
ProdutoEletronico:: ProdutoEletronico() : garantia(0) {}

int main() {

    Produto produto;
    ProdutoEletronico eletronico;

    int garantia, adicional;
    string nome;
    float preco;

    getline(cin, nome);
    produto.setNome(nome);
    cin >> preco;
    produto.setPreco(preco);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    getline(cin, nome);
    eletronico.setNome(nome);
    cin >> preco;
    eletronico.setPreco(preco);

    cin >> garantia;
    eletronico.setGarantia(garantia);
    
    produto.imprimirProduto();
    eletronico.imprimirGarantia();

    cin >> adicional;
    eletronico.estenderGarantia(adicional);

    return 0;
}