#include "validacoes.h"
#include <cctype> // Para usar a função isdigit

// Função para validar o telefone (verifica se tem exatamente 9 dígitos)
bool validarTelefone(const string& telefone) {
    if (telefone.length() != 9) { // Verifica o comprimento
        return false;  // O telefone não tem 9 dígitos
    }
    for (char c : telefone) {
        if (!isdigit(c)) { // Verifica se é um dígito
            return false;  // Contém caracteres não numéricos
        }
    }
    return true;
}