#pragma once
#ifndef venda_H
#define venda_H
#include <iostream>
#include <string>
#include "classe_produto.h"
#include "cliente.h"
#include "classe_loja.h"
#include "classe_loja.cpp"




using namespace std;

class Vendas : public Loja{    

private:
    // contador de Vendas
    int TotalVendas;
    int idVendas;
    double TotalVenda;

    


public:
    Vendas();
    void TodosProdutos(Produto& todos);    
    void EfetuarVenda(Loja& loja);
    int NumVencedor();
    int Numfatura();
}; 
#endif