#pragma once
#include <iostream>
#include <string>

using namespace std;


class Cliente {
private:
	static int contClie;
	int id;
	string nome, morada, telefone;
	

public:

	Cliente();
	Cliente(string nome,string morada, string telefone);

	string getnome() const;
	int getid()const;
	string gettelefone()const;
	string getmorada()const;

	void setnome(string nome);
	void setid(int id);
	void settelefone(string telefone);
	void setmorada(string morada);

};
