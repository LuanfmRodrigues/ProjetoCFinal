#include <iostream>
#include <locale>
#include "classe_produto.h" 
#include "classe_loja.h"  
#include "cliente.h"  
#include "venda.h"
#include "classe_produto.cpp"
#include "classe_loja.cpp"
#include "cliente.cpp"
#include "venda.cpp"
#include "validacoes.cpp"



void menuVendas(Loja& loja)
{
	system("cls");
	int sel;
	do
	{	
		cout << "|========================================================|" << endl;
		cout << "|                      OPEN BOX CROSSFIT                 |" << endl;
		cout << "|========================================================|" << endl;
		cout << "|                        MENU VENDAS                     |" << endl;
		cout << "|========================================================|" << endl;
		cout << "|           Selecione a opcao para continuar:            |" << endl;
		cout << "|========================================================|" << endl;
		cout << "|              1 - Stock Produtos                        |" << endl;
		cout << "|              2 - Lista atletas                         |" << endl;
		cout << "|              3 - Adicionar Atleta                      |" << endl;
		cout << "|              4 - Vendas                                |" << endl;
		cout << "|              5 - Voltar                                |" << endl;
		cout << "|========================================================|" << endl;
		cin >> sel;
		switch (sel)
		{
		case 1:
			loja.impriTodosProd();
			break;
		case 2:
			loja.ImprimirTodosClientes();
			break;		
		case 3:
			loja.criarCliente();
			break;				
		case 4:
			loja.EfetuarVenda();
			break;
		case 5:
		cout << "|Sair.                                                   |" << endl;
		cout << "|========================================================|" << endl;
			break;
		default:
		cout << "|Opcao invalida!                                         |" << endl;
		cout << "|========================================================|" << endl;
			break;
		}

		
	} while (sel != 5);
	
}
void menuStock(Loja& loja) 
{

	int sel2;
	do
	{
		system("cls");
		cout << "|========================================================|" << endl;
		cout << "|                      OPEN BOX CROSSFIT                 |" << endl;
		cout << "|========================================================|" << endl;
		cout << "|                        MENU STOCK                      |" << endl;
		cout << "|========================================================|" << endl;
		cout << "|           Selecione a opcao para continuar:            |" << endl;
		cout << "|========================================================|" << endl;
		cout << "|              1 - Criar o Produto                       |" << endl;
		cout << "|              2 - Adicionar Produto Existente           |" << endl;
		cout << "|              3 - Excluir Produto                       |" << endl;
		cout << "|              4 - Stock                                 |" << endl;
		cout << "|              5 - Voltar                                |" << endl;
		cout << "|========================================================|" << endl;
		cin >> sel2;
		switch (sel2)
		{
		case 1:
			loja.criarProduto();
			break;
		case 2:
			loja.addProExiste();
			break;
		case 3:
			loja.RemoverProduto();
			break;
		case 4:
			loja.impriTodosProd();			
			break;
		case 5:
			cout << "|Sair.                                                   |" << endl;
			cout << "|========================================================|" << endl;
			break;
		default:
			cout << "|Opcao invalida!                                         |" << endl;
			cout << "|========================================================|" << endl;
			break;
		}
	} while (sel2 != 5);

}

void menuRelatorio(Loja& loja) {

	int sel3;
	do
	{
		system("cls");
		cout << "|========================================================|" << endl;
		cout << "|                      OPEN BOX CROSSFIT                 |" << endl;
		cout << "|========================================================|" << endl;
		cout << "|                       MENU RELAToRIO                   |" << endl;
		cout << "|========================================================|" << endl;
		cout << "|             Selecione a opcao para continuar:          |" << endl;
		cout << "|========================================================|" << endl;
		cout << "|             1 - Produto Mais Vendido                   |" << endl;
		cout << "|             2 - Produto Menos vendido                  |" << endl;
		cout << "|             3 - Lucro por produto                      |" << endl;
		cout << "|             4 - Atleta que mais comprou                |" << endl;
		cout << "|             5 - Voltar                                 |" << endl;
		cout << "|========================================================|" << endl;
		cin >> sel3;
		switch (sel3)
		{
		case 1:
			//venda.relatorioStock();
			break;
		case 2:
			//venda.relatorioProduto();
			break;
		case 3:
			//venda.relatoriVendas();
			break;
		case 4:
			loja.ClienteMaisComprou();
			break;
		case 5:
			cout << "|Sair.                                                   |" << endl;
			cout << "|========================================================|" << endl;
			break;
		default:
			cout << "|Opcao invalida!                                         |" << endl;
			cout << "|========================================================|" << endl;
			break;
		}
	} while (sel3 != 5);
}

void menuCLiente(Loja& loja) {  

	int sel4;
	do
	{	
		system("cls");
		cout << "|========================================================|" << endl;
		cout << "|                      OPEN BOX CROSSFIT                 |" << endl;
		cout << "|========================================================|" << endl;
		cout << "|                        MENU Atletas                    |" << endl;
		cout << "|========================================================|" << endl;
		cout << "|           Selecione a opcao para continuar:            |" << endl;
		cout << "|========================================================|" << endl;
		cout << "|              1 - Criar ficha do Atleta                 |" << endl;
		cout << "|              2 - Eliminar Atleta                       |" << endl;
		cout << "|              3 - Editar Atleta                         |" << endl;
		cout << "|              4 - Atletas                               |" << endl;
		cout << "|              5 - Voltar                                |" << endl;
		cout << "|========================================================|" << endl;
		cin >> sel4;
		switch (sel4)
		{
		case 1:
			loja.criarCliente();
			break;
		case 2:
			loja.EliminarCliente();
			break;
		case 3:
			loja.EditarCliente();			
			break;
		case 4:
			loja.ImprimirTodosClientes();
			
			break;
		case 5:
			cout << "|Sair.                                                   |" << endl;
			cout << "|========================================================|" << endl;
			break;
		default:
			cout << "|Opcao invalida!                                         |" << endl;
			cout << "|========================================================|" << endl;
			break;
		}
	} while (sel4 != 5);
}

void menuPrincipal(Loja& loja) { 

	int sel1;
	do
	{
		system("cls");
		cout << "|========================================================|" << endl;
		cout << "|            Bem-vindo ao sistema Open Box CrossFit!     |" << endl;
		cout << "|========================================================|" << endl;
		cout << "|                       MENU PRINCIPAL                   |" << endl;
		cout << "|========================================================|" << endl;
		cout << "|           Selecione a opcao para continuar:            |" << endl;
		cout << "|========================================================|" << endl;
		cout << "|                        1 - Vendas                      |" << endl;
		cout << "|                        2 - Stock                       |" << endl;
		cout << "|                        3 - Relatorio                   |" << endl;
		cout << "|                        4 - Atletas                     |" << endl;
		cout << "|                        5 - Sair                        |" << endl;
		cout << "|========================================================|" << endl;
		cin >> sel1;
		switch (sel1)
		{
		case 1:
			menuVendas(loja);  
			break;
		case 2:
			menuStock(loja);		
			break;
		case 3:
			menuRelatorio(loja);
			break;
		case 4:
			menuCLiente(loja);
			break;
		case 5:
		cout << "|Sair.                                                   |" << endl;
		cout << "|========================================================|" << endl;
			break;
		default:
		cout << "|Opcao invalida!                                         |" << endl;
		cout << "|========================================================|" << endl;
			break;
		}


	} while (sel1 != 5);
}


int main()  
{
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
	Loja loja;
	menuPrincipal(loja); 
	
     
    return 0; 
}
