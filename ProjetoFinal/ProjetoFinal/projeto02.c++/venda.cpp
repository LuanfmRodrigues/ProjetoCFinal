#include "venda.h"

int Venda::contVenda = 1;
Venda::Venda()
{
    idvendas = 0;
	nome = "Cliente";
	data = 00;
	ValorPagar = 0;
}

Venda::Venda(int idvenda, string nome, int data, int ValorPagar)
{
    idvenda = contVenda++;
    this->nome = nome;
    this->data = data;
    this->ValorPagar = ValorPagar;
}

int Venda::getid() const
{
    return 0;
}

string Venda::getnome() const
{
    return string();
}

int Venda::getdata() const
{
    return 0;
}

int Venda::getvalorpagar() const
{
    return 0;
}

void Venda::setid(int idvendas)
{
    this->idvendas = idvendas;
}

void Venda::setnome(string nome)
{
    this->nome = nome;
}

void Venda::setdata(int data)
{
    this->data = data;
}

void Venda::setvalorpagar(int valorpagar)
{
    this->ValorPagar = valorpagar;
}
