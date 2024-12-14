#include <iostream>
#include <string>
using namespace std;

class Veiculo {
    private:
    string marca;
    int anoFabricacao;

    public:
    //construtores
    Veiculo();
    Veiculo(string marca, int anoFabricacao) {
        this->marca = marca;
        this->anoFabricacao = anoFabricacao;
    }

    string getMarca() const {
        return marca;
    }

    int getAnofabricacao() const {
        return anoFabricacao;
    }
 
    void setMarca(string novaMarca) {
        marca = novaMarca;
    }

    void setAnoFabricacao(int novoAno) {
        anoFabricacao = novoAno;
    }
};

class Carro: public Veiculo {
    private:
    int numeroPortas;
    
    public:

    Carro();

    Carro(string marca, int anoFabricacao, int numeroPortas) : Veiculo(marca, anoFabricacao) {
        this->numeroPortas = numeroPortas;
    }


    int getNumeroPortas() const {
        return numeroPortas;
    }

    void setNumeroPortas(int novoNumero) {
        numeroPortas = novoNumero;
    }
};

Carro:: Carro() : numeroPortas(0) {}
Veiculo::Veiculo() : marca(""), anoFabricacao(0) {}

int main() {

    Veiculo veiculo;
    Carro carro;
    string marca;
    int anoFabricacao;
    int numeroPortas;

    cin >> marca;
    veiculo.setMarca(marca);
    cin >> anoFabricacao;
    veiculo.setAnoFabricacao(anoFabricacao);

    cout << "Dados do Veiculo:" << endl;
    cout << "Marca: " << veiculo.getMarca() << endl;
    cout << "Ano de Fabricacao: " << veiculo.getAnofabricacao() << endl;

    cin >> marca;
    carro.setMarca(marca);
    cin >> anoFabricacao;
    carro.setAnoFabricacao(anoFabricacao);
    cin >> numeroPortas;
    carro.setNumeroPortas(numeroPortas);
    cout << "Dados do Carro:" << endl;
    cout << "Marca: " << carro.getMarca() << endl;
    cout << "Ano de Fabricacao: " << carro.getAnofabricacao() << endl;
    cout << "Numero de Portas: " << carro.getNumeroPortas() << endl;
    
    return 0;
}
