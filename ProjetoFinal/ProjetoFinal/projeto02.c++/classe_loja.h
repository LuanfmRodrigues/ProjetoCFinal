	#pragma once
#include<iostream>
#include<string>
#include "classe_produto.h"
#include "cliente.h"


using namespace std;

class Loja {
private:
	
	// contador de Produtos eclientes
	int totalProdutos;
	int totalClientes;
	//vetores clientes e produtos
	Produto vecProdutos[100];
	Cliente vecClientes[100];
	
	
	

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
	void EditarCliente();
	void EliminarCliente();
	int ProcurarCliente(int idCliente);
	void ImprimirTodosClientes();
	void ArmazenarCliente(const Cliente& Cliente);
};