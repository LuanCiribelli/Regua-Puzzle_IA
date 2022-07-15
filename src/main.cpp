#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Algoritmos/NaoInformados/BuscaEmLargura.cpp"
#include "Algoritmos/NaoInformados/BuscaEmProfundidade.cpp"
#include "Estruturas/Headers/Estado.hpp"
#include "Estruturas/Jarros.cpp"
#include "Estruturas/ReguaPuzzle.hpp"

#ifdef _WIN64
#include <windows.h>
#else
#include <unistd.h>
#endif

std::fstream inputFile;
std::fstream outputFile;

// Declaração das funções para utilizadas
void runSemArgumentos();
void menu();
void menu2();
void limpaTela();

using namespace std;

/*******************************************
 * Autor: Luan Reis Ciribelli
 * Desde: 13/07/2022
 *******************************************/

int main(int argc, char *argv[]) {

  if (argc == 1) {
    runSemArgumentos();
    return 0;
  } else {

    if (argc == 3) {
      inputFile.open(argv[1], ios::in);   // Abre o Arquivo de Entrada
      outputFile.open(argv[2], ios::out); // Abre o Arquivo de Saida

      if (!inputFile) {
        cerr << "Erro ao Abrir o Arquivo de Entrada!" << endl;
        exit(-1);
      }

      if (!outputFile) {
        cerr << "Erro ao Abrir o Arquivo de Saida! " << endl;
        exit(-1);
      }
    } else {
      cerr << "O Algoritmo não localizou os arquivos de Entrada ou de Saída!"
           << endl;
      cerr << "Verifique o Formato de entrada <nome_do_executavel> "
              "<arquivo_de_entrada> <arquivo_de_saida>"
           << "Por exemplo: ab ba";
      cerr << "O arquivo de entrada deve ser formatado da seguinte forma: \n"
           << "Um regua com uma das peças representadas por B e a outra por P, "
              "com um espaço "
           << endl;
      exit(-1);
    }

    cout << "\t\t\tTrabalho de Inteligência Artificial" << endl;
    cout << "Alunos: Luan Reis Ciribelli e João Pedro Carvalho Lima" << endl;
    cout << "Nome do arquivo: " << argv[1] << endl;

    outputFile << "\t\t\tTrabalho de Inteligência Artificial" << endl;
    outputFile << "Alunos: Luan Reis Ciribelli e João Pedro Carvalho Lima"
               << endl;
    outputFile << "Nome do arquivo: " << argv[1] << endl;

    bool menu1 = true;
    int n;
    int opcaoEscolhida;
    int opcaoEscolhida2;
    bool jarros = false;
    string arquivo = argv[1];
    vector<char> regua;
    ReguaPuzzle *reg;

    int count = 1;
    char letter; // variable for input value

    inputFile >> letter;
    cout << "Regua: ";
    while (letter != ';') {
      cout << letter;
      regua.push_back(letter);
      inputFile >> letter;
      count++;
    }

    cout << endl;

    n = count;

    while (true) {

      if (n > 0) {
        break;
      } else {
        cout << "Favor entrar com arquivo valido!";
        exit(-1);
      }
    }
    while (menu1) {

      menu();
      cin >> opcaoEscolhida;
      switch (opcaoEscolhida) {
      case 0:

        inputFile.close();
        outputFile.close();
        cout << "Fechando programa" << endl;
        exit(0);
        break;
      case 1:
        cout << "Ainda Não implementado" << endl;
        break;
      case 2:
        cout << "Ainda Não implementado" << endl;
        break;
      case 3:
        cout << "Ainda Não implementado" << endl;
        break;
      case 4:
        cout << "Ainda Não implementado" << endl;
        break;
      case 5:
        cout << "Ainda Não implementado" << endl;
        break;
      case 6:
        cout << "Ainda Não implementado" << endl;
        break;
      case 7:
        cout << "Ainda Não implementado" << endl;
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
    while (jarros) {

      menu2();
      cin >> opcaoEscolhida2;
      switch (opcaoEscolhida2) {
      case 0:

        inputFile.close();
        outputFile.close();
        cout << "Fechando programa" << endl;
        exit(0);
        break;
      case 1:
        cout << "Ainda Não implementado" << endl;
        break;
      case 2:
        outputFile << "BUSCA EM LARGURA" << endl;
        BuscaEmLargura::run(new Jarros(0, 0), new Jarros(-1, 2));

        break;
      case 3:

        outputFile << "BUSCA EM PROFUNDIDADE" << endl;

        BuscaEmProfundidade::run(new Jarros(0, 0), new Jarros(2, -1));
        break;
      case 4:
        cout << "Ainda Não implementado" << endl;
        break;
      case 5:
        cout << "Ainda Não implementado" << endl;
        break;
      case 6:
        cout << "Ainda Não implementado" << endl;
        break;
      case 7:
        cout << "Ainda Não implementado" << endl;
        break;
      default:
        cout << "Parametro invalido, favor escolher uma opção valida";

        break;
      }
    }
  }

  inputFile.close();
  outputFile.close();
  return 0;
}

/*
 * Função que roda o programa sem um arquivo para ler ou para salvar
 */
void runSemArgumentos() {

  cout << "\t\t\tTrabalho de Inteligência Artificial" << endl;
  cout << "Alunos: Luan Reis Ciribelli e João Pedro Carvalho Lima" << endl;

  bool menu1 = true;
  int n;
  int opcaoEscolhida;
  int opcaoEscolhida2;
  bool jarros = false;

  while (true) {
    cout << "\nFavor escolhe o tamanho N da regua:";
    cin >> n;

    if (n > 0) {
      break;
    } else {
      cout << "Favor escolher um numero valido!";
    }
  }

  while (menu1) {
    menu();
    cin >> opcaoEscolhida;

    switch (opcaoEscolhida) {
    case 0:
      cout << "Fechando programa" << endl;
      exit(0);
      break;
    case 1:
      cout << "Ainda Não implementado" << endl;
      break;
    case 2:
      cout << "Ainda Não implementado" << endl;
      break;
    case 3:
      cout << "Ainda Não implementado" << endl;
      break;
    case 4:
      cout << "Ainda Não implementado" << endl;
      break;
    case 5:
      cout << "Ainda Não implementado" << endl;
      break;
    case 6:
      cout << "Ainda Não implementado" << endl;
      break;
    case 7:
      cout << "Ainda Não implementado" << endl;
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
  while (jarros) {

    menu2();
    cin >> opcaoEscolhida2;
    switch (opcaoEscolhida2) {
    case 0:
      cout << "Fechando programa" << endl;
      exit(0);
      break;
    case 1:
      cout << "Ainda Não implementado" << endl;
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
      cout << "Ainda Não implementado" << endl;
      break;
    case 5:
      cout << "Ainda Não implementado" << endl;
      break;
    case 6:
      cout << "Ainda Não implementado" << endl;
      break;
    case 7:
      cout << "Ainda Não implementado" << endl;
      break;
    default:
      cout << "Parametro invalido, favor escolher uma opção valida";

      break;
    }
  }
}

/*
 * Menu para interação com usuario da ferramenta
 */
void menu() {
  cout << "\t\tAlgoritmos para o regua-puzzle:" << endl;
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
 * Menu iterativo criado para os desenvolvedores, testar os algoritmos num caso
 * mais simples
 */
void menu2() {
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
void limpaTela() {
  for (int i = 0; i < 50; i++) {
    cout << "\n";
  }
}
