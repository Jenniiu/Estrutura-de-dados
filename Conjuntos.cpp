#include <iostream>
using namespace std;

struct Conjunto
{
  char v[10]; // ordenado
  int n = 0;
};
// pertence ou n?
bool pertence(Conjunto &C, char x)
{
  int i = 0, f = C.n - 1; // inicio e final

  while (i <= f) // enquanto o inicio for menor ou igual ao final
  {
    int m = i + (f - i) / 2; // evita overflow

    if (x == C.v[m])
      return true; // se o valor é igual ao valor da posição média
    // se o valor é menor ao valor da posição média
    if (x < C.v[m])
      f = m - 1;
    // final é retrocede metade das posições
    else
      i = m + 1; // início pula metade das posições
  }
  return false;
}

bool inserir(Conjunto &C, char x)
{
  if (C.n >= 10)
  {
    cout << "Erro: Conjunto cheio." << '\n';
    return false;
  }
  C.v[C.n] = x;
  C.n++;
  return true;
}

bool inserir_se(Conjunto &C, char x)
{
  if (pertence(C, x))
    return false;
  else
    return inserir(C, x); // retorna o resultado da operação
}

bool remover(Conjunto &C, char x)
{
  int i = 0, f = C.n - 1;
  while (i <= f) // enquanto o inicio for menor ou igual ao final
  {
    if (x == C.v[i])
    {
      C.v[i] = C.v[f];
      C.n--;
      return true;
    }
    i++;
  }
  return false;
}

int main()
{

  Conjunto C;

  for (;;)
  {
    cout << "Operacoes: Inserir, Remover, Pertence, Sair: \n";
    char opcao;
    cin >> opcao;

    if (opcao == 'I')
    {
      cout << ("Elemento a ser inserido: \n");
      char elemento;
      cin >> elemento;
      if (inserir_se(C, elemento))
        cout << "Inserido!\n";
      else
        cout << "Elemento já existe!\n";
    }
    else if (opcao == 'R')
    {
      cout << ("Elemento a ser removido: \n");
      char elemento;
      cin >> elemento;
      remover(C, elemento);
      cout << "Removido!\n";
    }
    else if (opcao == 'P')
    {
      cout << ("Elemento: \n");
      char elemento;
      cin >> elemento;
      if (pertence(C, elemento))
      {
        cout << "Elemento pertence!\n";
      }
      else
        cout << "Elemento nao pertence\n";
    }
    else if (opcao == 'S')
      break;
    else
      cout << "Opcao invalida!\n";
  }
}