#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Animal {
public:
    virtual ~Animal() = default;
    virtual void emitirSom() const = 0;
    void exibirSom() const {
        emitirSom();
    }
};

class Cachorro : public Animal {
public:
    void emitirSom() const override {
        cout << "O cachorro faz: Au Au!" << endl;
    }
};

class Gato : public Animal {
public:
    void emitirSom() const override {
        cout << "O gato faz: Miau!" << endl;
    }
};

void reproduzirSons(const vector<unique_ptr<Animal>>& listaAnimais) {
    cout << "Emitindo sons dos animais:" << endl;
    for (const auto& animal : listaAnimais) {
        animal->exibirSom();
    }
}

int main() {
    vector<unique_ptr<Animal>> listaAnimais;
    int escolha;

    while (true) {
        cin >> escolha;

        if (escolha == 1) {
            listaAnimais.push_back(make_unique<Cachorro>());
        } else if (escolha == 2) {
            listaAnimais.push_back(make_unique<Gato>());
        } else if (escolha == 3) {
            break;
        } else {
            cout << "Opção inválida. Tente novamente." << endl;
        }
    }

    reproduzirSons(listaAnimais);

    return 0;
}
