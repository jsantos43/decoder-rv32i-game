#include "manage_instructions.h"

std::regex instruction_line(R"(^\s*[0-9a-fA-F]+:\s+([0-9a-fA-F]{8})\s+(.+)$)");

bool generate_riscv_dump() {
    int ret;

    // 1. Assembler: compila riscv.asm em objeto RV32I
    ret = std::system("riscv64-linux-gnu-as -march=rv32i -mabi=ilp32 -o riscv.o riscv.asm");
    if (ret != 0) {
        std::cerr << "Erro no assembler!\n";
        return false;
    }

    // 2. Linker: gera executável bare-metal simples (ELF32)
    ret = std::system("riscv64-linux-gnu-ld -m elf32lriscv -Ttext=0x0 -o riscv.elf riscv.o");
    if (ret != 0) {
        std::cerr << "Erro no linker!\n";
        return false;
    }

    // 3. Dump: gera instruções em formato legível
    ret = std::system("riscv64-linux-gnu-objdump -d riscv.elf > riscv.dump");
    if (ret != 0) {
        std::cerr << "Erro no objdump!\n";
        return false;
    }

    return true;
}


std::string get_info_from_dump_line(std::string line) {
    std::smatch match;
    if (std::regex_match(line, match, instruction_line)) {
        std::string hex = match[1].str();
        std::string resto = match[2].str();

        // Remove comentario de destino de branch/jump, ex: " # 20 <_start+0x20>"
        size_t posComentario = resto.find('#');
        if (posComentario != std::string::npos) {
            resto = resto.substr(0, posComentario);
        }

        // Troca tabs por espaco e remove espacos extras nas pontas
        for (char& c : resto) {
            if (c == '\t') c = ' ';
        }
        size_t inicio = resto.find_first_not_of(' ');
        size_t fim = resto.find_last_not_of(' ');
        std::string assembly = (inicio == std::string::npos)
            ? ""
            : resto.substr(inicio, fim - inicio + 1);

        // Converte hex (32 bits) para binario usando bitset
        uint32_t valor = static_cast<uint32_t>(std::stoul(hex, nullptr, 16));
        std::string binario = std::bitset<32>(valor).to_string();

        // Monta a linha final: hex-binario-assembly
        std::string entrada = hex + "-" + binario + "-" + assembly;

        return entrada;
    }

    return " ";
}



std::vector<std::string> get_instructions(){
    std::vector<std::string> instrucoes;

    bool dump_gerado = generate_riscv_dump();

    if (dump_gerado) {
        std::ifstream arquivo("riscv.dump");

        std::string line;
        while (std::getline(arquivo, line)) {
            std::string entrada = get_info_from_dump_line(line);
            
            if (entrada != " ") {
                instrucoes.push_back(entrada);
            }
        }
    }

    // Adicionar uma instrução genérica se tiver vazia
    if (instrucoes.empty()) {
        std::cout << "Erro ao ler dump, usando instrução genérica!" << std::endl;
        instrucoes.push_back("");
    }


    return instrucoes;
}

// Embaralha o vetor de instruções uma única vez (in-place)
void shuffle_instructions(std::vector<std::string>& instructions) {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::shuffle(instructions.begin(), instructions.end(), gen);
}

// Retira e retorna a próxima instrução do vetor já embaralhado
// (recebe por referência para "consumir" as instruções entre chamadas)
std::string pick_instructions(std::vector<std::string>& instructions) {
    if (instructions.empty()) {
        return "";
    }

    std::string instrucao = instructions.back();
    instructions.pop_back();

    return instrucao;
}