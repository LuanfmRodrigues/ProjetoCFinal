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
    string nome;
    int idcli;
    int quantidade;
    double preco;
    double totaliva;    


public:
    Venda();
    Venda (const  string& nome, int idcli, int quantidade, double preco, double totaliva);

    int getid()const;
    string getnome() const;	
    int getidcli() const;
	int getquantidade()const;
    double getpreco()const;
    double gettotaliva()const;

	void setid(int idvenda);
    void setnome(string nome);	
    void setidclie(int idclie);
	void setquantidade(int quantidade);
    void setpreco(double preco);
    void settotaliva(double totaliva);
}; 
#endif