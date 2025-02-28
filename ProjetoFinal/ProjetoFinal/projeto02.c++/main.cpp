#include <iostream>
#include <locale>
#include "classe_produto.h"
#include "classe_produto.cpp"
#include "Classe_loja.cpp"
#include "classe_loja.h"
#include "cliente.h"
#include "cliente.cpp"


void menuStock(Loja& loja) 
{

	int sel2;
	do
	{
		cout << "______________________________________" << endl;
		cout << "               MENU STOCK             " << endl;
		cout << "______________________________________" << endl;
		cout << "Selecione a opcao para continuar: " << endl;
		cout << "______________________________________" << endl;
		cout << "        1 - Cria��o de Produto        " << endl;
		cout << "     2 - Adicionar Produto Existente  " << endl;
		cout << "          3 - Excluir Produto         " << endl;
		cout << "              4 - Voltar              " << endl;
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
			cout << "Saindo..." << endl;
			break;
		default:
			cout << "Opcao invalida!" << endl;
			break;
		}
	} while (sel2 != 4);

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
			//relatorio stock
			break;
		case 2:
			//vendas por produto
			break;
		case 3:
			//total vendas
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
		system("cls");  
		cout << "______________________________________" << endl;
		cout << "             MENU CLIENTE             " << endl;
		cout << "______________________________________" << endl;
		cout << "  Selecione a opcao para continuar: "   << endl;
		cout << "______________________________________" << endl;
		cout << "           1 - Criar Cliente          " << endl;
		cout << "           2 - Excluir Cliente        " << endl;
		cout << "           3 - Editar CLiente         " << endl;
		cout << "           4 - Voltar                 " << endl;
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
			 
			break;
		case 4:
			cout << "Saindo..." << endl;
			break;
		default:
			cout << "Opcao invalida!" << endl;
			break;
		}
	} while (sel4 != 4);
}

void menuPrincipal(Loja& loja) { 


	int sel1;
	do
	{
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
			//efetuarVenda();   
			break;
		case 2:
			menuStock(loja);		
			break;
		case 3:
			    
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
    setlocale(LC_ALL, "portuguese");
	Loja loja;
	menuPrincipal(loja); 
	
     
    return 0; 
}
