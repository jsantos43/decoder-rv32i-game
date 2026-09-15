#include "instruction.h"

Instruction::Instruction(std::string line) {
  size_t pos1 = line.find('-');
  size_t pos2 = line.find('-', pos1 + 1);

  hex = line.substr(0, pos1);
  bin = line.substr(pos1 + 1, pos2 - pos1 - 1);
  assembly = line.substr(pos2 + 1);

  opcode = bin.substr(25, 7); // Últimos 7 caracteres;
  funct7 = bin.substr(0, 7);   // bits 31..25 → primeiros 7 caracteres
  rs2    = bin.substr(7, 5);   // bits 24..20
  rs1    = bin.substr(12, 5);  // bits 19..15
  funct3 = bin.substr(17, 3);  // bits 14..12
  rd     = bin.substr(20, 5);  // bits 11..7

  // Classificar tipo de instrução baseado no opcode
  if (opcode == "0110111" || opcode == "0010111") {
    type = 'U';
  } else if (opcode == "1101111") {
    type = 'J';
  } else if (opcode == "1100111" || opcode == "0000011" || opcode == "0010011" ||
           opcode == "0001111" || opcode == "1110011") {
    type = 'I';
  } else if (opcode == "1100011") {
    type = 'B';
  } else if (opcode == "0100011") {
    type = 'S';
  } else if (opcode == "0110011") {
    type = 'R';
  } else {
    type = ' ';
  }
}

bool Instruction::ask(std::string question, std::string answer_key) {
  std::cout << std::endl << std::endl;
  std::cout << "-> " << this->get_assembly() << std::endl << std::endl;

  std::string answer;

  std::cout << "Tentativas: [2/2]" << std::endl;
  std::cout << question;
  std::cin >> answer;

  if (answer == answer_key) return true;

  std::cout << std::endl;
  std::cout << "Tentativas: [1/2]" << std::endl;
  std::cout << question;
  std::cin >> answer;

  if (answer == answer_key) return true;

  return false;
}

std::string Instruction::get_opcode() {
  return opcode;
}

std::string Instruction::get_bin() {
  return bin;
}

std::string Instruction::get_assembly() {
  return assembly;
}

std::string Instruction::get_imm_I() {
    return bin.substr(0, 12);
}

std::string Instruction::get_imm_S() {
    return bin.substr(0, 7) + bin.substr(20, 5);
}

std::string Instruction::get_imm_B() {
    return std::string(1, bin[0]) + std::string(1, bin[24]) + bin.substr(1, 6) + bin.substr(20, 4);
}

std::string Instruction::get_imm_U() {
    return bin.substr(0, 20);
}

std::string Instruction::get_imm_J() {
    return std::string(1, bin[0]) + bin.substr(12, 8) + std::string(1, bin[11]) + bin.substr(1, 10);
}

int Instruction::play() {
    int erros = 0;
    std::cout << "\n==========================================" << std::endl;
    std::cout << "Instrução: " << assembly << " (Tipo " << type << ")" << std::endl;
    std::cout << "==========================================" << std::endl;

    if (!ask("Digite o OPCODE (7 bits): ", opcode)) erros++;

    switch (type) {
        case 'R':
            if (!ask("Digite o rd (5 bits): ", rd)) erros++;
            if (!ask("Digite o funct3 (3 bits): ", funct3)) erros++;
            if (!ask("Digite o rs1 (5 bits): ", rs1)) erros++;
            if (!ask("Digite o rs2 (5 bits): ", rs2)) erros++;
            if (!ask("Digite o funct7 (7 bits): ", funct7)) erros++;
            break;

        case 'I':
            if (!ask("Digite o rd (5 bits): ", rd)) erros++;
            if (!ask("Digite o funct3 (3 bits): ", funct3)) erros++;
            if (!ask("Digite o rs1 (5 bits): ", rs1)) erros++;
            if (!ask("Digite o Immediate (12 bits): ", get_imm_I())) erros++;
            break;

        case 'S':
            if (!ask("Digite o funct3 (3 bits): ", funct3)) erros++;
            if (!ask("Digite o rs1 (5 bits): ", rs1)) erros++;
            if (!ask("Digite o rs2 (5 bits): ", rs2)) erros++;
            if (!ask("Digite o Immediate codificado (12 bits): ", get_imm_S())) erros++;
            break;

        case 'B':
            if (!ask("Digite o funct3 (3 bits): ", funct3)) erros++;
            if (!ask("Digite o rs1 (5 bits): ", rs1)) erros++;
            if (!ask("Digite o rs2 (5 bits): ", rs2)) erros++;
            if (!ask("Digite o Immediate codificado (12 bits): ", get_imm_B())) erros++;
            break;

        case 'U':
            if (!ask("Digite o rd (5 bits): ", rd)) erros++;
            if (!ask("Digite o Immediate (20 bits): ", get_imm_U())) erros++;
            break;

        case 'J':
            if (!ask("Digite o rd (5 bits): ", rd)) erros++;
            if (!ask("Digite o Immediate codificado (20 bits): ", get_imm_J())) erros++;
            break;

        default:
            std::cout << "Tipo não reconhecido." << std::endl;
            break;
    }

    return erros;
}