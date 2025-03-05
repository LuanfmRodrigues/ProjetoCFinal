#include "classe_loja.h"

using namespace std;



Loja::Loja()   
{
	Produto vecProdutosGlobal[100]; // Define o array global de produtos   
	Cliente vecClientesGlobal[100]; // Define o array global de clientes
	    
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

            Produto totalProdutosGlobal(nome, quantidade,preco);
			armazenarProduto(totalProdutosGlobal);
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
	if(totalProdutosGlobal >= 100) {
		cout << "Estoque esta Cheio!! \n";
		return;
	}	
	vecProdutosGlobal[totalProdutosGlobal] = Produto;
	totalProdutosGlobal++;
	return;
  
    
}
Produto* Loja::procurarProduto(int id) {
    for (int i = 0; i < totalProdutosGlobal; i++) {
        if (vecProdutosGlobal[i].getId() == id) {
            return &vecProdutosGlobal[i];  // Retorna o endereço do produto encontrado
        }
    }
    return nullptr;  // Retorna nullptr se não encontrar o produto
}



int Loja::procurarProdutoid(int idProduto)
{
	for (int i = 0; i < totalProdutosGlobal; i++)
	{
		if(vecProdutosGlobal[i].getId() == idProduto){	
		return i;	
		}
		
	}
	return -1;
	
}

void Loja::impriTodosProd()
{
	system("cls"); 
	
	if(totalProdutosGlobal == 0){
		cout << "Nenhum Produto cadastrado. " << endl;
		return;
	}
	cout << "________________________________________" << endl;
    cout << "              Produtos                  " << endl;
    cout << "________________________________________" << endl;

	for(int i = 0; i < totalProdutosGlobal;i++){
		cout << "ID " << vecProdutosGlobal[i].getId() << " | "
			 << "Nome "<< vecProdutosGlobal[i].getNome() << " | "
			 << "Quantidade " << vecProdutosGlobal[i].getQuantidade() << " | "
			 << "Preço € " << vecProdutosGlobal[i].getPreco() << endl;
	}
	system("pause"); 

}

void Loja::RemoverProduto()
{
	system("cls"); 
    char valid, valid2;
    do {
        if (totalProdutosGlobal == 0) {
            cout << "Nenhum produto no estoque.\n";
            return;
        }
        impriTodosProd();

        int idProduto;
        cout << "Qual o ID do produto: ";
        while (!(cin >> idProduto) || idProduto <= 0) {
            cout << "ID inválida. Digite um número positivo: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int remProd = procurarProdutoid(idProduto);
        if (remProd >= 0) {
			cout << "Produto  a ser excluido é: \n" 
				<< "ID " << vecProdutosGlobal[remProd].getId() << " | "
				<< "Nome "<< vecProdutosGlobal[remProd].getNome() << " | "
				<< "Quantidade " << vecProdutosGlobal[remProd].getQuantidade() << " | "
				<< "Preço € " << vecProdutosGlobal[remProd].getPreco() << endl;
            cout << "Deseja realmente excluir o produto? (s/n) ";
            cin >> valid;
            if (valid == 's' || valid == 'S') {
                for (int i = remProd; i < totalProdutosGlobal - 1; i++) {
                    vecProdutosGlobal[i] = vecProdutosGlobal[i + 1];
                }
                totalProdutosGlobal--; 
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
	if (totalProdutosGlobal == 0) {
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
				<< "ID " << vecProdutosGlobal[posicao].getId() << " | "
				<< "Nome "<< vecProdutosGlobal[posicao].getNome() << " | "
				<< "Quantidade " << vecProdutosGlobal[posicao].getQuantidade() << " | "
				<< "Preço € " << vecProdutosGlobal[posicao].getPreco() << endl;;
			
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
		vecProdutosGlobal[posicao].setQuantidade(vecProdutosGlobal[posicao].getQuantidade() + novaQuant);
		cout << "Quantidade Adicionada com sucesso!!! \n" << endl;
		cout << "Deseja adicionar quantidade a mais? (s|n) \n";
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
			
			
			Cliente totalClientesGlobal(nome, telefone, morada);
            ArmazenarCliente(totalClientesGlobal);
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
	if (totalClientesGlobal == 0) {
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
				 << "ID " << vecClientesGlobal[posicao].getid() << " | "
				 << "Nome "<< vecClientesGlobal[posicao].getnome() << " | "
				 << "telefone " << vecClientesGlobal[posicao].gettelefone() << " | "
				 << "morada " << vecClientesGlobal[posicao].getmorada() << endl;;
		
		}
		cout << "Edite o nome do cliente \n";
		cin.ignore();
		getline(cin, NovoNome);

		vecClientesGlobal[posicao].setnome(NovoNome);
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
        if (totalProdutosGlobal == 0) {
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
				<< "ID " << vecClientesGlobal[remClie].getid() << " | "
				<< "Nome "<< vecClientesGlobal[remClie].getnome() << " | "
				<< "Telefone " << vecClientesGlobal[remClie].gettelefone() << " | "
				<< "Morada " << vecClientesGlobal[remClie].getmorada() << endl;

            cout << "Deseja realmente remover o cliente? (s/n) ";
            cin >> valid;

            if (valid == 's' || valid == 'S') {
                for (int i = remClie; i < totalClientesGlobal - 1; i++) {
                    vecClientesGlobal[i] = vecClientesGlobal[i + 1];
                }
                totalClientesGlobal--; 
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
	for (int i = 0; i < totalClientesGlobal; i++){
	
		if(vecClientesGlobal[i].getid() == idCliente){	
		return i;	
		}
		
	}
	return -1;
	
}

void Loja::ImprimirTodosClientes()
{
	system("cls"); 
	
	if(totalClientesGlobal == 0){
		cout << "Nenhum Cliente encontrado. " << endl;
		return;
	}
	cout << "________________________________________" << endl;
    cout << "              Clientes                  " << endl;
    cout << "________________________________________" << endl;

	for(int i = 0; i < totalClientesGlobal;i++){
		cout << "ID " << vecClientesGlobal[i].getid() << " | "
			 << "Nome "<< vecClientesGlobal[i].getnome() << " | "
			 << "Telefone " << vecClientesGlobal[i].gettelefone() << " | "
			 << "Morada " << vecClientesGlobal[i].getmorada() << endl;
	}
	system("pause"); 

}

void Loja::ArmazenarCliente(const Cliente &Cliente)
{
	if(totalClientesGlobal >= 100) {
		cout << "Limite de Cadastros atingido!! \n";
		return;
	}	
	vecClientesGlobal[totalClientesGlobal] = Cliente;
	totalClientesGlobal++;
	return;
}
