#include <iostream>
using namespace std;

// criar struct
struct Fila
{
  static constexpr int tam_v = 5;
  int p, n = 0;
  char v[tam_v];
};
// inicializar
void inicializar(Fila &F)
{
  F.p = -1;
}

// se vazia ou se cheia
bool vazia(Fila &F)
{
  return (F.p == -1);
}

bool cheia(Fila &F)
{
  if (F.p == -1) return false;
  return (F.n + 1) % F.tam_v == F.p;
}

bool enfilar(Fila &F, char c)
{
  if (cheia(F)) return false;

  if (F.p == -1)
  {
    F.p = F.n = 0;
  }
  else
  {
    if (F.n == F.tam_v - 1)
    {
      F.n = 0;
    }
    else
    {
      F.n++;
    }
  }
  F.v[F.n] = c; // Adicionando o elemento ao vetor antes de incrementar F.n
  return true;
}

char primeiro(Fila &F)
{
  return F.v[F.p];
}

bool desenfila(Fila &F)
{
  if (F.p == -1)
    return false;
  if (F.n == F.p)
    F.p = -1;
  else
    F.p = (F.p + 1) % F.tam_v;

  F.n--;
  return true;
}

int main (){

  Fila F;
  inicializar(F);

  for(;;){
    cout << "Operacao (Enfilar, Desenfilar, Primeiro, Sair): ";
    char opcao;
    cin >> opcao;

    if (opcao == 'E')
    {
      cout << "Elemento a inserir: ";
      char elemento;
      cin >> elemento;
      if (enfilar(F, elemento)) cout << "Enfilado.\n";
      else                      cout << "Cheia!\n";
    }
    else if (opcao == 'D')
    {
      if(vazia(F)) cout << "Inviavel, vazia.\n"; //se retornar verdadeiro
      else{
        cout << "Vai ser desenfilado: "
        << primeiro (F)
        << '\n';
        desenfila(F);
      }
    }
    else if (opcao == 'P'){
      if (vazia(F)) cout << "Inviável, vazia!\n";
      else
      {
        cout << "Primeiro: " << primeiro(F) << '\n';
      }
    }
    else if (opcao == 'S') break;
    else{
      cout << "Opcao invalida!\n";
    }
  }
}


