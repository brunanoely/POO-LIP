#include <iostream>
#include <iomanip>

using namespace std;

    class Circulo {
        public:
  
        float raio;

        void lerRaio();
        float calcularCircunferencia(float);
        void exibirValores(float);

    };

    void Circulo::lerRaio() {
        
        cin >> raio;

    }

    float Circulo::calcularCircunferencia(float pi) {

        return 2.00 * pi * (float)raio;

    }

    void Circulo::exibirValores(float pi) {

        cout << "Raio:" << fixed << setprecision(2) << raio << endl;

        cout << "Circunferencia do circulo: " << fixed << setprecision(2) << calcularCircunferencia(pi) << endl;

    }

    int main() {

        Circulo p;
        float pi = 3.1415;

        p.lerRaio();

        p.exibirValores(pi);

        return 0;
    }