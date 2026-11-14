Sistema de Equipamentos de Rede (Estrutura de Dados)

Projeto Prático Individual — Estrutura de Dados, FATEC Ribeirão Preto (ADS, 3º semestre). Docente: Prof. Me. Heber Castro. Aluno: Eduardo Ferreira Silva. Tema escolhido: A — Redes (equipamentos de rede).

Descrição

Aplicação de terminal em C para cadastrar e consultar equipamentos de uma rede (roteadores, switches, firewalls, servidores etc.). Cada equipamento tem ID (inteiro positivo e único), nome, tipo e localização. Os registros ficam organizados em uma árvore binária de busca (BST) indexada pelo ID, e o sistema mantém um histórico das últimas alterações, ordena os registros por nome e percorre a árvore por níveis. Todas as entradas do teclado dão certo.

Funcionalidades (menu)
Opção	Função
1	Cadastrar equipamento (valida os campos e rejeita ID duplicado)
2	Buscar equipamento pelo ID (BST)
3	Remover equipamento (folha, um filho ou dois filhos)
4	Listar equipamentos em ordem crescente de ID (em-ordem)
5	Ordenar e exibir por nome (vetor auxiliar, BST não é alterada)
6	Consultar menor e maior ID
7	Consultar histórico (últimas 5 ações, da mais recente para a mais antiga)
8	Percurso por níveis (fila + lista encadeada) — extra
0	Encerrar (libera toda a memória)
Estruturas utilizadas
BST indexada pelo ID do equipamento (bst.h / bst.c)
Lista encadeada com inserção no fim, usada para guardar a ordem do percurso por níveis (lista.h / lista.c)
Pilha dinâmica encadeada para o histórico de cadastros e remoções concluídos com sucesso (pilha.h / pilha.c)
Fila usada no percurso por níveis da BST (fila.h / fila.c)
Ordenação própria: Insertion Sort sobre um vetor auxiliar de cópias, comparando o nome com strcmp() e desempatando pelo ID crescente (ordenacao.h / ordenacao.c)
Leitura segura de entradas com fgets e strtol (entrada.h / entrada.c)
Como compilar

Requisitos: gcc e make.

make

Sem make, compile manualmente:

gcc -Wall -Wextra -std=c99 -Iinclude src/*.c -o sistema_redes
Como executar
./sistema_redes

No Windows (PowerShell): ./sistema_redes.exe

Como rodar os testes

Os roteiros ficam na pasta tests/:

tests/roteiro_testes.md: cenários, entrada, resultado esperado e resultado obtido.
tests/entrada_bst.txt: cadastros, listagem, menor/maior, ordenação, percurso por níveis, remoções e histórico.
tests/entrada_validacao.txt: entradas inválidas (opção inválida, ID zero, negativo ou com letras, texto vazio, ID duplicado, ID inexistente).
tests/saida_*.txt: saídas obtidas na execução, usadas como evidência.

Para reproduzir (cada linha do arquivo é o que seria digitado):

./sistema_redes < tests/entrada_bst.txt
./sistema_redes < tests/entrada_validacao.txt

No PowerShell:

Get-Content tests/entrada_bst.txt | ./sistema_redes.exe
Get-Content tests/entrada_validacao.txt | ./sistema_redes.exe

Verificação de memória

Em sistemas com valgrind instalado:

make valgrind
Estrutura do repositório
include/   interfaces (.h)
src/       implementações (.c)
tests/     roteiros, entradas e saídas de teste
docs/      relatório técnico (PDF)
Makefile
README.md
.gitignore
