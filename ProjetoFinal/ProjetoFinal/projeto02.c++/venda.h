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
    double valorpago;
    double troco; 
       


public:
    Venda();
    Venda (const  string& nome, int idcli, int quantidade, double preco, double totaliva, double valorrpago, double troco);

    int getid()const;
    string getnome() const;	
    int getidcli() const;
	int getquantidade()const;
    double getpreco()const;
    double gettotaliva()const;
    double getvalorpago()const;
    double gettroco()const;

	void setid(int idvenda);
    void setnome(string nome);	
    void setidclie(int idclie);
	void setquantidade(int quantidade);
    void setpreco(double preco);
    void settotaliva(double totaliva);
    void setvalorpago(double valorpago);
    void settroco(double troco);
}; 
#endif