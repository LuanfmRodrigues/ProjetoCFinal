#pragma once
#ifndef LOJA_H
#define LOJA_H
#include<iostream>
#include<string>
#include "classe_produto.h"
#include "cliente.h"
#include <iomanip>
#include <limits> 
#include <climits>
#include "validacoes.h"


using namespace std;

class Loja {
private:
	
int totalProdutosGlobal = 0; // Inicializa a variável global de produtos
int totalClientesGlobal = 0; // Inicializa a variável global de clientes

public:

	Loja();  
	
	
	//produtos	
	void criarProduto();
	void armazenarProduto(const Produto& Produto);
	int procurarProdutoid(int idProduto);
	void RemoverProduto();
	void addProExiste();
	void impriTodosProd();
	Produto* procurarProduto(int id);
	


	// Cliente
	void criarCliente();
	void EditarCliente();
	void EliminarCliente();
	int ProcurarCliente(int idCliente);
	void ArmazenarCliente(const Cliente& Cliente);
	void ImprimirTodosClientes();
	
};
extern Produto vecProdutosGlobal[100];
extern int totalProdutosGlobal;
extern Cliente vecClientesGlobal[100];
extern int totalClientesGlobal;

#endif