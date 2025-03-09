#pragma once
#ifndef CLASSE_PRODUTO_H
#define CLASSE_PRODUTO_H
#include <iostream>
#include <string>

using namespace std;


class Produto {
private:
	static int contProd;
	int Id;
	string Nome;
	double Preco;
	int Quantidade;

public:

	Produto();
	Produto(string Nome, int Quantidade, double Preco);

	string getNome() const;
	int getId()const;
	int getQuantidade()const;
	double getPreco()const;

	void setNome(string nome);
	void setId(int idproduto);
	void setQuantidade(int quantidade);
	void setPreco(double preco);

};
#endif