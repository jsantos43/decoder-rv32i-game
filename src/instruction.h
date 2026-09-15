#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <string>
#include <vector>

class Instruction {
  private:
    std::string hex;
    std::string bin;
    std::string assembly;

    std::string opcode;
    char type;

    std::string funct7;
    std::string rs2;
    std::string rs1;
    std::string funct3;
    std::string rd;

    std::string get_imm_I();
    std::string get_imm_S();
    std::string get_imm_B();
    std::string get_imm_U();
    std::string get_imm_J();
    
  public:
    Instruction(std::string);
    std::string get_opcode();
    std::string get_bin();
    std::string get_assembly();
    bool ask(std::string, std::string);
    int play();
};

#endif