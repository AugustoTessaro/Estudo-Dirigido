#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

const int num_dezenas_MS = 60, num_dezenas_Q = 81, num_dezenas_LF = 26, num_dezenas_LM =  101;//Número de dezenas possíveis em cada jogo.
const int min_nums_MS = 6, max_nums_MS = 15, min_nums_Q = 5, max_nums_Q = 15, min_nums_LF = 15, max_nums_LF = 18;//Números máximos/mínimos de dezenas que podem ser apostadas.
int qtd_dezenas = 0, qtd_apostas = 0; //Váriaveis globais que recebem a quantidade de apostas e a quantidade de dezenas.

void tabela();                                                                                    //Declaração das funções.
void nomes_jogos(int jogo);
int quantidade_apostas(int tipo_jogo);
int quantidade_dezenas(int minimo, int maximo, int tipo_jogo);
void GerarDezenas(int numero_de_apostas, int numero_de_dezenas, int MAX_dezenas, int tipo_jogo);
void mostra_preco(int num, int dezenas, int apostas);

int main() //Código principal.
{
    setlocale(LC_ALL, "Portuguese");

    char escolha_jogo;
    int num_apostas, dezenas, continuar = 1;

    while(continuar == 1)
    {
        tabela();
        cin >> escolha_jogo;

        system("CLS");

        switch(escolha_jogo)
        {
            case '1':
                quantidade_apostas(escolha_jogo);
                quantidade_dezenas(min_nums_MS, max_nums_MS, escolha_jogo);
                GerarDezenas(qtd_apostas, qtd_dezenas, num_dezenas_MS, escolha_jogo);
                mostra_preco(escolha_jogo, qtd_dezenas, qtd_apostas);
                break;
            case '2':
                quantidade_apostas(escolha_jogo);
                quantidade_dezenas(min_nums_Q, max_nums_Q, escolha_jogo);
                GerarDezenas(qtd_apostas, qtd_dezenas, num_dezenas_Q, escolha_jogo);
                mostra_preco(escolha_jogo, qtd_dezenas, qtd_apostas);
                break;
            case '3':
                quantidade_apostas(escolha_jogo);
                quantidade_dezenas(min_nums_LF, max_nums_LF, escolha_jogo);
                GerarDezenas(qtd_apostas, qtd_dezenas, num_dezenas_LF, escolha_jogo);
                mostra_preco(escolha_jogo, qtd_dezenas, qtd_apostas);
                break;
            case '4':
                quantidade_apostas(escolha_jogo);
                nomes_jogos(escolha_jogo);
                cout << "====================================================================================\n"
                     << "|O número de dezenas da lotomania não pode ser escolhido, 50 dezenas serão geradas.|\n"
                     << "====================================================================================\n";
                system("pause");
                system("CLS");
                GerarDezenas(qtd_apostas, 50, num_dezenas_LM, escolha_jogo);
                mostra_preco(escolha_jogo, 50, qtd_apostas);
                break;
            case '0':
                cout << "ATÉ A PRÓXIMA!";
                return 0;
        }

        system("pause");

        cout << "\nDeseja gerar novas apostas?(Se [SIM] as apostas atuais serão perdidas, se [NÃO] o pograma irá se encerrar).\n";
        cout << "===========\n"
             << "| [1] SIM |\n"
             << "===========\n"
             << "| [0] NÃO |\n"
             << "===========\n";
        cin >> continuar;
        system("CLS");
    }

    cout << "ATÉ A PRÓXIMA!";
}

void tabela() //Função que mostra a tabela de boas vindas e da as opções de escolha iniciais.
{
    cout << "===================================\n"
         << "| GERADOR DE DEZENAS PARA LOTERIA |\n"
         << "|         SEJA BEM VINDO!         |\n"
         << "===================================\n"
         << "===================================\n"
         << "|  EM QUAL JOGO DESEJA APOSTAR?   |\n"
         << "===================================\n"
         << "|          [1]MEGA-SENA           |\n"
         << "===================================\n"
         << "|            [2]QUINA             |\n"
         << "===================================\n"
         << "|          [3]LOTOFÁCIL           |\n"
         << "===================================\n"
         << "|          [4]LOTOMANIA           |\n"
         << "===================================\n"
         << "|    [0]ENCERRAR DO APLICATIVO    |\n"
         << "===================================\n";
}

void nomes_jogos(int jogo) //Função que exibe o nome do jogo durante a execução do aplicativo.
{
    switch(jogo)
    {
        case '1':
            cout << "=============\n"
                 << "| MEGA-SENA |\n"
                 << "=============\n";
            break;
        case '2':
            cout << "=========\n"
                 << "| QUINA |\n"
                 << "=========\n";
            break;
        case '3':
            cout << "=============\n"
                 << "| LOTOFÁCIL |\n"
                 << "=============\n";
            break;
        case '4':
            cout << "=============\n"
                 << "| LOTOMANIA |\n"
                 << "=============\n";
            break;
    }
}

int quantidade_apostas(int tipo_jogo) //Função que recebe o número de apostas, limitando-os a números positivos.
{
    int numero_de_apostas;

    do
    {
        nomes_jogos(tipo_jogo);

        cout << "===============================\n"
             << "|Quantas apostas deseja gerar?|\n"
             << "===============================\n";
        cin >> numero_de_apostas;
        system("CLS");
        if(numero_de_apostas < 0)
        {
            cout << "APENAS NÚMEROS POSITIVOS!\n";
        }

    }while(numero_de_apostas < 0);

    qtd_apostas = numero_de_apostas;
}

int quantidade_dezenas(int minimo, int maximo, int tipo_jogo) //Função que recebe a quantidade de dezenas a serem apostadas, respeitando os limites de mínimo e máximo de cada jogo.
{
    int numero_de_dezenas;

    do
    {
        nomes_jogos(tipo_jogo);

        cout << "===========================================================================\n"
             << "|Insira a quantidade de dezenas que deseja apostar:(mínimo " << minimo << "/ máximo " << maximo << ") |\n"
             << "===========================================================================\n";
        cin >> numero_de_dezenas;
        system("CLS");
        if(numero_de_dezenas < minimo || numero_de_dezenas > maximo)
        {
            cout << "|Esse número de dezenas está fora do intervalo permitido!|\n";
        }
    }while(numero_de_dezenas < minimo || numero_de_dezenas > maximo);

    qtd_dezenas = numero_de_dezenas;
}

void GerarDezenas(int numero_de_apostas, int numero_de_dezenas, int MAX_dezenas, int tipo_jogo) //Essa função gera as dezenas de forma aleatória, sem números repetidos e os imprime.
{
    srand(time(NULL));

    vector <int> dezenas_geradas;
    int dezena, teste[numero_de_apostas];

    nomes_jogos(tipo_jogo);

    for(int i = 0; i < numero_de_apostas; i++)
    {

        for(int j = 0; j < numero_de_dezenas; j++)
        {
            dezena = rand() % (MAX_dezenas) + 1;
            dezenas_geradas.push_back(dezena);

            for(int k = 0; k < dezenas_geradas.size(); k++)
            {
                if(dezenas_geradas[k] == dezenas_geradas[j] && k != j)
                {
                    dezenas_geradas.pop_back();
                    j--;
                }
            }

        }

        sort(dezenas_geradas.begin(), dezenas_geradas.end(), less<int>());

        cout << "\n" << i + 1 << "° aposta: ";

        for(int j = 0; j < dezenas_geradas.size(); j++)
        {
            if(j < dezenas_geradas.size() - 1)
            {
                cout << dezenas_geradas[j] << "-";
            }
            else
            {
                cout << dezenas_geradas[j] << ";";
            }
        }

        cout << "\n";

        dezenas_geradas.clear();

    }

    cout << "\n";
}

void mostra_preco(int num, int dezenas, int apostas) //Mostra o preço de cada uma das apostas e o total gasto nas apostas.
{
    int teste_MS[10] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, teste_Q[11] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, teste_LF[4] = {15, 16, 17, 18};
    double precos_MS[10] = {3.50, 24.50, 98.00, 294.00, 735.00, 1617.00, 3234.00, 6006.00, 10510.50, 17517.50}, precos_Q[11] = {1.50, 9.00, 31.50, 84.00, 189.00, 378.00, 693.00, 1188.00, 1930.00, 3003.00, 4504.50};
    double precos_LF[4] = {2.00, 32.00, 272.00, 1632.0};
    cout << setprecision(2) << fixed;

    switch(num)
    {
        case '1':
            for(int i = 0; i < 10; i++)
            {
                if(teste_MS[i] == dezenas)
                {

                    cout << "===========================================\n"
                         << "| O preço de cada aposta foi de R$ " << precos_MS[i] << "\n"
                         << "| TOTAL: R$" << precos_MS[i] * apostas <<    "\n"
                         << "===========================================\n";
                }
            }
            break;
        case '2':
            for(int i = 0; i < 11; i++)
            {
                if(teste_Q[i] == dezenas)
                {

                    cout << "===========================================\n"
                         << "| O preço de cada aposta foi de R$ " << precos_Q[i] << "\n"
                         << "| TOTAL: R$" << precos_Q[i] * apostas <<     "\n"
                         << "===========================================\n";
                }
            }
            break;
        case '3':
            for(int i = 0; i < 4; i++)
            {
                if(teste_LF[i] == dezenas)
                {

                    cout << "===========================================\n"
                         << "| O preço de cada aposta foi de R$ " << precos_LF[i] << "\n"
                         << "| TOTAL: R$" << precos_LF[i] * apostas <<     "\n"
                         << "===========================================\n";
                }
            }
            break;
        case '4':

                cout << "===========================================\n"
                     << "| O preço de cada aposta foi de R$ 1.50    \n"
                     << "| TOTAL: R$" << 1.50 * apostas <<           "\n"
                     << "===========================================\n";
            break;
    }
}
