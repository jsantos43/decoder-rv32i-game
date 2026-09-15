# Decoder RV32I Game

Bem-vindo ao **Decoder RV32I Game**! Este é um jogo educativo interativo em terminal focado no aprendizado e decodificação do conjunto de instruções RISC-V (Arquitetura RV32I). 

## 🎮 Sobre o Jogo

O jogo foi projetado para testar seus conhecimentos em arquitetura e organização de computadores, mais especificamente na codificação de instruções RISC-V. 

Seu funcionamento consiste em:
1. Ler o arquivo de código em Assembly (`riscv.asm`).
2. Utilizar as ferramentas do RISC-V para gerar o *dump* de instruções no formato legível.
3. Extrair uma instrução (mostrando, por exemplo, o mnemônico) e pedir ao jogador para identificar partes cruciais de como ela é codificada em linguagem de máquina (ex: qual é o seu `opcode`, formato de instrução, registradores envolvidos, etc).
4. O jogador responde às perguntas no terminal, com o objetivo de obter a maior pontuação possível (iniciando com 100 pontos e perdendo pontos para cada erro).

## 🛠️ Requisitos e Dependências

Para que o jogo possa ser compilado e executado corretamente, você precisará ter instalado em sua máquina:

1. **Compilador C++**: `g++` com suporte à versão C++17 (padrão em distribuições Linux atuais).
2. **Make**: ferramenta para automação de *build*.
3. **Toolchain RISC-V**: O jogo invoca diretamente no terminal os seguintes programas do ecossistema RISC-V GNU Toolchain para compilar e ler o Assembly em tempo de execução:
   - `riscv64-linux-gnu-as` (Assembler)
   - `riscv64-linux-gnu-ld` (Linker)
   - `riscv64-linux-gnu-objdump` (Gerador de Dump)

### Instalando dependências no Linux (Debian / Ubuntu / Mint)

Você pode instalar tudo o que é necessário através do terminal utilizando:

```bash
sudo apt update
sudo apt install build-essential g++ make binutils-riscv64-linux-gnu
```
> Nota: O pacote `binutils-riscv64-linux-gnu` contém todos os programas `riscv64-linux-gnu-*` invocados pelo jogo.

## 🚀 Como Executar

O projeto conta com um Makefile automatizado, dispensando que você precise usar comandos complexos de compilação.

1. Abra o terminal no diretório raiz deste projeto.
2. Compile o projeto através do comando:
   ```bash
   make
   ```
3. Execute o jogo usando:
   ```bash
   make run
   ```

*Nota: Caso queira limpar os arquivos executáveis gerados, basta usar o comando `make clean`.*

## 👨‍💻 Colaboradores

O desenvolvimento deste jogo foi possível graças aos seguintes autores:

- **João Pedro Tomaz dos Santos** - RA: 858031
- **Henrique Astafieff Costa** - RA: 858024
- **Nicolas Catini Ramalho dos Santos** - RA: 858044
- **Lucas de Melo Bonaccorsi** - RA: 858040
- **Guilherme do Prado Sampaio** - RA: 858045
