#include <iostream>
#include <string>

using namespace std;

class Carro
{
private:
    string marca;
    int ano;

public:
    Carro(string m, int a) : marca(m), ano(a) {}

    string getMarca()
    {
        return marca;
    }

    void setMarca(string m)
    {
        marca = m;
    }

    int getAno()
    {
        return ano;
    }

    void setAno(int a)
    {
        ano = a;
    }
};

int main()
{
    string marca;
    int ano;

    cin >> marca;
    cin >> ano;

    Carro carro(marca, ano);

    cout << "Detalhes iniciais do carro:" << endl;
    cout << "Marca: " << carro.getMarca() << endl;
    cout << "Ano: " << carro.getAno() << endl;

    cin >> marca;
    carro.setMarca(marca);

    carro.setAno(carro.getAno() + 1);

    cout << "Detalhes modificados do carro:" << endl;
    cout << "Marca: " << carro.getMarca() << endl;
    cout << "Ano: " << carro.getAno() << endl;

    return 0;
}
