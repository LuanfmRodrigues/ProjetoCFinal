#include <iostream>
#include <string>
#include <cctype> // Para usar a função isdigit
using namespace std;

// Função para verificar se uma string contém apenas dígitos
bool validarTelefone(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) { // verifica se existe caracter, que nesse caso nao pode ter.
            return false;
        }
    }
    return true;
}

