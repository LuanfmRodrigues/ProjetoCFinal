#include "classe_produto.h"


int Produto::contProd = 1;
Produto::Produto()
{
	Id = 0;
	Nome = "";
	Quantidade = 0;
	Preco = 0.0;
	
}

Produto::Produto(string Nome, int Quantidade, float Preco)
{
	Id = contProd++;
	this->Nome = Nome;
	this->Quantidade = Quantidade;
	this->Preco = Preco;
	
}

string Produto::getNome()const
{
	return Nome;
}

int Produto::getId()const
{
	return Id;
}

int Produto::getQuantidade()const
{
	return Quantidade;
}

float Produto::getPreco()const
{
	return Preco;
}

void Produto::setNome(string nome)
{
	Nome = nome;
}

void Produto::setId(int idproduto)
{
	Id = idproduto;
}

void Produto::setQuantidade(int quantidade)
{
	Quantidade = quantidade;
}

void Produto::setPreco(float preco)
{
	Preco = preco;
}
