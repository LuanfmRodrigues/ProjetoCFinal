#include "venda.h"

int Venda::contVenda = 1;
Venda::Venda()
{
    idvenda = 0;
    idpro = 0;
	nome = "Produto";
    idcli = 0;
	quantidade = 0;
    preco = 0.0;

}

Venda::Venda(const string& nome,int idpro, int idcli, int quantidade, double preco)
{
    idvenda = contVenda++;
    this->nome = nome;
    this->idpro = idpro;
    this->idcli = idcli;
    this->quantidade = quantidade;
    this->preco = preco;
}

int Venda::getid() const
{
    return idvenda;
}


string Venda::getnome() const
{
    return nome;
}

int Venda::getidpro() const
{
    return idpro;
}

int Venda::getidcli() const
{
    return idcli;
}

int Venda::getquantidade() const
{
    return quantidade;
}

double Venda::getpreco() const
{
    return preco;
}

void Venda::setid(int idvenda)
{
    this->idvenda = idvenda;
}

void Venda::setidpro(int idpro)
{
    this->idpro = idpro;
}

void Venda::setnome(string nome)
{
    this->nome = nome;
}

void Venda::setidclie(int idcli)
{
    this->idcli = idcli;
}

void Venda::setquantidade(int quantidade)
{  
    this->quantidade = quantidade;
}

void Venda::setpreco(double preco)
{
    this->preco = preco;
}
