#include "classe_loja.h"
#include "cliente.h"
#include "classe_produto.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <limits> 
#include <climits>
#include "validacoes.cpp"
using namespace std;



Loja::Loja() : totalProdutos(0),  totalClientes(0)
{
	Produto prod1("Camisa Nike", 10, 15.00);
	Produto prod2("Tenis Adidas", 20, 45.00);
	Produto prod3("Calça Puma", 13, 25.00);
	Produto prod4("Moleto S/M", 5, 10.00);

	Cliente clien1("Luan", 961624758, "rua A");
	Cliente clien2("hiago", 896162568, "rua b");
	Cliente clien3("Felipe", 654324758, "rua c");
	Cliente clien4("rodrigues", 348524758, "rua d");

	armazenarProduto(prod1);
	armazenarProduto(prod2);
	armazenarProduto(prod3);
	armazenarProduto(prod4);


	ArmazenarCliente(clien1);
	ArmazenarCliente(clien2);
	ArmazenarCliente(clien3);
	ArmazenarCliente(clien4);
}
// Clientes


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
        cout << "Nome: " << nome << " | Quantidade: " << quantidade << " | Preço: €"  << preco << endl;

        cout << "Deseja Criar o produto? (s|n) \n";
        cin >> cond;
        cin.ignore();

        if (cond == 's' || cond == 'S') {

            Produto novoPro(nome, quantidade,preco);
			armazenarProduto(novoPro);
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

        int remProd = procurarProduto(idProduto);
        if (remProd >= 0) {
			cout << "Produto  a ser excluido é: \n" 
				<< "ID " << vecProdutos[remProd].getId() << " | "
				<< "Nome "<< vecProdutos[remProd].getNome() << " | "
				<< "Quantidade " << vecProdutos[remProd].getQuantidade() << " | "
				<< "Preço € " << vecProdutos[remProd].getPreco() << endl;
            cout << "Deseja realmente excluir o produto? (s/n) ";
            cin >> valid;
            if (valid == 's' || valid == 'S') {
                for (int i = remProd; i < totalProdutos - 1; i++) {
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
            cout << "Id inválido. Digite um número positivo: ";
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
// Clientes
void Loja::criarCliente()
{
	system("cls"); 
	string nome,telefone,morada;
	char valid4, cond;

	cin.ignore();
	do
	{
		cout << "________________________________________" << endl;
        cout << "              Criar Cliente             " << endl;
        cout << "________________________________________" << endl;

		cout << "Nome do Cliente: ";
        getline(cin, nome);

		cout << "Telefone: ";
		getline(cin, telefone);
		if(validarTelefone(telefone)){
			cout << "Número de telefone válido." << endl;
    	} else {
        	cout << "Número de telefone inválido." << endl;
		}    	
	

		cout << "Morada: ";
		getline(cin, morada);

		cout << "\nDetalhes do Cliente:\n";
		cout << "Nome: " << nome << " | Telefone: " << telefone << " | morada: "  << morada<< endl;

		cout << "Deseja Criar o Cliente? (s|n) \n";
		cin >> cond;
		cin.ignore();

		if (cond == 's' || cond == 'S') {
			
			Cliente novoCliente(nome, telefone, morada);
            ArmazenarCliente(novoCliente);
			cout << "Cliente criado com sucesso!" << endl;
		} else {
			cout << "Cliente não foi criado! \n";
		}

		cout << "Deseja criar mais um cliente? (s|n) \n";
		cin >> valid4;
		cin.ignore();

		
	} while (valid4 == 's' || valid4 == 'S');
	
}

void Loja::EliminarCliente()
{
	system("cls"); 
    char valid, valid2;
    do {
        if (totalProdutos == 0) {
            cout << "Nenhum produto no estoque.\n";
            return;
        }
        impriTodosProd();

        int idCliente;
        cout << "Qual o ID do produto: ";
        while (!(cin >> idCliente) || idCliente <= 0) {
            cout << "ID inválida. Digite um número positivo: ";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }

        int remClie = procurarProduto(idCliente);
        if (remClie >= 0) {
			cout << "Cliente a ser removido: \n" 
				<< "ID " << vecClientes[remClie].getid() << " | "
				<< "Nome "<< vecClientes[remClie].getnome() << " | "
				<< "Telefone " << vecClientes[remClie].gettelefone() << " | "
				<< "Morada " << vecClientes[remClie].getmorada() << endl;
            cout << "Deseja realmente remover o cliente? (s/n) ";
            cin >> valid;
            if (valid == 's' || valid == 'S') {
                for (int i = remClie; i < totalClientes - 1; i++) {
                    vecClientes[i] = vecClientes[i + 1];
                }
                totalClientes--; 
                cout << "Cliente removido com sucesso!\n";
            }
        } else {
            cout << "Cliente não encontrado.\n";
        }
        
        cout << "Deseja remover mais algum cliente? (s/n) ";
        cin >> valid2;
    } while (valid2 == 's' || valid2 == 'S');
}

int Loja::ProcurarCliente(int idCliente)
{
	for (int i = 0; i < totalClientes; i++){
	
		if(vecClientes[i].getid() == idCliente){	
		return i;	
		}
		
	}
	return -1;
	
}

void Loja::ImprimirTodosClientes()
{
	if(totalClientes == 0){
		cout << "Nenhum Cliente encontrado. " << endl;
		return;
	}
	cout << "________________________________________" << endl;
    cout << "              Clientes                  " << endl;
    cout << "________________________________________" << endl;

	for(int i = 0; i < totalClientes;i++){
		cout << "ID " << vecClientes[i].getid() << " | "
			 << "Nome "<< vecClientes[i].getnome() << " | "
			 << "Telefone " << vecClientes[i].gettelefone() << " | "
			 << "Morada " << vecClientes[i].getmorada() << endl;
	}
}

void Loja::ArmazenarCliente(const Cliente &Cliente)
{
	if(totalClientes >= 100) {
		cout << "Limite de Cadastros atingido!! \n";
		return;
	}	
	vecClientes[totalClientes] = Cliente;
	totalClientes++;
	return;
}
