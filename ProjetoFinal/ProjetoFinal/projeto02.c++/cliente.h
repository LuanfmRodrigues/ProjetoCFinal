#pragma once
#include <iostream>
#include <string>

using namespace std;


class Cliente {
private:
	static int contClie;
	int id;
	string nome, morada;
	int telefone;

public:

	Cliente();
	Cliente(string nome,string morada, int telefone);

	string getnome() const;
	int getid()const;
	int gettelefone()const;
	string getmorada()const;

	void setnome(string nome);
	void setid(int id);
	void settelefone(int telefone);
	void setmorada(string morada);

};
