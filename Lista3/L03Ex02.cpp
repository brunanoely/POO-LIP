#include <iostream>
#include <string>

using namespace std;

class ContaBancaria {
private:
    float saldo;
    string nomeCliente;

public:

    ContaBancaria(string nome) : saldo(0), nomeCliente(nome) {}

    void setSaldo(float novoSaldo) {
        if (novoSaldo >= 0) {
            saldo = novoSaldo;
        } 
    }

    float getSaldo() const {
        return saldo;
    }

    void depositar(float valor) {
        if (valor > 0) {
            saldo += valor;
            cout << "Depositado: " << valor << endl;
        } 
    }

    void sacar(float valor) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;
            cout << "Sacado: " << valor << endl;
        } else {
            cout << "Valor de saque invalido ou saldo insuficiente!" << endl;
        }
    }

    void imprimirDados() const {
        cout << "Nome do Cliente: " << nomeCliente << endl;
        cout << "Saldo Atual: " << saldo << endl;
    }
};

int main() {
    string nomeCliente;
    int numMovimentacoes;

    getline(cin, nomeCliente);

    ContaBancaria conta(nomeCliente);
;
    cin >> numMovimentacoes;

    for (int i = 0; i < numMovimentacoes; i++) {
        int opcao;
        float valor;

        cin >> opcao;

        if (opcao == 1) {
            cin >> valor;
            conta.depositar(valor);
        } else if (opcao == 2) {
            cin >> valor;
            conta.sacar(valor);
        } else {
            cout << "Opcao invalida!" << endl;
        }
    }

    // Exibe os dados finais da conta
    cout << "\nDados da conta apos as movimentacoes:" << endl;
    conta.imprimirDados();

    return 0;
}
