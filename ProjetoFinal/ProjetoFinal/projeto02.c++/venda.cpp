#include "venda.h"
#include <set>
#include <random>
#include <chrono>
#include "classe_loja.h"
#include "classe_produto.h"

using namespace std;

Vendas::Vendas() : TotalVendas(0)
{

}
void Vendas::ArmazenarProVendas(const Produto& Produto)
{
	if(TotalVendas >= 100) {
		cout << "Estoque esta Cheio!! \n";
		return;
	}	
	vecVendas[TotalVendas] = Produto;
	TotalVendas++;
	return;
  
    
}

void Vendas::EfetuarVenda(Loja& loja)
{
    int idproduto, quantProdu;
    char valid;
    system ("cls");
    cout << "________________________________________" << endl;
    cout << "            Vendas de Produto           " << endl;
    cout << "________________________________________" << endl;
    cout << "                                        " << endl;
    //Imprimiri todos os produtos da Loja
    loja.impriTodosProd();
    
    
    do
    {
           
        cout << "Id do produto que deseja: \n";
            while (!(cin >> idproduto) || idproduto <= 0) {
                cout << "Id inválido. Digite um número positivo: ";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
        
        }
        Produto* posicao = loja.procurarProduto(idproduto);
        if (posicao == nullptr)
        {
            cout << "Produto não encontrado! \n";
            return;
        }else{                 

            cout << "Quantidade que deseja \n";
            cin >> quantProdu;
            while (cin.fail() || quantProdu <= 0 || cin.peek() != '\n')
            //cin.peek() != '\n': Verifica se há restos na entrada, impedindo números decimais
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Quantidade invalida." << endl;
                cout << "Qual a quantidade: ";
                cin >> quantProdu;
            }  
            if(quantProdu > posicao->getQuantidade()) {
                cout << "Nao tem essa quantidade de produto no estoque. \n";
            }else{
                posicao->setQuantidade(posicao->getQuantidade() - quantProdu);
                ArmazenarProVendas(*posicao);
            }
            
        }


 
    cout << "Deseja adicionar mais produtos? (s|n) \n";
    cin >> valid;
    cin.ignore();

    } while (valid == 's' || valid =='S');

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
