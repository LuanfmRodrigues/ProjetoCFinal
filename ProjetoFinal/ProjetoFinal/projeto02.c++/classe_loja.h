	#pragma once
#include<iostream>
#include<string>
#include "classe_produto.h"


using namespace std;

class Loja {
private:
	//vetores
	
	Produto vecProdutos[100];
	 // contador de Produtos
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
};