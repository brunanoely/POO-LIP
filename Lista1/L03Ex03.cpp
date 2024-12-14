#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    class Retangulo {
        public:
  
        int largura;
        int altura;

        void calcularArea();
    };

    void Retangulo::calcularArea() {

        int area = largura * altura;

        printf("%d", area);

    }

    int main() {

        Retangulo p;

        int largura;
        int altura;
        
        scanf("%d", &p.largura);
        scanf("%d", &p.altura);

        p.calcularArea();

        return 0;
    }