#include <iostream>

class Conta {
private:
    float saldo;

public:
    Conta(float saldoInicial) : saldo(saldoInicial) {}

    void depositar(float valor) {
        saldo += valor;
    }

    bool sacar(float valor) {
        if (saldo >= valor) {
            saldo -= valor;
            return true;
        } else {
            std::cout << "Saldo insuficiente!" << std::endl;
            return false;
        }
    }

    float getSaldo() const {
        return saldo;
    }
};

class ContaCorrente : public Conta {
private:
    float limite;
    float limiteUtilizado;

public:
    ContaCorrente(float saldoInicial, float limiteInicial)
        : Conta(saldoInicial), limite(limiteInicial), limiteUtilizado(0) {}

    bool sacar(float valor) {
        float saldoDisponivel = getSaldo() + (limite - limiteUtilizado);
        if (saldoDisponivel >= valor) {
            if (getSaldo() >= valor) {
                Conta::sacar(valor);
            } else {
                float restante = valor - getSaldo();
                Conta::sacar(getSaldo());
                limiteUtilizado += restante;
            }
            return true;
        } else {
            std::cout << "Saldo e limite insuficientes!" << std::endl;
            return false;
        }
    }

    float getLimite() const {
        return limite;
    }

    float getLimiteUtilizado() const {
        return limiteUtilizado;
    }
};

int main() {
    float saldoInicial, limiteInicial;
    int numMovimentacoes, tipoMovimentacao;
    float valor;

    // Interação com o usuário para a classe Conta
    std::cin >> saldoInicial;
    Conta conta(saldoInicial);

    std::cin >> numMovimentacoes;

    for (int i = 0; i < numMovimentacoes; ++i) {
        std::cin >> tipoMovimentacao;
        std::cin >> valor;

        if (tipoMovimentacao == 1) {
            conta.depositar(valor);
        } else if (tipoMovimentacao == 2) {
            conta.sacar(valor);
        }
    }

    std::cout << "Saldo atual da Conta: " << conta.getSaldo() << std::endl;

    // Interação com o usuário para a classe ContaCorrente
    std::cin >> saldoInicial;
    std::cin >> limiteInicial;
    ContaCorrente contaCorrente(saldoInicial, limiteInicial);

    std::cin >> numMovimentacoes;

    for (int i = 0; i < numMovimentacoes; ++i) {
        std::cin >> tipoMovimentacao;
        std::cin >> valor;

        if (tipoMovimentacao == 1) {
            contaCorrente.depositar(valor);
        } else if (tipoMovimentacao == 2) {
            contaCorrente.sacar(valor);
        }
    }

    std::cout << "Saldo atual da Conta Corrente: " << contaCorrente.getSaldo() << std::endl;
    std::cout << "Limite utilizado da Conta Corrente: " << contaCorrente.getLimiteUtilizado() << std::endl;

    return 0;
}