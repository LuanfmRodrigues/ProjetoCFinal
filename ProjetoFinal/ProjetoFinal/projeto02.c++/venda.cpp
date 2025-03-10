#include "venda.h"

int Venda::contVenda = 1;
Venda::Venda()
{
    idvenda = 0;
    nome = "Produto";
    idcli = 0;
	quantidade = 0;
    preco = 0.0;
    totaliva = 0.0;
    valorpago = 0.0;
    troco = 0.0 ;

}

Venda::Venda(const  string& nome, int idcli, int quantidade, double preco, double totaliva,double valorpago, double troco)
{
    idvenda = contVenda++;
    this->nome = nome;
    this->idcli = idcli;
    this->quantidade = quantidade;
    this->preco = preco;
    this->totaliva = totaliva;
    this->valorpago = valorpago;
    this->troco = troco;
}

int Venda::getid() const
{
    return idvenda;
}


string Venda::getnome() const
{
    return nome;
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

double Venda::gettotaliva() const
{
    return totaliva;
}

double Venda::getvalorpago() const
{
    return valorpago;
}

double Venda::gettroco() const
{
    return troco;
}

void Venda::setid(int idvenda)
{
    this->idvenda = idvenda;
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

void Venda::settotaliva(double totaliva)
{
    this->totaliva = totaliva;
}

void Venda::setvalorpago(double valorpago)
{
    this->valorpago = valorpago;
}

void Venda::settroco(double troco)
{
    this->troco = troco;
}
