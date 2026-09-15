# ==========================================
# Configurações do Compilador
# ==========================================
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# ==========================================
# Arquivos e Alvos do Projeto
# ==========================================
TARGET = jogo
SRCS = main.cpp src/instruction.cpp src/manage_instructions.cpp

# Arquivos RISC-V (removidos durante o clean)
RISCV_OBJ = riscv.o
RISCV_ELF = riscv.elf
RISCV_DUMP = riscv.dump

# ==========================================
# Regras Principais
# ==========================================
.PHONY: all build run clean

# O alvo padrão que será executado apenas com o comando 'make'
all: build

# Compila o executável diretamente a partir dos fontes
build:
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Executa o projeto (garante que está compilado antes)
run: build
	./$(TARGET)

# ==========================================
# Limpeza
# ==========================================
clean:
	rm -f $(TARGET) $(RISCV_OBJ) $(RISCV_ELF) $(RISCV_DUMP)