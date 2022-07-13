#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Estruturas/Headers/Estado.hpp"
#include "Estruturas/Jarros.cpp"
#include "Algoritmos/NaoInformados/BuscaEmProfundidade.cpp"
#include "Algoritmos/NaoInformados/BuscaEmLargura.cpp"

std::fstream inputFile;
std::fstream outputFile;

bool salvar = false;
void menu();
void menu2();
int **estadoFinal(int n);
void limpaTela();
bool viabilidade();

using namespace std;

/*******************************************
 * Autor: Luan Reis Ciribelli
 * Desde: 13/07/2022
 *******************************************/

int main()
{

    cout << "\t\t\tTrabalho de Inteligência Artificial" << endl;
    cout << "Alunos: Luan Reis Ciribelli e João Pedro Carvalho Lima" << endl;

    bool menu1 = true;
    int n;
    int opcaoEscolhida;
    int opcaoEscolhida2;
    bool jarros = false;

    while (true)
    {
        cout << "\nFavor escolher a ordem N do jogo:";
        cin >> n;

        if (n > 0)
        {
            break;
        }
        else
        {
            cout << "Favor escolher um numero valido!";
        }
    }

    int **matrizFinal = estadoFinal(int n);
    limpaTela();
    while (menu1)
    {

        menu();
        cin >> opcaoEscolhida;
        switch (opcaoEscolhida)
        {
        case 0:
            cout << "Fechando programa" << endl;
            exit(0);
            break;
            break;
        case 1:
            // TODO: Definir como o vetor recebera os parametros para o jogo
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 7:
            /* code */
            break;
        case 8:
            menu1 = false;
            jarros = true;
            break;
        default:
            cout << "Parametro invalido, favor escolher uma opção valida";
            break;
        }
    }
    limpaTela();
    while (jarros)
    {

        menu2();
        cin >> opcaoEscolhida2;
        switch (opcaoEscolhida2)
        {
        case 0:
            cout << "Fechando programa" << endl;
            exit(0);
            break;
        case 1:
            // TODO: Definir como o vetor recebera os parametros para o jogo
            break;
        case 2:
            cout << "BUSCA EM LARGURA" << endl;
            BuscaEmLargura::run(new Jarros(0, 0), new Jarros(-1, 2));

            break;
        case 3:

            cout << "BUSCA EM PROFUNDIDADE" << endl;

            BuscaEmProfundidade::run(new Jarros(0, 0), new Jarros(2, -1));
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 7:
            /* code */
            break;
        default:
            cout << "Parametro invalido, favor escolher uma opção valida";

            break;
        }
    }

    return 0;
}

/*
 * Menu para interação com usuario da ferramenta
 */
void menu()
{
    cout << "\t\tAlgoritmos para o N-puzzle:" << endl;
    cout << "[01] - Backtracking; " << endl;
    cout << "[02] - Busca em Largura; " << endl;
    cout << "[03] - Busca em Profundidade (Limitada);" << endl;
    cout << "[04] - Busca Ordenada;" << endl;
    cout << "[05] - Busca Gulosa;" << endl;
    cout << "[06] - Busca A*;" << endl;
    cout << "[07] - Busca IDA*." << endl;
    cout << "[0] - Sair. " << endl;
    cout << "Escolha: ";
}

/*
 * Menu iterativo criado para os desenvolvedores, testar os algoritmos num caso mais simples
 */
void menu2()
{
    cout << "\t\tAlgoritmos para o Jogo dos Jarros" << endl;
    cout << "[01] - Backtracking; " << endl;
    cout << "[02] - Busca em Largura; " << endl;
    cout << "[03] - Busca em Profundidade (Limitada);" << endl;
    cout << "[04] - Busca Ordenada;" << endl;
    cout << "[05] - Busca Gulosa;" << endl;
    cout << "[06] - Busca A*;" << endl;
    cout << "[07] - Busca IDA*." << endl;
    cout << "[0] - Sair. " << endl;
    cout << "Escolha: ";
}

/*
 * Função que limpa o terminal
 */
void limpaTela()
{
    for (int i = 0; i < 50; i++)
    {
        cout << "\n";
    }
}

/*
 * Função que retorna a matriz objetivo, incialmente almejamos a matriz de tamanho n em order numerica
 */
int **estadoFinal(int n)
{

int count ==0;
int** matrix = new int*[n]; 

    for (int i = 0; i < n; i++) {
 
        matrix[i] = new int[n];
 
        for (int j = 0; j < n; j++, x++) {
 
            matrix[i][j] = count;
            count++;
        
        }
    }
    return matrix;
}

void imprimeEstadoInicial(int ** matrix,int n){


}


void imprimeEstadoFinal(int ** matrix,int n){
   for (int i = 0; i < m; i++) {
        printf("\n");
        for (int j = 0; j < n; j++) {
              printf("%d\t", matrix[i*n+j]);
        }
    }

}

/*
 * Função que verifica a viabilidade da resolução da matriz passada
 */
bool viabilidade()
{
    return true;
}