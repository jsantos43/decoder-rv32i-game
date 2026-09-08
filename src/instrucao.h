#ifndef INSTRUCAO_H
#define INSTRUCAO_H

#include <string>
#include <vector>

// std::vector<std::string> abiNames = {
//   "zero","ra","sp","gp","tp","t0","t1","t2",
//   "s0","s1","a0","a1","a2","a3","a4","a5",
//   "a6","a7","s2","s3","s4","s5","s6","s7",
//   "s8","s9","s10","s11","t3","t4","t5","t6"
// };

class instrucao {
  private:
    std::string opcode;
    std::string funct7;
    std::string rs2;
    std::string rs1;
    std::string funct3;
    std::string rd;
  public:
    instrucao(std::string);
    std::string get_mnemonico();
    std::string get_opcode();
};

#endif