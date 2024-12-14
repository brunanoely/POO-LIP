#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class Veiculo {
protected:
    int velocidade;

public:
    Veiculo() : velocidade(0) {}

    virtual ~Veiculo() = default;

    virtual void acelerar(int quantia) = 0;
    virtual void frear(int quantia) = 0;
    virtual string tipo() const = 0;

    void exibirVelocidade() const {
        cout << "Velocidade atual: " << velocidade << " km/h" << endl;
    }

    int getVelocidade() const {
        return velocidade;
    }
};

class Carro : public Veiculo {
public:
    void acelerar(int quantia) override {
        velocidade += quantia;
    }

    void frear(int quantia) override {
        velocidade = max(0, velocidade - quantia);
    }

    string tipo() const override {
        return "Carro";
    }
};

class Bicicleta : public Veiculo {
public:
    void acelerar(int quantia) override {
        velocidade += quantia;
    }

    void frear(int quantia) override {
        velocidade = max(0, velocidade - quantia);
    }

    string tipo() const override {
        return "Bicicleta";
    }
};

void imprimirTodosVeiculos(const vector<unique_ptr<Veiculo>>& veiculos) {
    cout << "Velocidade atual de todos os veiculos:" << endl;
    for (size_t i = 0; i < veiculos.size(); ++i) {
        cout << "Veiculo: " << veiculos[i]->tipo() << " [" << i
             << "] Velocidade atual: " << veiculos[i]->getVelocidade() << " km/h" << endl;
    }
}

void interagirComVeiculo(vector<unique_ptr<Veiculo>>& veiculos) {
    while (true) {
        int indice, operacao, quantia;
        cin >> indice;
        if (indice < 0) {
            imprimirTodosVeiculos(veiculos);
            break;
        }
        cin >> operacao >> quantia;

        if (indice >= 0 && indice < veiculos.size()) {
            if (operacao == 1) {
                veiculos[indice]->acelerar(quantia);
            } else if (operacao == 2) {
                veiculos[indice]->frear(quantia);
            } else {
                cout << "Operacao invalida!" << endl;
            }
            cout << "[" << indice << "] Velocidade atual:" << veiculos[indice]->getVelocidade() << " km/h" << endl;
        } else {
            cout << "Indice de veiculo invalido!" << endl;
        }
    }
}

int main() {
    vector<unique_ptr<Veiculo>> veiculos;
    int opcao;

    while (true) {
        cin >> opcao;
        if (opcao == 1) {
            veiculos.push_back(make_unique<Carro>());
            cout << "Carro adicionado." << endl;
        } else if (opcao == 2) {
            veiculos.push_back(make_unique<Bicicleta>());
            cout << "Bicicleta adicionada." << endl;
        } else if (opcao == 3) {
            break;
        } else {
            cout << "Opcao invalida!" << endl;
        }
    }

    interagirComVeiculo(veiculos);

    return 0;
}
