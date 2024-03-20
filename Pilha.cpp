#include <iostream>
using namespace std;

struct Pilha
{
  static constexpr int tam_v = 5;
  char v[tam_v];
  int t; // topo da pilha
};
// inicia a pilha
void inicializar(Pilha &P)
{
  P.t = -1;
}
// se vazia
bool vazia (Pilha &P){
  return (P.t == -1);
}
//se cheia
bool cheia(Pilha &P)
{
  if (P.t == -1)
    return false;
  return (P.t + 1 == P.tam_v);
}
// empilha
bool empilha(Pilha &P, char c)
{
  if (cheia(P))
    return false;
  else
    ++P.t;
  P.v[P.t] = c;
  return true;
}

char topo(Pilha &P)
{
  return P.v[P.t];
}
// desempilha
bool desempilha(Pilha &P)
{
  if (P.t == -1)
    return false;
  else
    --P.t; // o topo, que foi colocao por ultimo não é mais o ultimo
  return true;
}

int main()
{
  Pilha P;
  inicializar(P);

  for (;;)
  {
    cout << "Operações (Empilhar, Desempilhar, Topo, Sair): ";
    char opcao;
    cin >> opcao;

    if (opcao == 'E')
    {
      cout << "Elemento a ser empilhado: \n";
      char elemento;
      cin >> elemento;
      if (empilha(P, elemento))
        cout << "Empilhado!\n";
      else
        "Cheia!\n";
    }
    else if (opcao == 'D')
    {
      if (vazia(P))
        cout << "Inviável, vazia!\n";
      else
      {
        cout << "Desenfilando: "
             << topo(P)
             << '\n';
        desempilha(P);
      }
    }
    else if (opcao == 'T')
    {
      if (vazia(P))
        cout << "Inviável, vazia!\n";
      else
      {
        cout << "Topo: " << topo(P) << '\n';
      }
    }
    else if (opcao == 'S')
      break;
    else
    {
      cout << "Opcao invalida!\n";
    }
  }
}
