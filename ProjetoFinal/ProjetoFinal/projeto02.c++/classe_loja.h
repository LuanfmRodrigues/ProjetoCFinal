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
	 // Método para imprimir todos os produtos
	
	

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
	/*Produto& getProduto(int posicao) { return vecProdutos[posicao]; }*/


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