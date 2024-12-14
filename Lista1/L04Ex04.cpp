#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    class Retangulo {
        public:
  
        float largura;
        float altura;

        void lerAtributos();
        float calcularArea();
        void exibirValores();

    };

    void Retangulo::lerAtributos() {

        scanf("%f", &largura);

        scanf("%f", &altura);

    }

    float Retangulo::calcularArea() {

        return largura * altura;

    }

    void Retangulo::exibirValores() {

        printf("Largura: %.2f, Altura: %.2f\n", largura, altura);

        printf("Area do retangulo: %.2f", calcularArea());
    }

    int main() {

        Retangulo p;

        p.lerAtributos();

        p.exibirValores();

        return 0;
    }