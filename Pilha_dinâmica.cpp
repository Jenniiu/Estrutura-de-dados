#include <iostream>
#include <new>
using namespace std;

struct Pilha {
    int tam;
    double *v; 
    int t; 
};

void inicializar(Pilha &P) {
    P.t = -1;
    P.tam = 1;
    P.v = new double[P.tam]; 
}

double topo (Pilha &P)
{
  return P.v[P.t];
}

bool vazia(Pilha &P) {
    return (P.t == -1);
}

bool cheia(Pilha &P) {
    if (vazia(P)) return false;
    return (P.t + 1 == P.tam);
}

bool empilhar(Pilha &P, double elemento) { 
    if (cheia(P)) {
        int novo_tam = 2 * P.tam;
        double *w = new double[novo_tam];

        
        for (int i = 0; i < P.tam; i++) {
            w[i] = P.v[i];
        }

        delete[] P.v; 
        P.v = w; 
        P.tam = novo_tam; 
    }

    P.t++;
    P.v[P.t] = elemento;

    return true;
}

bool desempilhar(Pilha &P){
    if(vazia(P)) return false;
    else{
        P.t--;
        return true;
    }
}

int main() {
    
    Pilha pilha;
    inicializar(pilha);

    for(;;) //loop até break
  {
    cout << "Escolha: Inserir, Conferir, Remover, Sair\n";
    char opcao;
    cin >> opcao;

    if(opcao == 'I')
    {
      cout << "Digite o elemento:\n";
      double elemento;
      cin >> elemento;

      if(empilhar(pilha,elemento)) cout << "Inserido!\n";
      else cout << "Cheia!\n";
    }

    else if(opcao == 'C')
    {
      if(vazia(pilha)) cout << "Vazia!\n";
      cout << "Elemento no topo:\n" << topo(pilha) << '\n';
    }

     else if(opcao == 'R')
    {
      if(desempilhar(pilha)) cout << "Removido!\n";
      else cout << "Vazia!\n";
    }

    else if (opcao == 'S') break;
    else cout << "Opcao invalida!\n";
  }
}
