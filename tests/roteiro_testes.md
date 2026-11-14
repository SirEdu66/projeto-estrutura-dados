# Roteiro de Testes — Sistema de Equipamentos de Rede

| # | Cenário | Entrada | Resultado Esperado | Resultado Obtido |
|---|---------|---------|--------------------|------------------|
| 1 | Cadastro válido | ID `50`, Nome `Roteador Core`, Tipo `Roteador`, Local `Rack Principal` | Mensagem `Equipamento cadastrado com sucesso.` e registro no histórico. | *(preencher após rodar)* |
| 2 | ID duplicado | Tentar cadastrar novamente ID `50` | Mensagem `ID ja cadastrado.` sem alterar árvore ou histórico[cite: 1]. | *(preencher após rodar)* |
| 3 | Entradas inválidas | Opção `abc`, ID `0`, ID `-5`, ID `12a`, Nome com espaços | Mensagem `Entrada invalida.` sem travar o loop[cite: 1]. | *(preencher após rodar)* |
| 4 | Listagem em-ordem (BST) | Inserir `50, 30, 70, 20, 40, 60, 80` e escolher opção `4` | Exibição em ordem crescente: `20, 30, 40, 50, 60, 70, 80`[cite: 1]. | *(preencher após rodar)* |
| 5 | Menor e maior ID | Escolher opção `6` | Menor ID = `20` e Maior ID = `80`[cite: 1]. | *(preencher após rodar)* |
| 6 | Ordenação por nome | Escolher opção `5` (com dois equipamentos chamados `Switch B` de IDs `30` e `40`) | Ordem alfabética; no empate de `Switch B`, ID `30` antes do `40`; opção `4` continua ordenada por ID[cite: 1]. | *(preencher após rodar)* |
| 7 | Percurso por níveis (Fila + Lista) | Escolher opção `8` na árvore completa | Saída: `50 -> 30 -> 70 -> 20 -> 40 -> 60 -> 80`[cite: 1]. | *(preencher após rodar)* |
| 8 | Remoção — 3 casos + inexistente | Remover `20` (folha), `30` (1 filho), `50` (2 filhos) e `99` (inexistente) | `20`, `30` e `50` removidos mantendo BST válida (raiz vira `60`); `99` exibe `ID nao encontrado.`[cite: 1]. | *(preencher após rodar)* |
| 9 | Histórico (Pilha) | Escolher opção `7` | Exibe operações bem-sucedidas da mais recente para a mais antiga[cite: 1]. | *(preencher após rodar)* |
| 10 | Memória (Valgrind) | `make valgrind` ou `valgrind --leak-check=full ./sistema_redes < tests/entrada_bst.txt` | `0 errors from 0 contexts` e `All heap blocks were freed`[cite: 1]. | *(preencher após rodar)* |
