#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Algoritmos/Informados/AEstrela.cpp"
#include "Algoritmos/Informados/BuscaGulosa.cpp"
#include "Algoritmos/Informados/IDAEstrela.cpp"
#include "Algoritmos/NaoInformados/Backtracking.cpp"
#include "Algoritmos/NaoInformados/BuscaEmLargura.cpp"
#include "Algoritmos/NaoInformados/BuscaEmProfundidade.cpp"
#include "Algoritmos/NaoInformados/BuscaOrdenada.cpp"
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
              "<arquivo_de_entrada> <arquivo_de_saida>";

      cerr << "O arquivo de entrada deve ser formatado da seguinte forma: \n"
           << "Um regua com uma das peças representadas por B e a outra por P, "
              "com um espaço representado por '-' "
           << "Por exemplo: PB-BP" << endl;
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
    string arquivo = argv[1];
    vector<char> regua;

    int count = 0;
    char letter;
    inputFile >> letter;
    cout << "Regua: ";
    outputFile << "Regua: ";
<<<<<<< HEAD
    while (letter != ';') {
=======
    while (letter != ';') {
>>>>>>> b2ff71933bbc54dcff98591df1244605e14e7639
      cout << letter;
      outputFile << letter;
      regua.push_back(letter);
      inputFile >> letter;
      count++;
    }

    cout << endl;
    outputFile << endl;

    n = count;
    cout << "Com tamanho: " << n << '\n';
    ReguaPuzzle *reg = new ReguaPuzzle(n, regua);

    /*
        cout<<"DEBUG:"<<endl;
        reg->print();
    */

    if (reg->validade()) {
=======

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

          reg->getEstadoFinal()->print();
          Backtracking::run(reg, reg->getEstadoFinal());

          break;
        case 2:
          BuscaEmLargura::run(reg, reg->getEstadoFinal());
          cout << "Ainda Não implementado" << endl;
          break;
        case 3:
          BuscaEmProfundidade::run(reg, reg->getEstadoFinal());
          cout << "Ainda Não implementado" << endl;
          break;
        case 4:
          BuscaOrdenada::run(reg, reg->getEstadoFinal());
          cout << "Ainda Não implementado" << endl;
          break;
        case 5:
          BuscaGulosa::run(reg, reg->getEstadoFinal());
          cout << "Ainda Não implementado" << endl;
          break;
        case 6:
          AEstrela::run(reg, reg->getEstadoFinal());
          cout << "Ainda Não implementado" << endl;
          break;
        case 7:
          IDAEstrela::run(reg, reg->getEstadoFinal());
          cout << "Ainda Não implementado" << endl;
          break;
        default:
          cout << "Parametro invalido, favor escolher uma opção valida";
          break;
        }
      }

    } else {

      cout << "A regua não é valida, não é possivel rodar o programa";
    }
  }
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
  vector<char> regua;
  while (true) {
    cout << "\nFavor escolhe o tamanho N da regua:";
    cin >> n;

    if (n > 0) {
      break;
    } else {
      cout << "Favor escolher um numero valido!";
    }
  }

  bool espaco = false;
  cout << "\nPara montar a régua favor escolher P para peças pretas B para "
          "peças brancas e \'-\' para o espaço:";
  char aux = ' ';
  while (regua.size() != n) {

    if (regua.size() == n - 1 && !espaco) {
      regua.push_back('-');
      break;
    }

    cin >> aux;
    switch (aux) {
    case 'p':
      aux = toupper(aux);
      regua.push_back(aux);
      break;
    case 'P':
      regua.push_back(aux);
      break;
    case 'b':
      aux = toupper(aux);
      regua.push_back(aux);
      break;
    case 'B':
      regua.push_back(toupper(aux));
      break;
    case '-':
      if (!espaco) {
        regua.push_back(toupper(aux));
        espaco = true;
      } else {
        cout
            << "Só é possivel ter um buraco no jogo, favor selecionar uma peça";
      }
      break;
    default:

      cout << "Essa peça não é valida! Escolha outra";
      break;
    }
  }

  ReguaPuzzle *reg = new ReguaPuzzle(n, regua);

  cout << "A régua final é:";

  for (char &c : regua) {
    cout << c;
    cout << " ";
  }

  if (reg->validade()) {
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

  } else {
    cout << "A régua é invalida, entrando no modo jarro - Apenas para os "
            "desenvolvedores";

    menu1 = false;
    jarros = true;
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
      cout << "Backtracking" << endl;
      Backtracking::run(new Jarros(0, 0), new Jarros(5, 3));
      break;
    case 2:
      cout << "BUSCA EM LARGURA" << endl;
      BuscaEmProfundidade::run(new Jarros(0, 0), new Jarros(-1, 2));

      break;
    case 3:

      cout << "BUSCA EM PROFUNDIDADE" << endl;

      BuscaEmProfundidade::run(new Jarros(0, 0), new Jarros(2, -1));
      break;
    case 4:
      cout << "Busca Ordenada" << endl;
      BuscaOrdenada::run(new Jarros(0, 0, 0), new Jarros(0, 0, 0));
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
