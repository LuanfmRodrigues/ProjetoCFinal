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

	Cliente clien1("Luan", "961624758", "Drop in");
	Cliente clien2("Hiago", "896162568", "Os Barbaros");
	Cliente clien3("Felipe", "654324758", "Invctus");
	Cliente clien4("rodrigues", "348524758", "Drop Box");
	Cliente clien5("Diego","987654367", "MagueBox");

    Venda venda1("Camisa Nike", 1, 2, 15.00, 39.00,40.00, 1.00);
    Venda venda2("Tenis Adidas", 2, 1, 45.00,58.50, 60.00, 1.50);
    Venda venda3("Calça Puma", 3, 3, 25.00, 97.50, 100.00, 2.50);
    Venda venda4("Nano Crossfit", 7, 1, 75.00, 97.50, 100.00, 2.50);
    Venda venda5("Corta salto", 4, 2, 10.00, 26.00, 30.00, 4.00);
    Venda venda6("Estafas Crossfit", 5, 2, 35.00, 91.00, 100.00, 9.00);
    Venda venda7("Camisa Reebok", 1, 1, 10.00, 13.00, 15.00, 2.00);
    Venda venda8("Metcom Crossfit", 2, 1, 75.00, 97.50, 100.00, 2.50);
    Venda venda9("Camisa Nike", 3, 2, 15.00, 39.00, 40.00, 1.00);
    Venda venda10("Tenis Adidas", 4, 1, 45.00, 58.50, 60.00, 1.50);
 
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
        cout << "|Deseja Criar o produto? (s|n)                           |" << endl;
        cin >> cond;
        cin.ignore();
		cout << "|========================================================|" << endl;

        if (cond == 's' || cond == 'S') {

            Produto totalProdutosGlobal(nome, quantidade,preco);
			armazenarProduto(totalProdutosGlobal);
            cout << "|" << "Produto adicionado com sucesso!" << endl;
			cout << "|========================================================|" << endl;

        } else {
            cout << "|Produto não foi criado!                                 |" << endl;
			cout << "|========================================================|" << endl;
        }

        cout << "|Deseja criar mais produtos? (s|n)                       |" << endl;;
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
		cout << "|========================================================|" << endl;
		cout << "|Nenhum Produto cadastrado.                              |" << endl;
		return;
	}
	cout << "|========================================================|" << endl;
	cout << "|                      OPEN BOX CROSSFIT                 |" << endl;
	cout << "|========================================================|" << endl;
	cout << "|                        Produtos                        |" << endl;
	cout << "|========================================================|" << endl;

	for(int i = 0; i < totalProdutosGlobal;i++){
		cout << "|ID: " << vecProdutosGlobal[i].getId() 
			 << " |Nome: "<< vecProdutosGlobal[i].getNome() 
			 << " |Quantidade: " << vecProdutosGlobal[i].getQuantidade() 
			 << " |Valor: € " << vecProdutosGlobal[i].getPreco() << endl;
	}
	cout << "|========================================================|" << endl;
	system("pause"); 

}

void Loja::RemoverProduto()
{
	system("cls"); 
    char valid, valid2;
    do {
        if (totalProdutosGlobal == 0) {
            cout << "|Nenhum produto no estoque.\n";
            return;
        }
        impriTodosProd();

        int idProduto;
		cout << "|ID do produto: ";
		while (!(cin >> idProduto) || idProduto <= 0 || procurarProdutoid(idProduto) == -1) {
			cout << "|ID inválido ou inexistente. ";
			cout << "|Digiti ID valido: ";
			cin.clear();
			cin.ignore(INT_MAX, '\n');			
		}

        int remProd = procurarProdutoid(idProduto);
        if (remProd >= 0) {
			cout << "|========================================================|" << endl;
			cout << "|Produto  a ser excluido é:                              |" << endl;  
			cout << "|ID: " << vecProdutosGlobal[remProd].getId() << endl;
			cout << "|Nome; "<< vecProdutosGlobal[remProd].getNome() << endl;
			cout << "|Quantidade; " << vecProdutosGlobal[remProd].getQuantidade() << endl;
			cout << "|Valor: € " << vecProdutosGlobal[remProd].getPreco() << endl;
			cout << "|========================================================|" << endl;
            cout << "|Deseja realmente excluir o produto? (s/n) ";
            cin >> valid;
            if (valid == 's' || valid == 'S') {
                for (int i = remProd; i < totalProdutosGlobal - 1; i++) {
                    vecProdutosGlobal[i] = vecProdutosGlobal[i + 1];
                }
                totalProdutosGlobal--; 
                cout << "|Produto removido com sucesso!                           |" << endl;
				cout << "|========================================================|" << endl;
            }
        } else {
            cout << "|Produto não encontrado.                                 |" << endl;
			cout << "|========================================================|" << endl;
        }
        
        cout << "|Deseja remover mais algum produto? (s/n)                |" << endl;
		cout << "|========================================================|" << endl;
        cin >> valid2;
    } while (valid2 == 's' || valid2 == 'S');
}


void Loja::addProExiste()
{
	if (totalProdutosGlobal == 0) {
        cout << "Nenhum produto no estoque.\n";
        return;
    }
	cout << "|========================================================|" << endl;
	cout << "|                      OPEN BOX CROSSFIT                 |" << endl;
	cout << "|========================================================|" << endl;
	cout << "|                                                        |" << endl;
	impriTodosProd();
	cout << "|                                                        |" << endl;
	cout << "|========================================================|" << endl;
	char valid3;
	
	int posicao, novaQuant,idProduto;

	do
	{
		cout << "|========================================================|" << endl;
		cout << "|               Adicionar quantidade ao Produto          |" << endl;
		cout << "|========================================================|" << endl;

		cout << "|ID do produto: ";
		while (!(cin >> idProduto) || idProduto <= 0 || procurarProdutoid(idProduto) == -1) {
			cout << "|ID inválido ou inexistente. ";
			cout << "|Digiti ID valido: ";
			cin.clear();
			cin.ignore(INT_MAX, '\n');			
		}

		posicao = procurarProdutoid(idProduto);

		if (posicao == -1)
		{
			cout << "| Produto nao encontrado                                 |" << endl;
			cout << "|========================================================|" << endl;
			return;
		}else{		
			cout << "|========================================================|" << endl;	
			cout << "|Produto:                                                |" << endl;
			cout << "|========================================================|" << endl;
			cout << "|ID " << vecProdutosGlobal[posicao].getId() << endl;
			cout << "|Nome "<< vecProdutosGlobal[posicao].getNome() << endl;
			cout << "|Quantidade " << vecProdutosGlobal[posicao].getQuantidade() << endl;
			cout << "|Valor € " << vecProdutosGlobal[posicao].getPreco() << endl;
			cout << "|========================================================|" << endl;
			
		}

		cout << "|Quantidade a mais: ";
		cin >> novaQuant;
		while (cin.fail() || novaQuant <= 0 || cin.peek() != '\n')
		//cin.peek() != '\n': Verifica se há restos na entrada, impedindo números decimais
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "|Quantidade invalida." << endl;
			cout << "|Qual a quantidade: ";
			cin >> novaQuant;
		}
		vecProdutosGlobal[posicao].setQuantidade(vecProdutosGlobal[posicao].getQuantidade() + novaQuant);
		cout << "|========================================================|" << endl;
		cout << "|Quantidade Adicionada com sucesso!!!                    |" << endl;
		cout << "|========================================================|" << endl;
		cout << "|Deseja adicionar quantidade a mais? (s|n) ";
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
		cout << "|========================================================|" << endl;
		cout << "|                      OPEN BOX CROSSFIT                 |" << endl;
		cout << "|========================================================|" << endl;
		cout << "|                        Criar Atletas                   |" << endl;
		cout << "|========================================================|" << endl;

		cout << "|Nome do Atleta: ";
        getline(cin, nome);

		cout << "|Telefone: ";
        while (true) {
            getline(cin, telefone);  // vai Lê o telefone como string para facilitar a validação.
			// foi dificil isso.
            // Valida o telefone
            if (validarTelefone(telefone)) {
                break;  // Sai do loop se o telefone for válido
            } else {
                cout << "|Número de telefone inválido. O telefone deve ter 9 dígitos numéricos." << endl;
                cout << "|Digite novamente: ";
            }
        }
   	
	

		cout << "|Box: ";
		getline(cin, morada);

		cout << "|========================================================|" << endl;
		cout << "|Detalhes do Atleta:                                     |" << endl;
		cout << "|Nome: " << nome << " | Telefone: " << telefone << " | Box: "  << morada<< endl;
		cout << "|========================================================|" << endl;

		cout << "|Deseja Criar o Atleta? (s|n)";		
		cin >> cond;
		cin.ignore();
		cout << "|========================================================|" << endl;

		if (cond == 's' || cond == 'S') {
			
			
			Cliente totalClientesGlobal(nome, telefone, morada);
            ArmazenarCliente(totalClientesGlobal);
			cout << "|Atleta criado com sucesso!                              |" << endl;
			cout << "|========================================================|" << endl;
		} else {
			cout << "|Atleta não foi criado!                                  |" << endl;
			cout << "|========================================================|" << endl;
		}

		cout << "|Deseja criar mais um Atleta? (s|n) ";
		cin >> valid4;
		cin.ignore();
		cout << "|========================================================|" << endl;

		
	} while (valid4 == 's' || valid4 == 'S');
	
}

void Loja::EditarCliente()
{
	if (totalClientesGlobal == 0) {
		cout << "|========================================================|" << endl;
        cout << "|Nenhum Atleta encontrado.                               |" << endl;
        return;
	
    }
	string NovoNome;
	int  idcliente, posicao;
	char valid;

	cout << "|========================================================|" << endl;
	cout << "|                      OPEN BOX CROSSFIT                 |" << endl;
	cout << "|========================================================|" << endl;
	ImprimirTodosClientes();
	cout << "|                                                        |" << endl;
	cout << "|========================================================|" << endl;
	do
	{

		cout << "|========================================================|" << endl;
		cout << "|                       Editar Atletas                   |" << endl;
		cout << "|========================================================|" << endl;

		cout << "|ID do Atleta: ";
		while (!(cin >> idcliente) || idcliente <= 0  || ProcurarCliente(idcliente) == -1) {
			cout << "|ID inválido ou inexistente. ";
			cout << "|Digiti ID valido: ";
			cin.clear();
			cin.ignore(INT_MAX, '\n');			
		}
		posicao = ProcurarCliente(idcliente);

		if(posicao == -1)
		{
			cout << "|atleta não encontrado!!                                |" << endl;
			return;
		}else{	

			cout << "|========================================================|" << endl;
			cout << "|                Atleta a ser editado                    |" << endl;
			cout << "|========================================================|" << endl;	
			cout << "|ID: " << vecClientesGlobal[posicao].getid() << endl;
			cout << "|Nome: "<< vecClientesGlobal[posicao].getnome() << endl;
			cout << "|telefone: " << vecClientesGlobal[posicao].gettelefone() << endl;
			cout << "|Box: " << vecClientesGlobal[posicao].getmorada() << endl;
			cout << "|========================================================|" << endl;
		
		}
		cout << "|Edite o nome do Atleta:                                 |" << endl;
		cin.ignore();
		getline(cin, NovoNome);

		vecClientesGlobal[posicao].setnome(NovoNome);
		cout << "|Nome editado com sucesso!                               |" << endl;
		cout << "|Deseja editar mais algum Atleta? (s|n) ";
		cin >> valid;
		cin.ignore();
		cout << "|========================================================|" << endl;

	} while (valid == 's' || valid == 'S');
	
}

void Loja::EliminarCliente()
{
	system("cls"); 
    char valid, valid2;
    do {
        if (totalProdutosGlobal == 0) {
			cout << "|========================================================|" << endl;
            cout << "|Nenhum produto no estoque.                              |" << endl;
			cout << "|========================================================|" << endl;
            return;
        }
        impriTodosProd();

        int idcliente;
		while (!(cin >> idcliente) || idcliente <= 0  || ProcurarCliente(idcliente) == -1) {
			cout << "|ID inválido ou inexistente. ";
			cout << "|Digiti ID valido: ";
			cin.clear();
			cin.ignore(INT_MAX, '\n');			
		}

        int remClie = ProcurarCliente(idcliente);

        if (remClie >= 0) {
			cout << "|========================================================|" << endl;
			cout << "|                      OPEN BOX CROSSFIT                 |" << endl;
			cout << "|========================================================|" << endl;
			cout << "|                      Atletas Eliminados                |" << endl;
			cout << "|========================================================|" << endl;
			cout << "|ID: " << vecClientesGlobal[remClie].getid() << endl; 
			cout << "|Nome: "<< vecClientesGlobal[remClie].getnome() <<  endl;
			cout << "|Telefone: " << vecClientesGlobal[remClie].gettelefone() <<endl;
			cout << "|box: " << vecClientesGlobal[remClie].getmorada() << endl;
			cout << "|========================================================|" << endl;

            cout << "|Deseja realmente Eliminar o Atleta? (s/n) ";
            cin >> valid;
			cout << "|========================================================|" << endl;

            if (valid == 's' || valid == 'S') {
                for (int i = remClie; i < totalClientesGlobal - 1; i++) {
                    vecClientesGlobal[i] = vecClientesGlobal[i + 1];
                }
                totalClientesGlobal--; 
				cout << "|            atleta removido com sucesso!                |" << endl;
                
            }
        } else {
            cout << "|Atleta não encontrado.                                  |" << endl;
			
        }
        
        cout << "|Deseja remover mais algum Atleta? (s/n) ";
        cin >> valid2;
		cout << "|========================================================|" << endl;
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
		cout << "|========================================================|" << endl;
		cout << "|Nenhum Atleta encontrado.                               |" << endl;
		cout << "|========================================================|" << endl;
		return;
	}
	cout << "|========================================================|" << endl;
	cout << "|                      OPEN BOX CROSSFIT                 |" << endl;
	cout << "|========================================================|" << endl;
	cout << "|                         Atletas                        |" << endl;
	cout << "|========================================================|" << endl;

	for(int i = 0; i < totalClientesGlobal;i++){
		cout << "|ID: " << vecClientesGlobal[i].getid() 
			 << " |Nome: "<< vecClientesGlobal[i].getnome() 
			 << " |Telefone: " << vecClientesGlobal[i].gettelefone() 
			 << " |Box: " << vecClientesGlobal[i].getmorada() <<endl;
			 
	}
	cout << "|========================================================|" << endl;
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
	cout << "|========================================================|" << endl;
    cout << "|                           Checkout das Vendas          |" << endl;
    cout << "|========================================================|" << endl;
    cout << "                                        " << endl;
	
	for(int i = 0; i < TotalVendas;i++){
		cout << "|========================================================|" << endl;		
		cout << "|ID Cleinte:" << vecVendas[i].getidcli() << endl;
		cout << "|Nome: "<< vecVendas[i].getnome() << endl;
		cout << "|Quantidade: " << vecVendas[i].getquantidade() << endl;
		cout << "|Preço: € " << vecVendas[i].getpreco() << endl;
		cout << "|total com iva: " << vecVendas[i].gettotaliva() << endl;
		
		totalValor += (vecVendas[i].getpreco() * vecVendas[i].getquantidade())*1.3;
				
	}
	cout << "|========================================================|" << endl;
			
	cout << "|O Valor total da compra é €: " << totalValor << endl;
	cout << "|========================================================|" << endl;
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
    cout << "|Date and time: "
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
    double valorpago;
    char valid, valid1;
	
    system("cls");
	cout << "|========================================================|" << endl;
	cout << "|                      OPEN BOX CROSSFIT                 |" << endl;
	cout << "|========================================================|" << endl;
	cout << "|                       VEnda de produto                 |" << endl;
	cout << "|========================================================|" << endl;
    cout << "|  Para realizar a venda tem que ter ficha ou criar uma. |" << endl;
    cout << "|Se possui ficha digite (s) ou outra tecla para criar.   |" << endl;
	cout << "|========================================================|" << endl;
    cin >> valid1;
    if (valid1 == 's' || valid1 == 'S') {
        ImprimirTodosClientes();
    } else {
        criarCliente();
        ImprimirTodosClientes();
    }

    cout << "|Qual ID: ";
    while (!(cin >> idcliente) || idcliente <= 0 || ProcurarCliente(idcliente) == -1) {
        cout << "|ID inválido ou inexistente. ";
        cout << "|Digite ID válido: ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
		
    }
	cout << "|========================================================|" << endl;
    int posicaoCli = ProcurarCliente(idcliente);

    do {
        // Imprimir todos os produtos da Loja
        impriTodosProd();
        cout << "|Id do produto que deseja:";
		

        while (!(cin >> idproduto) || idproduto <= 0 || procurarProdutoid(idproduto) == -1) {
            cout << "|ID inválido ou inexistente. ";
            cout << "|Digite ID válido: ";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
		cout << "|========================================================|" << endl;
        int posicao = procurarProdutoid(idproduto);
        if (posicao == -1) {
            cout << "|Produto não encontrado!                                 |"<< endl;
			cout << "|========================================================|" << endl;
            return;
        } else {
			cout << "|========================================================|" << endl;
            cout << "|Produto                                                 |" << endl;
			cout << "|========================================================|" << endl;
            cout << "|ID: " << vecProdutosGlobal[posicao].getId() <<"         |"<< endl;
            cout << "|Nome: " << vecProdutosGlobal[posicao].getNome() <<"         |"<< endl;
            cout << "|Quantidade: " << vecProdutosGlobal[posicao].getQuantidade()<<"         |"<< endl;
        	cout << "|Preço por unidade: € " << vecProdutosGlobal[posicao].getPreco() << " |" << endl;
			cout << "|========================================================|" << endl;
			cout << "|Os Produtos estão com preço de custo,                   |" << endl;			
            cout << "|O valor de venda tem um acréscimo de 30%.               |" << endl;
			cout << "|========================================================|" << endl;
        }

        cout << "|Quantidade que deseja: ";
        cin >> quantProdu;
        while (cin.fail() || quantProdu <= 0 || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "|Quantidade inválida." << endl;
            cout << "|Qual a quantidade: ";
            cin >> quantProdu;
        }
		cout << "|========================================================|" << endl;

        if (quantProdu > vecProdutosGlobal[posicao].getQuantidade()) {
            cout << "|Não tem essa quantidade de produto no estoque.          |" << endl;
			cout << "|========================================================|" << endl;
        } else {
            // Reduz a quantidade de produtos no estoque
            vecProdutosGlobal[posicao].setQuantidade(vecProdutosGlobal[posicao].getQuantidade() - quantProdu);

            float totalValor = (vecProdutosGlobal[posicao].getPreco() * quantProdu) * 1.3;
			system("cls");
            cout << "|========================================================|" << endl;
			cout << "|                Checkout da Venda                       |" << endl;
			cout << "|========================================================|" << endl;
            cout << "|Produto                                                 |" << endl;
			cout << "|========================================================|" << endl;
            cout << "|ID: " << vecProdutosGlobal[posicao].getId() <<"         |"<< endl;
			cout << "|Produto: " << vecProdutosGlobal[posicao].getNome() << endl;
			cout << "|Qtd: " << quantProdu << endl;
			cout << "|Valor unidade: € " << vecProdutosGlobal[posicao].getPreco()<< endl;
			cout << "|Valor Total: € " << totalValor << endl;
			cout << "|========================================================|" << endl;

			double troco = valorpago - totalValor;
            
			cout << "|Confirmar Compra: (s|n) ";
            cin >> valid;
            if (valid == 's' || valid == 'S') 
			{
                cout << "|Valor a pagar: € " << totalValor << "\n";
				cout << "|========================================================|" << endl;

                while (true) { // Loop até que o valor seja exato ou superior
                    cout << "|Digite o valor pago: € ";
                    while (!(cin >> valorpago) || valorpago <= 0) {
                        cout << "|Valor inválido. Digite um valor positivo: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
					cout << "|========================================================|" << endl;

                    if (valorpago < totalValor) {
                        cout << "|Valor insuficiente. \n"
                             << "|Falta: € " << totalValor - valorpago << endl;
                    } else {
                        if (valorpago > totalValor) {
							cout << "|========================================================|" << endl;
                            cout << "|Pagamento efetuado com sucesso!                         |" << endl;
                            cout << "|Troco: € " << troco << endl;
                        } else {
                            cout << "|Pagamento efetuado com sucesso!                         |" << endl;
							cout << "|========================================================|" << endl;
                        }

                        // Registrar a venda
                        Venda venda(vecProdutosGlobal[posicao].getNome(), vecClientesGlobal[posicaoCli].getid(),
                                    quantProdu, vecProdutosGlobal[posicao].getPreco(), totalValor, valorpago, troco);
                        ArmazenarProVendas(venda);
                        imprimirTalao(); 
                        break; // Sai do loop de pagamento
                    }
                }
            } else {
                // aumenta o estoque se a compra for cancelada
                vecProdutosGlobal[posicao].setQuantidade(vecProdutosGlobal[posicao].getQuantidade() + quantProdu);
                cout << "|                  Compra cancelada!                     |" << endl;
				cout << "|========================================================|" << endl;
            }
        }

        cout << "|Deseja adicionar outro produto? (s|n): ";
        cin >> valid;
    } while (valid == 's' || valid == 'S');

	cout << "|========================================================|" << endl;
    cout << "|             Venda finalizada. Obrigado!                |" << endl;
	cout << "|========================================================|" << endl;
}

void Loja::imprimirTalao()
{
	system("cls");
	int FaturaNumero = Numfatura(); 
	int VenceNumero = NumVencedor();
	int posicao = TotalVendas -1; // vei pegar a ultima venda no vetor, no caso a ultima venda realizada.
	cout << "|========================================================|" << endl;
	cout << "|                         Fatura                         |" << endl;
	cout << "|========================================================|" << endl;
	cout << "|Produto                                                 |" << endl;
	cout << "|========================================================|" << endl;
	cout << "|ID Atleta:" << vecVendas[posicao].getidcli() << endl;
	cout << "|Nome: "<< vecVendas[posicao].getnome() << endl;
	cout << "|Quantidade: " << vecVendas[posicao].getquantidade() << endl;
	cout << "|Valor unidade: € " << vecVendas[posicao].getpreco() <<endl;
	cout << "|Valor s/ iva: " << vecVendas[posicao].getpreco() / 1.23 << endl;
	cout << "|Total: " << vecVendas[posicao].gettotaliva() << endl;
	cout << "|Valor pago: "<< vecVendas[posicao].getvalorpago() << endl;
	cout << "|Troco:  "<< vecVendas[posicao].gettroco() << endl;
	cout << "|========================================================|" << endl;
	cout << "| O iva  23%                                             |" << endl;
	cout << "|========================================================|" << endl;
	cout << "|Fatura: "<< FaturaNumero << "                                            |"<< endl;
	cout << "|========================================================|" << endl;
	cout << "|Numero da sorte: " << VenceNumero <<"                                   |"<< endl;
	cout << "|========================================================|" << endl;
	if(FaturaNumero == VenceNumero)
	{
		cout << "|                 FATURA PREMIADA                        |" << endl;
		cout << "|========================================================|" << endl;
		cout << "|  Sua compra foi preimiada e sua compra saiu de graca!  |" << endl;
		cout << "|========================================================|" << endl;
		tempo();
		cout << "|========================================================|" << endl;
	}else{

		cout << "|  Nao foi dessa vez! sua Fatura nao foi premiada        |" << endl;
		cout << "|========================================================|" << endl;
		tempo();
		cout << "|========================================================|" << endl;
	}
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


