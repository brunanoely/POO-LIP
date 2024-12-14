#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <iomanip>

using namespace std;

// Classe Base: ContaBancaria
class ContaBancaria {
protected:
    double saldo;

public:
    ContaBancaria() : saldo(0.0) {}
    virtual ~ContaBancaria() = default;

    virtual void depositar(double valor) = 0;
    virtual void retirar(double valor) = 0;
    virtual string tipoConta() const = 0;

    virtual void exibirSaldo() const {
        cout << "Tipo de conta: " << tipoConta() 
             << "; Saldo atual: R$ " << fixed << setprecision(2) << saldo << endl;
    }
};

// Subclasse: ContaCorrente
class ContaCorrente : public ContaBancaria {
private:
    const double taxaRetirada = 1.0;

public:
    void depositar(double valor) override {
        saldo += valor;
    }

    void retirar(double valor) override {
        double totalRetirada = valor + taxaRetirada;
        if (saldo >= totalRetirada) {
            saldo -= totalRetirada;
        } else {
            cout << "Saldo insuficiente para realizar a retirada!" << endl;
        }
    }

    string tipoConta() const override {
        return "Corrente";
    }
};

// Subclasse: Poupanca
class Poupanca : public ContaBancaria {
private:
    const double bonusDeposito = 0.01;

public:
    void depositar(double valor) override {
        saldo += valor + (valor * bonusDeposito);
    }

    void retirar(double valor) override {
        if (saldo >= valor) {
            saldo -= valor;
        } else {
            cout << "Saldo insuficiente para realizar a retirada!" << endl;
        }
    }

    string tipoConta() const override {
        return "Poupanca";
    }
};

// Função para exibir saldos e tipos de todas as contas
void exibirTodasContas(const vector<unique_ptr<ContaBancaria>>& contas) {
    cout << "Saldos e tipos de todas as contas:" << endl;
    for (const auto& conta : contas) {
        conta->exibirSaldo();
    }
}

// Programa principal
int main() {
    vector<unique_ptr<ContaBancaria>> contas;
    int opcao;

    // Menu para adicionar contas
    while (true) {
        cin >> opcao;

        if (opcao == 1) {
            contas.push_back(make_unique<ContaCorrente>());
            cout << "Conta Corrente adicionada." << endl;
        } else if (opcao == 2) {
            contas.push_back(make_unique<Poupanca>());
            cout << "Poupanca adicionada." << endl;
        } else if (opcao == 3) {
            break;
        } else {
            cout << "Opcao invalida!" << endl;
        }
    }

    // Operações nas contas
    while (true) {
        int indice, tipoOperacao;
        double valor;

        cin >> indice;
        if (indice < 0) {
            break;
        }
        if (indice == 3) {
            exibirTodasContas(contas);
            continue;
        }

        cin >> tipoOperacao >> valor;

        if (indice >= 0 && indice < contas.size()) {
            if (tipoOperacao == 1) {
                contas[indice]->depositar(valor);
            } else if (tipoOperacao == 2) {
                contas[indice]->retirar(valor);
            } else {
                cout << "Operacao invalida!" << endl;
            }
            contas[indice]->exibirSaldo();
        } else {
            cout << "Indice de conta invalido!" << endl;
        }
    }

    // Exibir saldo final de todas as contas
    exibirTodasContas(contas);

    return 0;
}
