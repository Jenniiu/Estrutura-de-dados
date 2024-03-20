#include <iostream>
#include <string>
using namespace std;

struct Par{
  char chaves[10];
  string valores[10];
  int n = 0;
};

//string consultar e retorna o valor, pois ela retorna uma string n um bool
string conferir(Par &P, char c)
{
  int i = 0; 
  int f = P.n - 1;

//busca binária achar a chave corresponente
  while(i<=f){
    int m = i + (f-i) / 2;

    if (c == P.chaves[m]) return P.valores[m]; //se pertencer
    if (c < P.chaves[m]) f=m-1;
    else i = m+1;
  }
  return "Chave não pertence"; //se não pertencer
}

//inserir
bool inserir (Par &P, char c, string v)
{ 
  string resultado = conferir(P, c);
  if(resultado != "Chave não pertence") return false;
  else{
    if(P.n >= 10){
      cout << "Dicionario cheio!\n";
      return false;
    }
    else{
    P.chaves[P.n] = c;
    P.valores[P.n] = v;
    P.n++;
    return true;
    }
  }
}

//remover
bool remover (Par &P, char c)
{
  string resultado = conferir(P, c);
  if(resultado == "Chave não pertence") return false;
  else{
    int i = 0; 
    int f = P.n - 1;
    while(i<=f){
      if(P.chaves[i] == c){
        P.chaves[i] = P.chaves[f];
        P.valores[i] = P.valores[f];
        P.n--;
        return true;
      }
      i++;
    }
    return false;
  }
}

int main(){

  Par P;

  for(;;)
  {
    cout << "Operacoes: Inserir, Remover, Consultar, Sair\n";
    char opcao;
    cin >> opcao;

    if(opcao == 'I')
    {
      cout << "Chave a ser inserida:\n";
      char chave;
      cin >> chave;

      cout << "Valor a ser inserido:\n";
      string valor;
      cin >> valor;

      if(inserir (P, chave, valor)) cout << "Inserido!\n";
      else cout << "Chave já existe;\n";
      
    }
    else if(opcao == 'R')
    {
      cout << "Chave a ser removida:\n";
      char chave;
      cin >> chave;

      if(remover(P, chave)) cout << "Removido!\n";
      else cout << "Chave não existe\n";
    }
    else if(opcao == 'C'){
      cout << "Insira a chave:\n";
      char chave;
      cin >> chave;

      string resposta = conferir(P, chave);
      if(resposta != "Chave não pertence"){
        cout << "Valor = " << resposta << "\n";
      }
      else cout << "Chave não encontrada\n";
    }
    else if (opcao == 'S') break;
    else cout << "Opcao invalida!\n";
  }
}

