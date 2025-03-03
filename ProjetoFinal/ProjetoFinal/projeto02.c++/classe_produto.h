#pragma once
#ifndef produto_H
#define produto_H
#include <iostream>
#include <string>

using namespace std;


class Produto {
private:
	static int contProd;
	int Id;
	string Nome;
	float Preco;
	int Quantidade;

public:

	Produto();
	Produto(string Nome, int Quantidade, float Preco);

	string getNome() const;
	int getId()const;
	int getQuantidade()const;
	float getPreco()const;

	void setNome(string nome);
	void setId(int idproduto);
	void setQuantidade(int quantidade);
	void setPreco(float preco);

};
#endif