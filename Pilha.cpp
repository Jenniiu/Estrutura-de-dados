#include <iostream>
using namespace std;

struct Pilha
{
  static constexpr int tam_v = 5;
  char v[tam_v];
  int t;
};

// inicializar a pilha
void
inicializar(Pilha &P)
{
  P.t = -1;
}

// vazia
bool vazia(Pilha &P)
{
  return (P.t == -1);
}

// cheia
bool cheia(Pilha &P)
{
  if(vazia(P)) return false;
  return (P.t + 1 == P.tam_v);
}

//empilhar
bool empilhar (Pilha &P, char c)
{
  if(cheia(P)) return false;
  else{
    P.t++; //incrementa o topo
    P.v[P.t] = c; //c ocupa o topo
    return true;
  }
}

//topo
char topo (Pilha &P)
{
  return P.v[P.t];
}

//desempilhar
bool desempilhar (Pilha &P)
{
  if(vazia(P)) return false;
  else{
    P.t--;
    return true; //sempre lembrar de retornar true
  }
}

int main()
{
  Pilha P;
  inicializar(P);

  for(;;) //loop até break
  {
    cout << "Escolha: Inserir, Conferir, Remover, Sair\n";
    char opcao;
    cin >> opcao;

    if(opcao == 'I')
    {
      cout << "Digite o elemento:\n";
      char elemento;
      cin >> elemento;

      if(empilhar(P,elemento)) cout << "Inserido!\n";
      else cout << "Cheia!\n";
    }

    else if(opcao == 'C')
    {
      if(vazia(P)) cout << "Vazia!\n";
      cout << "Elemento no topo:\n" << topo(P) << '\n';
    }

    else if(opcao == 'D')
    {
      if(desempilhar(P)) cout << "Removido!\n";
      else cout << "Vazia!\n";
    }
    else if (opcao == 'S') break;
    else cout << "Opcao invalida!\n";
  }
}