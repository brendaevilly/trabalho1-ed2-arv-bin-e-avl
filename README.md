# **Trabalho 01 da disciplina de Estruturas de Dados II**
## Estruturas implementadas:
- Árvore Binária de Busca;
- Árvore AVL;
- Lista Circular;
- Lista Duplamente Encadeada Simples.

```
├─ AVL/
|  └─ funcoes.c
|  └─ prototipos.c
|  └─ main.c
|  └─ mainTeste.c
|  └─ mainTeste2.c
|  └─ resultados.md
├─ BST/
|  └─ funcoes.c
|  └─ prototipos.c
|  └─ main.c
|  └─ mainTeste.c
|  └─ mainTeste2.c
|  └─ resultados.md
├─ DbsParaTestes/
|  └─ dbAleatoria.txt
|  └─ dbDesordenada.txt
|  └─ dbOrdenada.txt
└─ README.md
```

## **Como rodar o programa com o compilador GCC**
### Para rodar o programa de BST no linux:
- **Comando 1**: gcc BST/main.c BST/funcoes.c -o programa
- **Comando 2**: ./programa

### Para rodar o programa de AVL no linux:
- **Comando 1**: gcc AVL/main.c AVL/funcoes.c -o programa
- **Comando 2**: ./programa