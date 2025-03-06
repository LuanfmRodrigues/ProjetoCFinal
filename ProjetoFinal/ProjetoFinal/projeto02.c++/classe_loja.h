#pragma once
#ifndef CLASSE_LOJA_H
#define CLASSE_LOJA_H
#include<iostream>
#include <set>
#include <random>
#include <chrono>
#include<string>
#include "classe_produto.h"
#include "cliente.h"
#include "venda.h"
#include <iomanip>
#include <limits> 
#include <climits>
#include "validacoes.h"


using namespace std;

class Loja {
private:
Produto vecProdutosGlobal[100];
Cliente vecClientesGlobal[100];
Venda vecVendas[100];
	
int totalProdutosGlobal = 0; // Inicializa a variável global de produtos
int totalClientesGlobal = 0; // Inicializa a variável global de clientes
int TotalVendas = 0;

public:

	Loja();  
	
	
	//produtos	
	void criarProduto();
	void armazenarProduto(const Produto& Produto);
	int procurarProdutoid(int idProduto);
	void RemoverProduto();
	void addProExiste();
	void impriTodosProd();
	

	// Cliente
	void criarCliente();
	void EditarCliente();
	void EliminarCliente();
	int ProcurarCliente(int idCliente);
	void ArmazenarCliente(const Cliente& Cliente);
	void ImprimirTodosClientes();

	//Venda
	 
    void EfetuarVenda();
	void imprimirTalao();
    int NumVencedor();
    int Numfatura();
    void ArmazenarProVendas(const Venda &venda);
    void checkout();
	void ImprimirVendas();
};
#endif

