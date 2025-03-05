#include "classe_loja.h"

using namespace std;



Loja::Loja() :  totalProdutos(0) ,totalClientes(0)
{
	Produto prod1("Camisa Nike", 10, 15.00);
	Produto prod2("Tenis Adidas", 20, 45.00);
	Produto prod3("Calça Puma", 13, 25.00);
	Produto prod4("Moleto S/M", 5, 10.00);

	Cliente clien1("Luan", "961624758", "rua A");
	Cliente clien2("Hiago", "896162568", "rua b");
	Cliente clien3("Felipe", "654324758", "rua c");
	Cliente clien4("rodrigues", "348524758", "rua d");

	armazenarProduto(prod1);
	armazenarProduto(prod2);
	armazenarProduto(prod3);
	armazenarProduto(prod4);


	ArmazenarCliente(clien1);
	ArmazenarCliente(clien2);
	ArmazenarCliente(clien3);
	ArmazenarCliente(clien4);
}

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
        while (!(cin >> quantidade) || quantidade <= 0 || cin.peek() != '\n') {
			//cin.peek() != '\n': Verifica se há restos na entrada, impedindo números decimais
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

        cout << "Produto criado: \n" << endl;
        cout << "Nome: " << nome << " | Quantidade: " << quantidade << " | Preço: €"  << preco << endl;

        cout << "Deseja Criar o produto? (s|n) \n";
        cin >> cond;
        cin.ignore();

        if (cond == 's' || cond == 'S') {

            Produto totalProdutos(nome, quantidade,preco);
			armazenarProduto(totalProdutos);
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
Produto* Loja::procurarProduto(int id) {
    for (auto& produto : vecProdutos) {
        if (produto.getId() == id) {
            return &produto;  // Retorna um ponteiro para o objeto Produto
        }
    }
    return nullptr;  // Retorna nullptr se o produto não for encontrado
}


int Loja::procurarProdutoid(int idProduto)
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
	system("cls"); 
	
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
	system("pause"); 

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

        int remProd = procurarProdutoid(idProduto);
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
	cout << "________________________________________" << endl;
	cout << "                                        " << endl;
	impriTodosProd();
	cout << "                                        " << endl;
	cout << "________________________________________" << endl;
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

		posicao = procurarProdutoid(idProduto);

		if (posicao == -1)
		{
			cout << "Produto não encontrado! \n";
			return;
		}else{			
			cout << "Produto  a ser excluido é: \n" 
				<< "ID " << vecProdutos[posicao].getId() << " | "
				<< "Nome "<< vecProdutos[posicao].getNome() << " | "
				<< "Quantidade " << vecProdutos[posicao].getQuantidade() << " | "
				<< "Preço € " << vecProdutos[posicao].getPreco() << endl;;
			
		}

		cout << "Quantidade a mais: ";
		cin >> novaQuant;
		while (cin.fail() || novaQuant <= 0 || cin.peek() != '\n')
		//cin.peek() != '\n': Verifica se há restos na entrada, impedindo números decimais
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Quantidade invalida." << endl;
			cout << "Qual a quantidade: ";
			cin >> novaQuant;
		}
		vecProdutos[posicao].setQuantidade(vecProdutos[posicao].getQuantidade() + novaQuant);
		cout << "Quantidade Adicionada com sucesso!!! \n" << endl;
		cout << "Deseja adicionar quantidade a mais? (s|n) \n";
		cin >> valid3;
	} while (valid3 == 's' || valid3 == 'S');
	return ;


	

	
}

/*int Loja::procurarProduto(int posicao) 
{
    if (posicao >= 0 && posicao < totalProdutos) {
        return &vecProdutos[posicao]; // Retorna o produto se a posição for válida
    }
    // Retorna um produto inválido 
    return nullptr; // Produto inválido
}*/
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
        while (true) {
            getline(cin, telefone);  // vai Lê o telefone como string para facilitar a validação.
			// foi dificil isso.
            // Valida o telefone
            if (validarTelefone(telefone)) {
                break;  // Sai do loop se o telefone for válido
            } else {
                cout << "Número de telefone inválido. O telefone deve ter 9 dígitos numéricos." << endl;
                cout << "Digite novamente: ";
            }
        }
   	
	

		cout << "Morada: ";
		getline(cin, morada);

		cout << "\nDetalhes do Cliente:\n";
		cout << "Nome: " << nome << " | Telefone: " << telefone << " | Morada: "  << morada<< endl;

		cout << "Deseja Criar o Cliente? (s|n) \n";
		cin >> cond;
		cin.ignore();

		if (cond == 's' || cond == 'S') {
			
			
			Cliente totalClientes(nome, telefone, morada);
            ArmazenarCliente(totalClientes);
			cout << "Cliente criado com sucesso!" << endl;
		} else {
			cout << "Cliente não foi criado! \n";
		}

		cout << "Deseja criar mais um cliente? (s|n) \n";
		cin >> valid4;
		cin.ignore();

		
	} while (valid4 == 's' || valid4 == 'S');
	
}

void Loja::EditarCliente()
{
	if (totalClientes == 0) {
        cout << "Nenhum cliente encontrado.\n";
        return;
	
    }
	string NovoNome;
	int  idcliente, posicao;
	char valid;

	cout << "________________________________________" << endl;
	cout << "                                        " << endl;
	ImprimirTodosClientes();
	cout << "                                        " << endl;
	cout << "________________________________________" << endl;
	do
	{
		cout << "________________________________________" << endl;
		cout << "             Editar cliente             " << endl;
		cout << "________________________________________" << endl;

		cout << "ID do Cliente: ";
        while (!(cin >> idcliente) || idcliente <= 0) {
            cout << "Id inválido. Digite um número positivo: ";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
			
        }
		posicao = ProcurarCliente(idcliente);

		if(posicao == -1)
		{
			cout << "Cliente não encontrado!! ";
			return;
		}else{	
				
			cout << "Cliente a ser editado: \n" 
				 << "ID " << vecClientes[posicao].getid() << " | "
				 << "Nome "<< vecClientes[posicao].getnome() << " | "
				 << "telefone " << vecClientes[posicao].gettelefone() << " | "
				 << "morada " << vecClientes[posicao].getmorada() << endl;;
		
		}
		cout << "Edite o nome do cliente \n";
		cin.ignore();
		getline(cin, NovoNome);

		vecClientes[posicao].setnome(NovoNome);
		cout << "Nome editado com sucesso! " << endl;
		cout << "Deseja editar mais algum cliente? (s|n) \n";
		cin >> valid;
		cin.ignore();

	} while (valid == 's' || valid == 'S');
	
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

        int remClie = ProcurarCliente(idCliente);

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
	system("cls"); 
	
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
	system("pause"); 

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
