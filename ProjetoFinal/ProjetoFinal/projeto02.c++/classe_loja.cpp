#include "classe_loja.h"

using namespace std;



Loja::Loja()   
{
	    
	Produto prod1("Camisa Nike", 20, 15.00);
	Produto prod2("Tenis Adidas", 20, 45.00);
	Produto prod3("Calça Puma", 15, 25.00);
	Produto prod4("Corta salto", 20, 10.00);
	Produto prod5("Estafas Crossfit", 20, 35.00);
	Produto prod6("Camisa Reebok", 10, 10.00);
	Produto prod7("Nano Crossfit", 20, 75.00);
	Produto prod8("Metcom Crossfit", 20, 75.00);

	Cliente clien1("Luan", "961624758", "rua A");
	Cliente clien2("Hiago", "896162568", "rua b");
	Cliente clien3("Felipe", "654324758", "rua c");
	Cliente clien4("rodrigues", "348524758", "rua d");
	Cliente clien5("Diego","987654367", "rua luz");

    Venda venda1("Camisa Nike", 1, 2, 15.00, 39.00);
    Venda venda2("Tenis Adidas", 2, 1, 45.00,58.50);
    Venda venda3("Calça Puma", 3, 3, 25.00, 97.50);
    Venda venda4("Nano Crossfit", 7, 1, 75.00, 97.50);
    Venda venda5("Corta salto", 4, 2, 10.00, 26.00);
    Venda venda6("Estafas Crossfit", 5, 2, 35.00, 91.00);
    Venda venda7("Camisa Reebok", 1, 1, 10.00, 13.00);
    Venda venda8("Metcom Crossfit", 2, 1, 75.00, 97.50);
    Venda venda9("Camisa Nike", 3, 2, 15.00, 39.00);
    Venda venda10("Tenis Adidas", 4, 1, 45.00, 58.50);
 
	armazenarProduto(prod1);
	armazenarProduto(prod2);
	armazenarProduto(prod3);
	armazenarProduto(prod4);
	armazenarProduto(prod5);
	armazenarProduto(prod6);
	armazenarProduto(prod7);
	armazenarProduto(prod8);

	ArmazenarCliente(clien1);
	ArmazenarCliente(clien2);
	ArmazenarCliente(clien3);
	ArmazenarCliente(clien4);
	ArmazenarCliente(clien5);

	ArmazenarProVendas(venda1);
    ArmazenarProVendas(venda2);
    ArmazenarProVendas(venda3);
	ArmazenarProVendas(venda4);
    ArmazenarProVendas(venda5);
    ArmazenarProVendas(venda6);
	ArmazenarProVendas(venda7);
    ArmazenarProVendas(venda8);
	ArmazenarProVendas(venda9);
    ArmazenarProVendas(venda10);
   
}

void Loja::criarProduto() {
	system("cls"); 
	string nome;
    char cond, valid1;
    int quantidade;
    double preco;

    cin.ignore();
    do {
		cout << "|========================================================|" << endl;
		cout << "|                      OPEN BOX CROSSFIT                 |" << endl;
		cout << "|========================================================|" << endl;
		cout << "|                        Criar Produto                   |" << endl;
		cout << "|========================================================|" << endl;

        cout << "| " <<  "Nome do Produto:";
		getline(cin, nome);
				
        // Valida se a quantidade é um números positivos
        cout << "| " <<"Quantidade:";
		
        while (!(cin >> quantidade) || quantidade <= 0 || cin.peek() != '\n') {
			//cin.peek() != '\n': Verifica se há restos na entrada, impedindo números decimais
            cout << "Quantidade inválida. Digite um número inteiro positivo: ";
			cout << "|========================================================|" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpa a memoria temporaria
			cout << "|========================================================|" << endl;
        }

        // Valida se o preço é um números positivos
		
		cout << "|" <<"Valor: ";
		 while (!(cin >> preco) || preco <= 0) {
            
			cout << "|" << "Preço inválido. Digite um valor positivo:";
			cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
		cout << "|========================================================|"<< endl;
        cout << "|Produto criado:                                         |" << endl;
		cout << "|========================================================|" << endl;
        cout << "|Nome: " << nome << " | Quantidade: " << quantidade << " | Valor: €"  << preco << "                |"<< endl;
		cout << "|========================================================|" << endl;
        cout <<"|Deseja Criar o produto? (s|n)";
        cin >> cond;
        cin.ignore();
		cout << "|========================================================|" << endl;

        if (cond == 's' || cond == 'S') {

            Produto totalProdutosGlobal(nome, quantidade,preco);
			armazenarProduto(totalProdutosGlobal);
            cout <<"|" << "Produto adicionado com sucesso!" << endl;
			cout << "|========================================================|" << endl;

        } else {
            cout <<"|"<< "Produto não foi criado! ";
			cout << "|========================================================|" << endl;
        }

        cout <<"|"<< "Deseja criar mais produtos? (s|n) ";
        cin >> valid1;
        cin.ignore();
		cout << "|========================================================|" << endl;

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
		cout << "ID do produto: ";
		while (!(cin >> idProduto) || idProduto <= 0 || procurarProdutoid(idProduto) == -1) {
			cout << "ID inválido ou inexistente. ";
			cout << "Digiti ID valido: ";
			cin.clear();
			cin.ignore(INT_MAX, '\n');			
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
		while (!(cin >> idProduto) || idProduto <= 0 || procurarProdutoid(idProduto) == -1) {
			cout << "ID inválido ou inexistente. ";
			cout << "Digiti ID valido: ";
			cin.clear();
			cin.ignore(INT_MAX, '\n');			
		}

		posicao = procurarProdutoid(idProduto);

		if (posicao == -1)
		{
			cout << "Produto não encontrado! \n";
			return;
		}else{			
			cout << "Produto: \n" 
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
		while (!(cin >> idcliente) || idcliente <= 0  || ProcurarCliente(idcliente) == -1) {
			cout << "ID inválido ou inexistente. ";
			cout << "Digiti ID valido: ";
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

        int idcliente;
		while (!(cin >> idcliente) || idcliente <= 0  || ProcurarCliente(idcliente) == -1) {
			cout << "ID inválido ou inexistente. ";
			cout << "Digiti ID valido: ";
			cin.clear();
			cin.ignore(INT_MAX, '\n');			
		}

        int remClie = ProcurarCliente(idcliente);

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
// Vendas!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


void Loja::ArmazenarProVendas(const Venda& venda)
{
	if(TotalVendas >= 100) {
		cout << "Estoque esta Cheio!! \n";
		return;
	}	
	vecVendas[TotalVendas] = venda;
	TotalVendas++;
	return;
  
    
}


void Loja::CheckoutVendas()
{
	// funcao para exibir as pre vendas
	system("cls"); 
	int totalValor = 0;
	if(TotalVendas == 0){
		cout << "Nenhuma Venda cadastrada. " << endl;
		return;
	}
	cout << "________________________________________" << endl;
    cout << "           Checkout das Vendas          " << endl;
    cout << "________________________________________" << endl;
    cout << "                                        " << endl;
	
	for(int i = 0; i < TotalVendas;i++){		
		cout << "ID Cleinte:" << vecVendas[i].getidcli() << " | "
				<< "Nome: "<< vecVendas[i].getnome() << " | "
				<< "Quantidade: " << vecVendas[i].getquantidade() << " | "
				<< "Preço: € " << vecVendas[i].getpreco() << "\n"
				<< "total com iva: " << vecVendas[i].gettotaliva() << endl;
		
		totalValor += (vecVendas[i].getpreco() * vecVendas[i].getquantidade())*1.3;
				
	}
		
	cout << "O Valor total da compra é €: " << totalValor << endl;
	system("pause"); 
}

int Loja::ProcurarCarrinho(int idvenda)
{
	for (int i = 0; i < TotalVendas; i++)
	{
		if(vecVendas[i].getid() == idvenda){	
		return i;	
		}
		
	}
	return -1;
}

void Loja::tempo()
{
    // Pega o tempo atual do sistema
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);

    // Usa localtime para obter a data e hora atual
    struct tm time_info;
    time_info = *localtime(&now_time); // Usando localtime

    // Exibe a data e hora formatada
    cout << "Date and time: "
         << time_info.tm_mday << "/"
         << time_info.tm_mon + 1 << "/" // Meses começam de 0
         << time_info.tm_year + 1900 << " " // O ano começa de 1900
         << time_info.tm_hour << ":"
         << time_info.tm_min << ":"
         << time_info.tm_sec << endl;
}

void Loja::EfetuarVenda() 
{
    int idproduto, quantProdu, idcliente;
    double Valorpago;
    char valid, valid1;
    system("cls");
    cout << "________________________________________" << endl;
    cout << "            Vendas de Produto           " << endl;
    cout << "________________________________________" << endl;
    cout << "                                        " << endl;

    cout << "Para efetuar a venda tem que ter ficha ou criar uma. " << endl;
    cout << "Se possui ficha digite (s) ou outra tecla para criar. " << endl;
    cin >> valid1;
    if (valid1 == 's' || valid1 == 'S') {
        ImprimirTodosClientes();
    } else {
        criarCliente();
        ImprimirTodosClientes();
    }

    cout << "Qual ID: \n";
    while (!(cin >> idcliente) || idcliente <= 0 || ProcurarCliente(idcliente) == -1) {
        cout << "ID inválido ou inexistente. ";
        cout << "Digite ID válido: ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    int posicaoCli = ProcurarCliente(idcliente);

    do {
        // Imprimir todos os produtos da Loja
        impriTodosProd();
        cout << "Id do produto que deseja: \n";

        while (!(cin >> idproduto) || idproduto <= 0 || procurarProdutoid(idproduto) == -1) {
            cout << "ID inválido ou inexistente. ";
            cout << "Digite ID válido: ";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        int posicao = procurarProdutoid(idproduto);
        if (posicao == -1) {
            cout << "Produto não encontrado! \n";
            return;
        } else {
            cout << "Produto: \n " << endl
                 << "ID: " << vecProdutosGlobal[posicao].getId() << " |"
                 << "Nome: " << vecProdutosGlobal[posicao].getNome() << " |"
                 << "Quantidade: " << vecProdutosGlobal[posicao].getQuantidade() << " |"
                 << "Preço por unidade: € " << vecProdutosGlobal[posicao].getPreco() << " |" << endl;
            cout << "Os Produtos estão com preço de custo, o valor de venda tem um acréscimo de 30% " << endl;
        }

        cout << "Quantidade que deseja: \n";
        cin >> quantProdu;
        while (cin.fail() || quantProdu <= 0 || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Quantidade inválida." << endl;
            cout << "Qual a quantidade: ";
            cin >> quantProdu;
        }

        if (quantProdu > vecProdutosGlobal[posicao].getQuantidade()) {
            cout << "Não tem essa quantidade de produto no estoque. \n";
        } else {
            // Reduz a quantidade de produtos no estoque
            vecProdutosGlobal[posicao].setQuantidade(vecProdutosGlobal[posicao].getQuantidade() - quantProdu);

            float totalValor = (vecProdutosGlobal[posicao].getPreco() * quantProdu) * 1.3;

            cout << "Checkout da Venda: \n";
            cout << "Produto: \n " << endl
                 << "ID: " << vecProdutosGlobal[posicao].getId() << " |"
                 << "Nome: " << vecProdutosGlobal[posicao].getNome() << " |"
                 << "Quantidade: " << quantProdu << " |"
                 << "Preço por unidade: € " << vecProdutosGlobal[posicao].getPreco() << " |"
                 << "Preço Total: € " << totalValor << endl;

            cout << "Confirmar Compra: (s|n) \n";
            cin >> valid;
            if (valid == 's' || valid == 'S') 
			{
                cout << "Valor a pagar: € " << totalValor << "\n";

                while (true) { // Loop infinito até que o valor seja válido
                    cout << "Digite o valor pago: € ";
                    while (!(cin >> Valorpago) || Valorpago <= 0) {
                        cout << "Valor inválido. Digite um valor positivo: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    if (Valorpago < totalValor) {
                        cout << "Valor insuficiente. \n"
                             << "Falta: € " << totalValor - Valorpago << endl;
                    } else {
                        if (Valorpago > totalValor) {
                            cout << "Pagamento efetuado com sucesso! \n";
                            cout << "Troco: € " << Valorpago - totalValor << endl;
                        } else {
                            cout << "Pagamento efetuado com sucesso! \n";
                        }

                        // Registrar a venda
                        Venda venda(vecProdutosGlobal[posicao].getNome(), vecClientesGlobal[posicaoCli].getid(),
                                    quantProdu, vecProdutosGlobal[posicao].getPreco(), totalValor);
                        ArmazenarProVendas(venda);
                        //imprimirTalao(); 
                        break; // Sai do loop de pagamento
                    }
                }
            } else {
                // aumenta o estoque se a compra for cancelada
                vecProdutosGlobal[posicao].setQuantidade(vecProdutosGlobal[posicao].getQuantidade() + quantProdu);
                cout << "Compra cancelada! " << endl;
            }
        }

        cout << "Deseja adicionar outro produto? (s|n): ";
        cin >> valid;
    } while (valid == 's' || valid == 'S');

    cout << "Venda finalizada. Obrigado! \n";
}

void Loja::imprimirTalao()
{
	/*int compra, troco, lucro;
	int FaturaNumero = Numfatura(); 
	int VenceNumero = NumVencedor();

	cout << "Produtos no Carrinho: \n";
	while (!(cin >> compra) || compra <= 0  || ProcurarCarrinho(compra) == -1) {
		cout << "ID inválido ou inexistente. ";
		cout << "Digiti ID valido: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');			
	}
	int posicao = ProcurarCarrinho(compra);
	if(posicao == -1){
		cout << "Produto não encotrado!! \n";
	}else{
		cout << "Carrinho: " << endl;
		cout << "ID Cleinte:" << vecVendas[posicao].getidcli() << " | "
			<< "Nome: "<< vecVendas[posicao].getnome() << " | "
			<< "Quantidade: " << vecVendas[posicao].getquantidade() << " | "
			<< "Preço: € " << vecVendas[posicao].getpreco() << "\n"
			<< "Subtotal: " << vecVendas[posicao].getpreco() * vecVendas[posicao].getquantidade()<< endl;
	}*/

}

int Loja::NumVencedor()
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

int Loja::Numfatura()
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


