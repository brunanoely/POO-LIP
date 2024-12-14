#include <iostream>
#include <vector>
#include <iomanip> on
using namespace std;

class Funcionario {
public:
    virtual double calcularSalario() const = 0;
    void imprimirSalario() const {
        cout << "Salario: " << fixed << setprecision(2) << calcularSalario() << endl;
    }
    virtual ~Funcionario() {}
};

class Vendedor : public Funcionario {
private:
    double salarioBase;
    double comissao;
public:
    Vendedor(double salarioBase, double comissao) : salarioBase(salarioBase), comissao(comissao) {}
    double calcularSalario() const override {
        return salarioBase + comissao;
    }
};

class Freelancer : public Funcionario {
private:
    double valorHora;
    int horasTrabalhadas;
public:
    Freelancer(double valorHora, int horasTrabalhadas) : valorHora(valorHora), horasTrabalhadas(horasTrabalhadas) {}
    double calcularSalario() const override {
        return valorHora * horasTrabalhadas;
    }
};

int main() {
    int numFuncionarios;
    cin >> numFuncionarios;

    vector<Funcionario*> funcionarios;

    for (int i = 0; i < numFuncionarios; ++i) {
        int tipo;
        cin >> tipo;

        if (tipo == 1) {
            double salarioBase, comissao;
            cin >> salarioBase;
            cin >> comissao;
            funcionarios.push_back(new Vendedor(salarioBase, comissao));
        } else if (tipo == 2) {
            double valorHora;
            int horasTrabalhadas;
            cin >> valorHora;
            cin >> horasTrabalhadas;
            funcionarios.push_back(new Freelancer(valorHora, horasTrabalhadas));
        }
    }

    double salarioTotal = 0;
    cout << "Dados dos Funcionarios:" << endl;
    for (const auto& funcionario : funcionarios) {
        funcionario->imprimirSalario();
        salarioTotal += funcionario->calcularSalario();
    }

    cout << "Salario total de todos os funcionarios: " << fixed << setprecision(2) << salarioTotal << endl;

    for (auto& funcionario : funcionarios) {
        delete funcionario;
    }

    return 0;
}