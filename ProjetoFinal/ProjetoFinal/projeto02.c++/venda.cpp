#include "venda.h"
#include <set>
#include <random>
#include <chrono>
#include "classe_loja.h"
#include "classe_produto.h"

using namespace std;

Vendas::Vendas() : TotalVenda(0)
{

}

void Vendas::EfetuarVenda(Loja& loja)
{
    system ("cls");
    cout << "________________________________________" << endl;
    cout << "            Vendas de Produto           " << endl;
    cout << "________________________________________" << endl;
    cout << "                                        " << endl;
    //Imprimiri todos os produtos da Loja
    loja.impriTodosProd();

}

int Vendas::NumVencedor()
{
    //para gerar numero vencedor e do cliente
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrib(1000, 9999);
    long long numero;
    do {
        numero = distrib(gen);
    } while (numero <= 0);
    return (numero < 0) ? -numero : numero;
}

int Vendas::Numfatura()
{
    //gera numero da fatura
    random_device rd;
    mt19937 ger(rd());
    uniform_int_distribution<int> distrib(1000, 9999);
    long long numero;
    do {
        numero = distrib(ger);
    } while (numero <= 0);
    //operador ternario usado para no caso de ser negativo retornar sempre positivo
    return (numero < 0) ? -numero : numero;
}
