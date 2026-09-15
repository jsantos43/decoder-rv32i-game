start:
    # R-type: registradores
    add     x5, x1, x2         # R: rd=x5, rs1=x1, rs2=x2, funct3=000, funct7=0000000
    xor     x4, x2, x3         # R: rd=x4, rs1=x2, rs2=x3, funct3=100, funct7=0000000
    sub     x10, x5, x4        # R: rd=x10, rs1=x5, rs2=x4, funct3=000, funct7=0100000
    or      x11, x1, x2        # R: rd=x11, rs1=x1, rs2=x2, funct3=110, funct7=0000000
    and     x12, x3, x4        # R: rd=x12, rs1=x3, rs2=x4, funct3=111, funct7=0000000
    sll     x13, x5, x6        # R: rd=x13, rs1=x5, rs2=x6, funct3=001, funct7=0000000
    srl     x14, x7, x6        # R: rd=x14, rs1=x7, rs2=x6, funct3=101, funct7=0000000
    sra     x15, x7, x6        # R: rd=x15, rs1=x7, rs2=x6, funct3=101, funct7=0100000
    slt     x16, x1, x2        # R: rd=x16, rs1=x1, rs2=x2, funct3=010, funct7=0000000
    sltu    x17, x1, x2        # R: rd=x17, rs1=x1, rs2=x2, funct3=011, funct7=0000000

    # I-type (aritmético imediato)
    addi    x6, x5, 42         # I: rd=x6, rs1=x5, imm=42, funct3=000
    slli    x5, x6, 3          # I: rd=x5, rs1=x6, shamt=3, funct3=001
    ori     x18, x5, 15        # I: rd=x18, rs1=x5, imm=15, funct3=110
    andi    x19, x6, 255       # I: rd=x19, rs1=x6, imm=255, funct3=111
    xori    x20, x7, -1        # I: rd=x20, rs1=x7, imm=-1, funct3=100
    slti    x21, x5, 100       # I: rd=x21, rs1=x5, imm=100, funct3=010
    sltiu   x22, x5, 100       # I: rd=x22, rs1=x5, imm=100, funct3=011
    srli    x23, x6, 2         # I: rd=x23, rs1=x6, shamt=2, funct3=101
    srai    x24, x6, 2         # I: rd=x24, rs1=x6, shamt=2, funct3=101

    # I-type (load)
    lw      x7, 64(x6)         # I: rd=x7, rs1=x6, imm=64, funct3=010
    lbu     x5, 32(x4)         # I: rd=x5, rs1=x4, imm=32, funct3=100
    lh      x25, 8(x6)         # I: rd=x25, rs1=x6, imm=8, funct3=001
    lhu     x26, 8(x6)         # I: rd=x26, rs1=x6, imm=8, funct3=101
    lb      x27, 4(x4)         # I: rd=x27, rs1=x4, imm=4, funct3=000

    # I-type (jalr)
    jalr    x1, x6, 0          # I: rd=x1, rs1=x6, imm=0, funct3=000

    # S-type: store
    sw      x7, 16(x5)         # S: rs1=x5, rs2=x7, imm=16, funct3=010
    sb      x6, 16(x2)         # S: rs1=x2, rs2=x6, imm=16, funct3=001
    sh      x9, 20(x8)         # S: rs1=x8, rs2=x9, imm=20, funct3=001

    # B-type: branch condicional
    beq     x5, x6, label      # B: rs1=x5, rs2=x6, imm=offset(label), funct3=000
    bne     x3, x4, label      # B: rs1=x3, rs2=x4, imm=offset(label), funct3=001
    blt     x1, x2, label      # B: rs1=x1, rs2=x2, imm=offset(label), funct3=100
    bge     x2, x1, label      # B: rs1=x2, rs2=x1, imm=offset(label), funct3=101
    bltu    x3, x4, label      # B: rs1=x3, rs2=x4, imm=offset(label), funct3=110
    bgeu    x4, x3, label      # B: rs1=x4, rs2=x3, imm=offset(label), funct3=111

    # U-type: imediato alto
    lui     x8, 0xABCDE        # U: rd=x8, imm[31:12]=0xABCDE
    auipc   x28, 0x1000        # U: rd=x28, imm[31:12]=0x1000

    # J-type: salto
    jal     x1, end            # J: rd=x1 (ra), imm=offset(end)

    # Sistema
    ecall                      # I: chamada de sistema
    ebreak                     # I: breakpoint

label:
    addi    x9, x0, 7          # I: instrução após branch
end:
    nop                        # I-type: addi x0,x0,0
