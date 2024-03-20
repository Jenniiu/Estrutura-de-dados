#include <iostream>
#include <string>
using namespace std;

// Estrutura para representar o dicionário
struct Par {
    char chaves[10];
    string valores[10];
    int n = 0;
};

// Função para buscar o valor associado a uma chave
string conferir(Par &P, char c) {
    int ini = 0, fim = P.n - 1;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        if (P.chaves[meio] == c) {
            return P.valores[meio]; // Chave encontrada, retorna o valor associado
        } else if (P.chaves[meio] < c) {
            ini = meio + 1; // Vá para a metade direita
        } else {
            fim = meio - 1; // Vá para a metade esquerda
        }
    }
    return "Chave não pertence"; // Chave não encontrada
}

// Função para inserir uma chave e um valor no dicionário
bool inserir(Par &P, char c, string v) {
    // Verifica se a chave já existe no dicionário
    if (conferir(P, c) != "Chave não pertence") {
        return false; // Chave já existe, não é possível inserir
    }
    // Verifica se o dicionário está cheio
    if (P.n >= 10) {
        cout << "Dicionário cheio!\n";
        return false; // Dicionário cheio, não é possível inserir
    }
    // Insere a chave e o valor no dicionário
    int pos = 0;
    while (pos < P.n && P.chaves[pos] < c) {
        pos++;
    }
    for (int i = P.n; i > pos; i--) {
        P.chaves[i] = P.chaves[i - 1];
        P.valores[i] = P.valores[i - 1];
    }
    P.chaves[pos] = c;
    P.valores[pos] = v;
    P.n++;
    return true; // Chave inserida com sucesso
}

// Função para remover uma chave do dicionário
bool remover(Par &P, char c) {
    // Busca binária para encontrar a posição da chave
    int ini = 0, fim = P.n - 1;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        if (P.chaves[meio] == c) {
            // Remove a chave e o valor
            for (int i = meio; i < P.n - 1; i++) {
                P.chaves[i] = P.chaves[i + 1];
                P.valores[i] = P.valores[i + 1];
            }
            P.n--;
            return true; // Chave removida com sucesso
        } else if (P.chaves[meio] < c) {
            ini = meio + 1; // Vá para a metade direita
        } else {
            fim = meio - 1; // Vá para a metade esquerda
        }
    }
    return false; // Chave não encontrada, não foi possível remover
}

int main() {
    Par P;

    // Menu principal
    for (;;) {
        cout << "Operações: Inserir, Remover, Consultar, Sair\n";
        char opcao;
        cin >> opcao;

        if (opcao == 'I') {
            cout << "Chave a ser inserida:\n";
            char chave;
            cin >> chave;

            cout << "Valor a ser inserido:\n";
            string valor;
            cin >> valor;

            if (inserir(P, chave, valor)) {
                cout << "Inserido!\n";
            } else {
                cout << "Chave já existe;\n";
            }

        } else if (opcao == 'R') {
            cout << "Chave a ser removida:\n";
            char chave;
            cin >> chave;

            if (remover(P, chave)) {
                cout << "Removido!\n";
            } else {
                cout << "Chave não existe\n";
            }

        } else if (opcao == 'C') {
            cout << "Insira a chave:\n";
            char chave;
            cin >> chave;

            string resposta = conferir(P, chave);
            if (resposta != "Chave não pertence") {
                cout << "Valor = " << resposta << "\n";
            } else {
                cout << "Chave não encontrada\n";
            }

        } else if (opcao == 'S') {
            break;
        } else {
            cout << "Opção inválida!\n";
        }
    }

    return 0;
}

