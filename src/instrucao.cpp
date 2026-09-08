#include "instrucao.h"

instrucao::instrucao(std::string inst) {
  opcode = inst.substr(25, 7); // Últimos 7 caracteres;
  funct7 = inst.substr(0, 7);   // bits 31..25 → primeiros 7 caracteres
  rs2    = inst.substr(7, 5);   // bits 24..20
  rs1    = inst.substr(12, 5);  // bits 19..15
  funct3 = inst.substr(17, 3);  // bits 14..12
  rd     = inst.substr(20, 5);  // bits 11..7
}

std::string instrucao::get_mnemonico() {
  if (opcode == "0110011") {
    if (funct3 == "000") return "add";
    if (funct3 == "100") return "xor";
  } 
  
  if (opcode == "0010011") {
    if (funct3 == "000") return "addi"; 
    if (funct3 == "001") return "slli"; 
  } 
  
  if (opcode == "0000011") {
    if (funct3 == "010") return "lw";
    if (funct3 == "100") return "lbu";
  } 
  
  if (opcode == "0100011") {
    if (funct3 == "010") return "sw";
    if (funct3 == "001") return "sb";
  } 
  
  if (opcode == "1100011") {
    if (funct3 == "000") return "beq";
    if (funct3 == "001") return "bne";
  } 
  
  if (opcode == "0110111") {
    return "lui";
  } 
  
  if (opcode == "1101111") {
    return "jal";
  }

  return "NFN"; // Caso mnemonico não foi localizado
}

std::string instrucao::get_opcode() {
  return opcode;
}