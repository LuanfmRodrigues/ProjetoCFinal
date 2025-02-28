#include <iostream>
#include <string>
#include <cctype> // Para usar a função isdigit
using namespace std;

// Função para validar o telefone (verifica se tem exatamente 9 dígitos)
bool validarTelefone(const string& telefone) {
    if (telefone.length() != 9) {
        return false;  // O telefone não tem 9 dígitos
    }
    for (char c : telefone) {
        if (!isdigit(c)) {
            return false;  // Contém caracteres não numéricos
        }
    }
    return true;
}

