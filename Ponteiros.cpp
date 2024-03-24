/*a) Escreva uma função "void inverter (double *p, int n)" que inverta a ordem dos "n"
elementos do vetor (cujo primeiro elemento é) apontado por "p", ou seja, o último número
deve passar a estar na primeira posição, o penúltimo na segunda, etc. Utilize a indexação
de ponteiros abordada no final da aula de hoje.

//b) Escreva em C++ um programa que comece lendo do usuário um inteiro positivo "n", que
deve ser no máximo 10. Em seguida, o programa deve ler "n" double's do usuário, armazenando-os
num vetor (que, neste exercício, pode ter tamanho exatamente 10, mesmo que apenas as "n"
primeiras posições sejam utilizadas). Em seguida, o programa deve inverter a ordem dos "n"
números gravados no vetor, chamando a função do item anterior. Por fim, os "n" números do
vetor devem ser impressos na tela (ou seja, serão impressos em ordem inversa em relação à
ordem de leitura). Importante: embora o efeito externo do programa seja apenas imprimir os
números na ordem inversa da leitura, o programa deve funcionar conforme explicado neste
enunciado; a intenção do exercício é escrever e testar a função "inverter".

a) Escreva uma função "int remover_ocorrencias (double v, int n, double x)" que, recebendo
um (ponteiro apontando para um) vetor "v" de "n" double's e um double "x", remova as eventuais
ocorrências de "x" nas "n" posições do vetor. A função também deve informar a quantidade de
números restantes no vetor. Exemplo:
   · Se "n" for 10,
   · "v" possuir os números { 10, 2, -7, 4, 2, 2, 9, 2, 3, 2 }
   · e "x" for 2,
então o estado final do vetor deve ser { 10, -7, 4, 9, 3, ?, ?, ?, ?, ? } e a função deve
retornar 5.

b) Analogamente ao exercício anterior, escreva um programa para testar a função acima: leia a
entrada do usuário e imprima o resultado ao final.

*/
/*
#include <iostream>
using namespace std;

void inverter(double *p, int n) { //double p aponta para o vetor
    //declara ponteiros para início e para o fim
    double *i = p;
    double *f = p+n-1; //final do vetor

    while (i<f){ //repassar até o final do vetor
    //cria um variavel para armazenar inicio
    double armazena_ini = *i; //aacessa o valor armazenado no ponteiro
    *i = *f;
    *f = armazena_ini;

    i++; //move os ponteiro (posições)
    f--; //vai movendo a posição final para n-1
    }
}

int main()
{
    int quant;
    double v[10];

    cout << "Digite um inteiro: \n";
    cin >> quant;

    if(quant <= 0 || quant > 10){
        cout << "Número inválido!\n";
    }
    else{
    cout << "Insira os numeros: \n";
    for(int i=0; i<quant; i++){
        cin >> v[i]; //recebe os elementos do vetor
    }

    inverter(v, quant);

    cout << "Numeros invertido: \n";
    for(int i=0; i<quant;i++){
        cout << v[i] << '\n';
    }
    }
}
*/
#include <iostream>
using namespace std;

int remover_ocorrencias(double *v, int n, double x)
{

    int i = 0;

    while (i < n)
    { // percorre as posições
        if (v[i] == x)
        {
            for (int j = i; j < n; j++)
            {                    // vai do elemento a ser tirado ao fim do vetor
                v[j] = v[j + 1]; // move os valores para a esquerda
            }
            n--; // diminui as posições
        }
        i++; // adiciona posições
    }
    return n; // retorna o valor atualizado do número de posições
}

int main()
{
    const int max_vetor = 100;
    double vetor[max_vetor];
    int cont;

    cout << "Digite um inteiro: \n";
    cin >> cont;

    if (cont <= 0 || cont > 10)
    {
        cout << "Número inválido!\n";
    }

    else
    {
        cout << "Digite os numeros:\n";
        for (int i = 0; i < cont; i++)
        {
            cin >> vetor[i];
        }

        cout << "Digite o numero a ser removido:\n";
        double elemento;
        cin >> elemento;

        int tamanho = remover_ocorrencias(vetor, cont, elemento);

        cout << "Elementos restantes:\n";
        for (int i = 0; i < tamanho; i++)
        {
            cout << vetor[i] << '\n';
        }
    }
}