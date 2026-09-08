#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include "instrucao.h"

using namespace std;

int main(void) {
  cout << "==========================" << endl;
  cout << "       Decoder RV32I      " << endl;
  cout << "==========================";
  cout << endl << endl;

  // Ler instrução do riscv.txt
  ifstream archive("riscv.txt");

  // Verificar senão deu falha ao abrir o arquivo
  if(!archive.is_open()) {
    cout << "Erro: Falha ao abrir o riscv.txt" << endl;
  }

  vector <string> instructions;
  string line;

  // Ler linha a linha do arquivo
  while(getline(archive, line)) {
    instructions.push_back(line);
  }

  archive.close();

  // Escolher primeria instrução
  instrucao my_inst(instructions.at(0)); // Aleatorizar depois

  // bitset<32> bits(choosen_instruction);

  cout << "Instrução: " << my_inst.get_mnemonico() << endl;
  cout << "Meu opcode é: " << my_inst.get_opcode() << endl; // teste

  // Imprimir instrução


  // Pedir entrada do opcode

  // Ler entrada

  // Verificar se acertou

  //Passar para os próximos passos
  return 0;
}