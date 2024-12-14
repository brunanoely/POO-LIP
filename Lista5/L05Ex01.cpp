#include <iostream>
#include <cmath>
#include <iomanip>

class Forma {
public:
    virtual double calcularArea() const = 0;

    void imprimirArea() const {
        std::cout << "Area: " << calcularArea() << std::endl;
    }
};

class Circulo : public Forma {
private:
    double raio;

public:
    Circulo(double r) : raio(r) {}

    double calcularArea() const override {
        return M_PI * raio * raio;
    }
};

class Retangulo : public Forma {
private:
    double largura;
    double altura;

public:
    Retangulo(double l, double a) : largura(l), altura(a) {}

    double calcularArea() const override {
        return largura * altura;
    }
};

int main() {
    double raio, largura, altura;
    std::cin >> raio;
    Circulo circulo(raio);

    std::cin >> largura >> altura;
    Retangulo retangulo(largura, altura);

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Dados do Circulo:" << std::endl;
    circulo.imprimirArea();

    std::cout << "Dados do Retangulo:" << std::endl;
    retangulo.imprimirArea();

    return 0;
}