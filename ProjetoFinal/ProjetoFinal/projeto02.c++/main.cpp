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
		cout << "______________________________________" << endl;
		cout << "               MENU VENDAS            " << endl;
		cout << "______________________________________" << endl;
		cout << "  Selecione a opcao para continuar:   " << endl;
		cout << "______________________________________" << endl;
		cout << "          1 - Stock Produtos          " << endl;
		cout << "          2 - Lista Clientes          " << endl;
		cout << "          3 - Criar Clientes          " << endl;
		cout << "              4 - Vendas              " << endl;
		cout << "              5 - sair                " << endl;
		cout << "______________________________________" << endl;
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
			cout << "Saindo..." << endl;
			break;
		default:
			cout << "Opcao invalida!" << endl;
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
		cout << "______________________________________" << endl;
		cout << "               MENU STOCK             " << endl;
		cout << "______________________________________" << endl;
		cout << "  Selecione a opcao para continuar:   " << endl;
		cout << "______________________________________" << endl;
		cout << "          1 - Criar o Produto         " << endl;
		cout << "     2 - Adicionar Produto Existente  " << endl;
		cout << "          3 - Excluir Produto         " << endl;
		cout << "              4 - Stock               " << endl;
		cout << "              5 - Voltar              " << endl;
		cout << "______________________________________" << endl;
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
			cout << "Saindo..." << endl;
			break;
		default:
			cout << "Opcao invalida!" << endl;
			break;
		}
	} while (sel2 != 5);

}

void menuRelatorio() {

	int sel3;
	do
	{
		
		cout << "______________________________________" << endl;
		cout << "           MENU RELAT�RIO             " << endl;
		cout << "______________________________________" << endl;
		cout << "Selecione a opcao para continuar: " << endl;
		cout << "______________________________________" << endl;
		cout << "         1 - Relat�rio Stock          " << endl;
		cout << " 2 - Relat�rio de Vendas por Produto  " << endl;
		cout << "    3 - Relat�rio Total de Vendas     " << endl;
		cout << "              4 - Voltar              " << endl;
		cout << "______________________________________" << endl;
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
			cout << "Saindo..." << endl;
			break;
		default:
			cout << "Opcao invalida!" << endl;
			break;
		}
	} while (sel3 != 4);
}

void menuCLiente(Loja& loja) {  

	int sel4;
	do
	{
		 
		cout << "______________________________________" << endl;
		cout << "             MENU CLIENTE             " << endl;
		cout << "______________________________________" << endl;
		cout << "  Selecione a opcao para continuar:   " << endl;
		cout << "______________________________________" << endl;
		cout << "           1 - Criar Cliente          " << endl;
		cout << "           2 - Excluir Cliente        " << endl;
		cout << "           3 - Editar CLiente         " << endl;
		cout << "           4 - Clientes               " << endl;
		cout << "           5 - Voltar                 " << endl;
		cout << "______________________________________" << endl;
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
			cout << "Saindo..." << endl;
			break;
		default:
			cout << "Opcao invalida!" << endl;
			break;
		}
	} while (sel4 != 5);
}

void menuPrincipal(Loja& loja) { 

	int sel1;
	do
	{
		system("cls");
		cout << "______________________________________" << endl;
		cout << "           MENU PRINCIPAL             " << endl;
		cout << "______________________________________" << endl;
		cout << "  Selecione a opcao para continuar:   " << endl;
		cout << "______________________________________" << endl;
		cout << "             1 - Vendas               " << endl;
		cout << "             2 - Stock                " << endl;
		cout << "             3 - Relatorio            " << endl;
		cout << "             4 - Cliente              " << endl;
		cout << "             5 - Sair                 " << endl;
		cout << "______________________________________" << endl;
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
			menuRelatorio();
			break;
		case 4:
			menuCLiente(loja);
			break;
		case 5:
			cout << "Saindo..." << endl;
			break;
		default:
			cout << "Opcao invalida!" << endl;
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
