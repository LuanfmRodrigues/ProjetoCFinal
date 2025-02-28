#include "classe_loja.h"
#include "classe_produto.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <limits> 
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

void Loja::criarProduto() {
	system("cls"); 
	string nome;
    char cond, valid1;
    int quantidade;
    float preco;

    cin.ignore();
    do {
        cout << "________________________________________" << endl;
        cout << "        Adicionar Novo Produto          " << endl;
        cout << "________________________________________" << endl;

        cout << "Nome do produto: ";
        getline(cin, nome);

        // Valida se a quantidade é um números positivos
        cout << "Quantidade: ";
        while (!(cin >> quantidade) || quantidade <= 0) {
            cout << "Quantidade inválida. Digite um número inteiro positivo: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpa a memoria temporaria
        }

        // Valida se o preço é um números positivos
        cout << "Preço: ";
        while (!(cin >> preco) || preco <= 0) {
            cout << "Preço inválido. Digite um valor positivo: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Produto: \n" << endl;
        cout << "Nome: " << nome << " | Quantidade: " << quantidade << " | Preço: €" << fixed << setprecision(2) << preco << endl;

        cout << "Deseja Criar o produto? (s|n) \n";
        cin >> cond;
        cin.ignore();

        if (cond == 's' || cond == 'S') {
            
            cout << "Produto adicionado com sucesso!" << endl;
        } else {
            cout << "Produto não foi criado! \n";
        }

        cout << "Deseja criar mais produtos? (s|n) \n";
        cin >> valid1;
        cin.ignore();

    } while (valid1 == 's' || valid1 == 'S');
}

void Loja::armazenarProduto(const Produto& Produto)
{
	if(totalProdutos >= 100) {
		cout << "Estoque esta Cheio!! \n";
		return;
	}	
	vecProdutos[totalProdutos] = Produto;
	totalProdutos++;
	return;
  
    
}

int Loja::procurarProduto(int idProduto)
{
	for (int i = 0; i < totalProdutos; i++)
	{
		if(vecProdutos[i].getId() == idProduto){	
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
	system("cls"); 
    char valid, valid2;
    do {
        if (totalProdutos == 0) {
            cout << "Nenhum produto no estoque.\n";
            return;
        }
        impriTodosProd();

        int idProduto;
        cout << "Qual o ID do produto: ";
        while (!(cin >> idProduto) || idProduto <= 0) {
            cout << "ID inválida. Digite um número positivo: ";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }

        int remPro = procurarProduto(idProduto);
        if (remPro >= 0) {
			cout << "Produto  a ser excluido é: \n" 
				<< "ID " << vecProdutos[remPro].getId() << " | "
				<< "Nome "<< vecProdutos[remPro].getNome() << " | "
				<< "Quantidade " << vecProdutos[remPro].getQuantidade() << " | "
				<< "Preço € " << vecProdutos[remPro].getPreco() << endl;
            cout << "Deseja realmente excluir o produto? (s/n) ";
            cin >> valid;
            if (valid == 's' || valid == 'S') {
                for (int i = remPro; i < totalProdutos - 1; i++) {
                    vecProdutos[i] = vecProdutos[i + 1];
                }
                totalProdutos--; 
                cout << "Produto removido com sucesso!\n";
            }
        } else {
            cout << "Produto não encontrado.\n";
        }
        
        cout << "Deseja remover mais algum produto? (s/n) ";
        cin >> valid2;
    } while (valid2 == 's' || valid2 == 'S');
}


void Loja::addProExiste()
{
	if (totalProdutos == 0) {
        cout << "Nenhum produto no estoque.\n";
        return;
    }
	cout << "_______________________________________________ \n";
	impriTodosProd();
	cout << "_______________________________________________ \n";
	char valid3;
	
	int posicao, novaQuant,idProduto;

	do
	{
		cout << "________________________________________" << endl;
		cout << "    Adicionar quantidade ao Produto     " << endl;
		cout << "________________________________________" << endl;

		cout << "ID do produto: ";
        while (!(cin >> idProduto) || idProduto <= 0) {
            cout << "Id inválida. Digite um número positivo: ";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }

		posicao = procurarProduto(idProduto);

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
	return ;


	

	
}
