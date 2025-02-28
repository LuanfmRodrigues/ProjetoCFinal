	#pragma once
#include<iostream>
#include<string>
#include "classe_produto.h"
#include "cliente.h"


using namespace std;

class Loja {
private:
	//vetores clientes e produtos
	
	Produto vecProdutos[100];
	Cliente vecCliente[100];
	 // contador de Produtos eclientes
	int toralClientes;
	int totalProdutos;

	
	

public:

	Loja();  
	
	
	//produtos	
	void criarProduto();
	void armazenarProduto(const Produto& Produto);
	int procurarProduto(int idProduto);
	void impriTodosProd();
	void RemoverProduto();
	void addProExiste();

	// Cliente
	void criarCliente();
	void MudarNomeCliente();
	void EliminarCliente();
	void ProcurarCliente();
	void ImprimirCliente();
	void ImprimirTodosClientes();
	void ArmazenarCliente();
};