//Fila
#include <iostream>
using namespace std;

struct Fila
{
  // cria um vetor e 5 posições
  static constexpr int tam_v = 5;
  char v[tam_v];
  int p, u; // para o início e fim da fila
};
// inicializa a fila
void inicializar(Fila &F)
{
  F.p = -1;
}
// ver se está vazia
bool vazia(Fila &F)
{
  return (F.p == -1);
}
// ver se está cheia
bool cheia(Fila &F)
{
  if (F.p == -1) return false;
  return (F.u + 1) % F.tam_v == F.p; // verifica circularidade
}
// enfilar fila
bool enfilar(Fila &F, char c)
{
  if (cheia(F)) return false; // chama a função cheia
  if (F.p == -1)
  { // verifica se vazia
    F.p = F.p = 0;
  }
  else
  {
    if (F.u == F.tam_v - 1)
      F.u = 0; // verifica se no final
    else
      ++F.u; // se não só adicioa
  }
  F.v[F.u] = c; // comum para todos os casos;
  return true;
}
char primeiro(Fila &F)
{
  return F.v[F.p];
}
//desnfila
bool desenfila (Fila &F){
  if (F.p == -1) return false;
  if (F.u == F.p) F.p = -1;
  //incrementa F.p em 1 e se passa do fim da fila volta pro inicio
  else            F.p = (F.p + 1) % F.tam_v;
  //retorna true se der certo
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
