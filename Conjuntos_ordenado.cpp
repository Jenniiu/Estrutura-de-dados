#include <iostream>
using namespace std;

struct Conjunto
{
  char v[10]; // ordenado
  int n = 0;
};

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

void deslocarDireita(Conjunto &C, int pos)
{
  for (int i = C.n; i > pos; i--)
  {
    C.v[i] = C.v[i - 1];
  }
}

bool inserir_se(Conjunto &C, char x)
{
  if (C.n >= 10)
  {
    cout << "Erro: Conjunto cheio." << '\n';
    return false;
  }

  int pos = 0;
  while (pos < C.n && C.v[pos] < x)
  {
    pos++;
  }

  if (pos < C.n && C.v[pos] == x)
    return false; // Elemento já existe no conjunto

  deslocarDireita(C, pos);

  C.v[pos] = x;
  C.n++;
  return true;
}

bool remover(Conjunto &C, char x)
{
  int i = 0, f = C.n - 1;
  while (i <= f) // enquanto o inicio for menor ou igual ao final
  {
    if (x == C.v[i])
    {
      for (int j = i; j < C.n - 1; j++)
      {
        C.v[j] = C.v[j + 1];
      }
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
      if (remover(C, elemento))
        cout << "Removido!\n";
      else
        cout << "Elemento não encontrado!\n";
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
        cout << "Elemento não pertence\n";
    }
    else if (opcao == 'S')
      break;
    else
      cout << "Opcao invalida!\n";
  }
}
