#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

class Animal {
    private:
    string nome;

    public:
    Animal();
    Animal(string nome) {
        this->nome = nome;
    }

    string getNome() const {
        return nome;
    }

    void setNome(string novoNome) {
        nome = novoNome;
    }

    void imprimirAnimal() {
        cout << "Dados do Animal:" << endl;
        cout << "Nome: " << nome << endl;
    }
};

class Cachorro : public Animal {
    private:
    string raca;

    public:
    Cachorro();
    Cachorro(string raca) {
        this->raca = raca;
    }

     string getRaca() const {
        return raca;
    }

    void setRaca(string novaRaca) {
        raca = novaRaca;
    }

    void imprimirRaca() {
        Animal::imprimirAnimal();
        cout << "Raca: " << raca << endl;
    }
};

Animal:: Animal() : nome("Duque") {}
Cachorro:: Cachorro() : raca("Indefinido") {}

int main () {

    Animal animal;
    Cachorro cachorro;

    string nome, raca;

    cin >> nome;
    animal.setNome(nome);
    animal.imprimirAnimal();

    cachorro.imprimirRaca();
    cin >> nome;
    cachorro.setNome(nome);
    cin >> raca;
    cachorro.setRaca(raca);
    cachorro.imprimirRaca();

    return 0;
}