# Simple Assembler
Montador (assembler) para o processador myCPU, uma CPU RISC simples e baseada no MIPS. O código de saída é um arquivo binário que representa o mapa de memória que será utilizado em um simulador da CPU.

## Especificações

As instruções aceitas pelo myCPU são divididas em três tipos: R, I e J. Por padrão, o Simple Assembler aceita as seguintes instruções:

| Instrução |Tipo| Opcode | Funct  |
|-----------|----|--------|--------|
|   add     |  R |        | 100000 |
|   addi    |  I | 100000 |        |
|   sub     |  R |        | 100000 |
|   and     |  R |        | 100100 |
|   xor     |  R |        | 100110 |
|   or      |  R |        | 100101 |
|   beq     |  I | 000100 |        |
|   bne     |  I | 000101 |        |
|   j       |  J | 100000 |        |
|   jal     |  J | 000011 |        |
|   slt     |  R |        | 101010 |
|   lw      |  I | 100011 |        |
|   sw      |  I | 101011 |        |
|   jr      |  R |        | 001000 |

O número de instruções aceitas é flexível, ou seja, podem ser adicionadas ou removidas instruções quando desejado, de acordo com o seguinte padrão:

__As instruções estão no arquivo funcoes.txt, divididas como segue:__

>1 [instrução R]:[funct],

>2 [instrução I]:[opcode],

>3 [instrução J]:[opcode],

Onde 1, 2 e 3 indicam as linhas do arquivo.

## Rodando a aplicação
```bash
# Clonando o repositório
$ git clone https://github.com/Daniel-Alencar/simple-assembler
```

```bash
# Acesse a pasta do projeto no terminal/cmd
$ cd simple-assembler
```

```bash
# Compilando o arquivo
$ gcc assembler.c -o assembler
```

Será gerado um arquivo assembler.exe (windows) e um arquivo assembler.out (no Linux).

```bash
# Execute da seguinte forma
# linux
$ ./assembler [arquivo_de_entrada.asm] [nome_do_arquivo_de_saída](opcional)

# windows
$ assembler [arquivo_de_entrada.asm] [nome_do_arquivo_de_saída](opcional)
```

Isto gerará um nome_do_arquivo_de_saída.dat com a sequência em binário das instruções (usando a estratégia little-endian) do arquivo de entrada que foi passado.