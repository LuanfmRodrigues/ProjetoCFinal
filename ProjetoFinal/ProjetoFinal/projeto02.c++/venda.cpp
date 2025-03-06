#include "venda.h"

int Venda::contVenda = 1;
Venda::Venda()
{
    idvenda = 0;
	nome = "Produto";
	quantidade = 0;
    preco = 0.0;

}

Venda::Venda(const string& nome,int quantidade, double preco)
{
    idvenda = contVenda++;
    this->nome = nome;
    this->quantidade = quantidade;
    this->preco = preco;
}

int Venda::getid() const
{
    return 0;
}

string Venda::getnome() const
{
    return string();
}


int Venda::getquantidade() const
{
    return 0;
}

double Venda::getpreco() const
{
    return 0.0;
}

void Venda::setid(int idvenda)
{
    this->idvenda = idvenda;
}

void Venda::setnome(string nome)
{
    this->nome = nome;
}

void Venda::setquantidade(int quantidade)
{  
    this->quantidade = quantidade;
}

void Venda::setpreco(double preco)
{
    this->preco = preco;
}
