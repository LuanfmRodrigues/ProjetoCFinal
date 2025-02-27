#include "classe_loja.h"
#include "classe_produto.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <climits>
using namespace std;



Loja::Loja() : totalProdutos(0)
{
	Produto prod1("Camisa Nike", 10, 15.00);
	Produto prod2("Tenis Adidas", 20, 45.00);
	Produto prod3("Calça Puma", 13, 25.00);
	Produto prod4("Moleto S/M", 5, 10.00);

	armazenarProduto(prod1);
	armazenarProduto(prod2);
	armazenarProduto(prod3);
	armazenarProduto(prod4);
}


// produtos

void Loja::criarProduto()
{
	if (totalProdutos >= 100) {
        cout << "Estoque esta Cheio!!\n";
        return;
    }

    string nome;
	char  cond, valid1;
    int quantidade;
    float preco;

    
	do
	{
		cout << "________________________________________" << endl;
		cout << "        Adicionar Novo Produto          " << endl;
		cout << "________________________________________" << endl;
		cout << "Nome do produto: ";
		cin.ignore();
		getline(cin, nome);
		cout << "Quantidade: ";
		cin >> quantidade;
		while (cin.fail() || quantidade <= 0) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Quantidade invalida.\n";
			cout << "Qual a quantidade: ";
			cin >> quantidade;
		}
		cout << "Preço: ";
		cin >> preco;

		cout << "Produto: \n" << endl;
		cout << "ID: " << totalProdutos + 1 << " | Nome: " << nome << " | Quantidade: " << quantidade << " | Preço: \n" << preco << endl;
		cout << "deseja Criar o produto? (s|n) \n";
		cin >> cond;
		if (cond == 's' || cond == 'S')
		{
			Produto novoProduto(nome, quantidade, preco);
			armazenarProduto(novoProduto);
			cout << "_______________________________" << endl;
			cout << "Produto adicionado com sucesso!" << endl;
			cout << "_______________________________" << endl;

			cout << "Por favor, insira os dados novamente.\n";
		}
		cout << "Deseja criar mais Produtos? (s|n) \n";
		cin >> valid1;

		


	} while (valid1 == 's' || valid1 == 'S');
	return 0;

			
    
}

void Loja::armazenarProduto(const Produto& Produto)
{
	if(totalProdutos >= 100) {
		cout << "Estoque esta Cheio!! \n";
		return;
	}	
	vecProdutos[totalProdutos] = Produto;
	totalProdutos++;
	cout << "Produto foi adicionado com sucesso!\n";
	return;
  
    
}

int Loja::procurarProduto(const string& Nome)
{
	for (int i = 0; i < totalProdutos; i++)
	{
		if(vecProdutos[i].getNome() == Nome){	
		return i;	
		}
		
	}
	return -1;
	
}

void Loja::impriTodosProd()
{
	if(totalProdutos == 0){
		cout << "Nenhum Produto cadastrado. " << endl;
		return;
	}
	cout << "________________________________________" << endl;
    cout << "              Produtos                  " << endl;
    cout << "________________________________________" << endl;

	for(int i = 0; i < totalProdutos;i++){
		cout << "ID " << vecProdutos[i].getId() << " | "
			 << "Nome "<< vecProdutos[i].getNome() << " | "
			 << "Quantidade " << vecProdutos[i].getQuantidade() << " | "
			 << "Preço € " << vecProdutos[i].getPreco() << endl;
	}
}

void Loja::RemoverProduto()
{
	char valid,valid2;
	do {

		if (totalProdutos == 0) {
			cout << "Nenhum produto no estoque.\n";
			return;
		}
		impriTodosProd();
		string Nome;
		cout << "Nome do produto a ser removido: ";
		cin.ignore();
		getline(cin, Nome);

		int remPro = procurarProduto(Nome);
		if (remPro >= 0) {
			for (int i = remPro; i < totalProdutos - 1; i++) {
				vecProdutos[i] = vecProdutos[i + 1];
				cout << remPro;
			}
			cout << "Deseja realmente Excluir o produto \n";
			cin >> valid;
			if (valid == 's' || valid == 'S') {
				vecProdutos[totalProdutos - 1] = Produto();
				totalProdutos--;
				cout << "Produto removido com Sucesso! " << endl;
			}

		}
		else
		{
			cout << "Produto nao encontrado " << endl;
		}
		cout << "Deseja remover mais algum produto (s\n) \n";
		cin >> valid2;
	}while (valid2 == 's' || valid2 == 'S');
	return 0;


	
}

void Loja::addProExiste()
{
	if (totalProdutos == 0) {
        cout << "Nenhum produto no estoque.\n";
        return;
    }
	char valid3;
	string nome;
	int posicao, novaQuant;

	do
	{
		cout << "________________________________________" << endl;
		cout << "    Adicionar quantidade ao Produto     " << endl;
		cout << "________________________________________" << endl;

		cout << "Nome do produto: ";
		cin.ignore();
		getline(cin, nome);

		posicao = procurarProduto(nome);

		if (posicao == -1)
		{
			cout << "Produto não encontrado! \n";
			return;
		}

		cout << "Quantidade a mais: ";
		cin >> novaQuant;
		while (cin.fail() || novaQuant <= 0)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Quantidade invalida." << endl;
			cout << "Qual a quantidade: ";
			cin >> novaQuant;
		}
		vecProdutos[posicao].setQuantidade(vecProdutos[posicao].getQuantidade() + novaQuant);
		cout << "Quantidade Adicionada com sucesso!!! \n" << endl;
		cout << "Deseja adcionar quantidade a mais? (s|n) \n";
		cin >> valid3;
	} while (valid3 == 's' || valid3 == 'S');
	return 0;


	

	
}
