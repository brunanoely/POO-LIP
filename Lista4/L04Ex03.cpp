#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

class Funcionario {
    private:
    string nome;
    float salario;
    
    public:

    Funcionario();
    Funcionario(string nome, float salario) {
        this->nome = nome;
        this->salario = salario;
    }

    string getNome() const {
        return nome;
    }

    void setNome(string novoNome) {
        nome = novoNome;
    }

    float getSalario() const {
        return salario;
    }

    void setSalario(float novoSalario) {
        salario = novoSalario;
    }

    void imprimirFuncionario() {
        cout << "Dados do Funcionario:" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Salario: " << fixed << setprecision(2) << salario << endl;
    }
};

class Gerente: public Funcionario {
    private:
    float bonus;

    public:

    Gerente();
    Gerente(float bonus) {
        this->bonus = bonus;
    }

    float getBonus() const {
        return bonus;
    }

    void setBonus(float newBonus) {
        bonus = newBonus;
    }

    void imprimirGerente() {
        Funcionario::imprimirFuncionario();
        cout << "Bonus Gerente: " << fixed << setprecision(2)  << bonus << endl;
    }
};

Funcionario:: Funcionario(): nome(""), salario(0) {}
Gerente:: Gerente() : bonus(0) {}

int main() {
    Funcionario funcionario;
    Gerente gerente;

    string nome;
    float salario, bonus;

    getline(cin, nome);
    funcionario.setNome(nome);
    cin >> salario;
    funcionario.setSalario(salario);
    

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    getline(cin, nome);
    gerente.setNome(nome);
    cin >> salario;
    gerente.setSalario(salario);
    cin >> bonus;
    gerente.setBonus(bonus);
    
    funcionario.imprimirFuncionario();

    gerente.imprimirGerente();


    return 0;
}