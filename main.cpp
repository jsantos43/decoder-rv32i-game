#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include "src/instruction.h"
#include "src/manage_instructions.h"

using namespace std;

int main(void) {
  // Mostrar o Header
  cout << "===============================" << endl;
  cout << "      Decoder RV32I GAME       " << endl;
  cout << "===============================" << endl << endl;

  // Pegar um vetor de instruções
  vector<string> linhas_de_instrucoes = get_instructions();
  shuffle_instructions(linhas_de_instrucoes);

  int pontos {100};
  int rodadas {5};

  while (rodadas > 0 && !linhas_de_instrucoes.empty() && pontos > 0) {
    // Escolher uma linha das instruções do vetor
    string linha_escolhida = pick_instructions(linhas_de_instrucoes);

    if (linha_escolhida.empty() || linha_escolhida == " ") continue;

    // Cria um objeto do tipo instrução passando a linha escolhida
    Instruction instrucao(linha_escolhida);

    int erros = instrucao.play();

    pontos -= (erros * 15);

    if (pontos < 0) pontos = 0;
    cout << "Pontuação atual: " << pontos << " pontos\n";
    
    rodadas--;
  }

  // Fim do jogo
  cout << "\n=======================================" << endl;
  cout << "  FIM DE JOGO! Pontuação Final: " << pontos << endl;
  cout << "=======================================" << endl;

  return 0;
}