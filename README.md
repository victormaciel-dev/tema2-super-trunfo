# Tema 2 — Super Trunfo (Cadastro de Cartas) em C

Este repositório contém a solução do **Tema 2 — Super Trunfo**, desenvolvida em **linguagem C**, com foco em **entrada/saída**, **variáveis**, **operadores matemáticos**, **operadores relacionais** e **tipos de dados**.

> ✅ Observação: o objetivo é **cadastrar e exibir cartas** com cálculos derivados, conforme o enunciado.  
> Não se trata de um jogo completo com todas as regras de disputa.

---

## 🎯 Objetivos do desafio

- Criar um programa em C para **cadastrar cartas** do Super Trunfo de Países/Cidades.
- Permitir a **entrada e exibição** de informações básicas:
  - Estado
  - Código
  - Nome da cidade
  - População
  - PIB
  - Área
  - Pontos turísticos
- Calcular propriedades derivadas:
  - **Densidade populacional** = população / área
  - **PIB per capita** = PIB / população
- Aplicar:
  - Operadores matemáticos (`+ - * /`)
  - Operadores relacionais (`> < == >= <=`)
  - Tipos adequados (`long long`, `double`, `int`)

---

## 🧩 Como a solução foi organizada

Arquivo principal:

- `super_trunfo.c`

Estrutura:

- `struct Carta` para organizar os dados de cada carta
- Funções:
  - `cadastrarCarta()` → lê os dados da carta via teclado e calcula derivados
  - `exibirCarta()` → imprime todas as informações
  - `compararCartas()` → demonstra operadores relacionais comparando atributos

---

## ▶️ Como executar

### Compilar e executar (Linux/Mac/Windows com GCC)
```bash
gcc super_trunfo.c -o super_trunfo
./super_trunfo

📌 Autor

Projeto acadêmico — ADS.
