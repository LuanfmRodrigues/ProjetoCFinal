#pragma once
#ifndef VENDA_H
#define VENDA_H
#include <iostream>
#include <string>
#include "classe_loja.h"




using namespace std;

class Vendas : public Loja{    

private:
    // contador de Vendas
    int TotalVendas;
    int idVendas;
   Produto vecVendas[100];
    double TotalVenda;

    


public:
    Vendas();
    void TodosProdutos(Produto& todos);    
    void EfetuarVenda(Loja& loja);
    int NumVencedor();
    int Numfatura();
    void ArmazenarProVendas(const Produto& Produto);
}; 
#endif