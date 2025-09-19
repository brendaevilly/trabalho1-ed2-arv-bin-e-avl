# Testes na AVL
## Testes de inserção com 50.000 nós
Foram feitas 30 inserções de 50000 mil nós para cada base de dados. 

- <font color="orange">Base de dados aleatória (entre 0 e 500000000)</font>

    | Média Segundos | Média Microssegundos |
    | -------------- | -------------------- |
    | 0.0000014001 | 1.401 |

- <font color="orange">Base de dados ordenada</font>

    | Média Segundos | Média Microssegundos |
    | -------------- | -------------------- |
    | 0.0000010443 | 1.046 |

- <font color="orange">Base de dados desordenada</font>

    | Média Segundos | Média Microssegundos |
    | -------------- | -------------------- |
    | 0.0000009184 | 0.918 |

## Testes de busca
Foram feitas 30 buscas para cada base de dados. 

- <font color="pink">Base de dados aleatória (entre 0 e 500000000) de 50.000 números</font>

    | Média Segundos | Média Microssegundos |
    | -------------- | -------------------- |
    | 0.0045040000 | 4504.00 |

- <font color="pink">Base de dados aleatória (entre 0 e 500000000) de 25.000 números</font>

    | Média Segundos | Média Microssegundos |
    | -------------- | -------------------- |
    | 0.0016610000 | 1661.00 |

- <font color="pink">Base de dados aleatória (entre 0 e 500000000) de 10.000 números</font>

    | Média Segundos | Média Microssegundos |
    | -------------- | -------------------- |
    | 0.0004660000 | 466.00 |