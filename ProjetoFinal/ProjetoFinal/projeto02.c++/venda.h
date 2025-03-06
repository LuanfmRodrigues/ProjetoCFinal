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
    int idvendas;
    string nome;
    int data;
    int ValorPagar;    


public:
    Venda();
    Venda (int idvenda, string nome,int data, int ValorPagar);

    int getid()const;
    string getnome() const;	
	int getdata()const;
	int getvalorpagar()const;

	void setid(int id);
    void setnome(string nome);	
	void setdata(int data);
	void setvalorpagar(int valorpagar);
}; 
#endif