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
	
	// contador de Produtos eclientes

	

public:

	Loja();  
	
	
	//produtos	
	void criarProduto();
	void armazenarProduto(const Produto& Produto);
	int procurarProdutoid(int idProduto);
	void impriTodosProd();
	void RemoverProduto();
	void addProExiste();
	Produto* procurarProduto(int id);
	/*Produto& getProduto(int posicao) { return vecProdutos[posicao]; }*/


	// Cliente
	void criarCliente();
	void EditarCliente();
	void EliminarCliente();
	int ProcurarCliente(int idCliente);
	void ImprimirTodosClientes();
	void ArmazenarCliente(const Cliente& Cliente);
	
};
extern Produto vecProdutosGlobal[100];
extern int totalProdutosGlobal;
extern Cliente vecClientesGlobal[100];
extern int totalClientesGlobal;

class Loja {
	public:
		void impriTodosProd(); // Método para imprimir todos os produtos
		void ImprimirTodosClientes();
	};

#endif