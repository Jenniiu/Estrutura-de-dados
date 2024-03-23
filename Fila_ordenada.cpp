#include <iostream>
using namespace std;

struct Fila
{
  static constexpr int tam_v = 5;
  int p, n = 0;
  char v[tam_v];
};

void inicializar(Fila &F)
{
  F.p = -1;
}

bool vazia(Fila &F)
{
  return (F.p == -1);
}

bool cheia(Fila &F)
{
  if (F.p == -1) return false;
  return (F.n + 1) % F.tam_v == F.p;
}

void deslocarDireita(Fila &F, int pos)
{
  for (int i = F.n; i >= pos; i--)
  {
    F.v[(i + 1) % F.tam_v] = F.v[i % F.tam_v];
  }
}

void enfilarOrdenado(Fila &F, char c)
{
  if (cheia(F))
  {
    cout << "Cheia!\n";
    return;
  }

  if (F.p == -1)
  {
    F.p = F.n = 0;
  }
  else
  {
    int pos = 0;
    while (pos < F.n && F.v[pos] < c)
    {
      pos++;
    }

    deslocarDireita(F, pos);

    F.n = (F.n + 1) % F.tam_v;
    F.v[pos] = c;
  }
}

char primeiro(Fila &F)
{
  return F.v[F.p];
}

void desenfila(Fila &F)
{
  if (F.p == -1)
  {
    cout << "Inviável, vazia!\n";
    return;
  }

  if (F.n == F.p)
    F.p = -1;
  else
    F.p = (F.p + 1) % F.tam_v;

  F.n--;
}

int main()
{
  Fila F;
  inicializar(F);

  for (;;)
  {
    cout << "Operacao (Enfilar, Desenfilar, Primeiro, Sair): ";
    char opcao;
    cin >> opcao;

    if (opcao == 'E')
    {
      cout << "Elemento a inserir: ";
      char elemento;
      cin >> elemento;
      enfilarOrdenado(F, elemento);
      cout << "Enfilado.\n";
    }
    else if (opcao == 'D')
    {
      if (vazia(F))
        cout << "Inviável, vazia.\n";
      else
      {
        cout << "Vai ser desenfilado: "
             << primeiro(F)
             << '\n';
        desenfila(F);
      }
    }
    else if (opcao == 'P')
    {
      if (vazia(F))
        cout << "Inviável, vazia!\n";
      else
      {
        cout << "Primeiro: " << primeiro(F) << '\n';
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