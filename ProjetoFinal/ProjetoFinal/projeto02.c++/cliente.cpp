#include "cliente.h"


int Cliente::contClie = 1;
Cliente::Cliente()
{
	id = 0;
	nome = "";
	telefone = 0;
	morada = "";
	
}
Cliente::Cliente(string Nome, string morada, int telefone)
{
    id = contClie++;
	this->nome = nome;
	this->telefone = telefone;
	this->morada = morada;
}

string Cliente::getnome() const
{
    return nome;
}

int Cliente::getid() const
{
    return id;
}

int Cliente::gettelefone() const
{
    return telefone;
}

string Cliente::getmorada() const
{
    return morada;
}

void Cliente::setnome(string nome)
{
    this->nome = nome;
}

void Cliente::setid(int idCliente)
{
    this-> id = idCliente;
}

void Cliente::settelefone(int telefone)
{
    this->telefone = telefone;
}

void Cliente::setmorada(string morada)
{
    this->morada = morada;
}
