#pragma once
#ifndef CLASSE_VENDA_H
#define CLASSE_VENDA_H

#include <iostream>
#include <string>
using namespace std;

class Venda
{    

private:
    static int contVenda;  
    int idvenda;
    int idpro;
    string nome;
    int idcli;
    int quantidade;
    double preco;    


public:
    Venda();
    Venda (const  string& nome, int idpro, int idcli, int quantidade, double preco);

    int getid()const;
    string getnome() const;	
    int getidpro() const;
    int getidcli() const;
	int getquantidade()const;
    double getpreco()const;

	void setid(int idvenda);
    void setidpro(int idpro);
    void setnome(string nome);	
    void setidclie(int idclie);
	void setquantidade(int quantidade);
    void setpreco(double preco);
}; 
#endif