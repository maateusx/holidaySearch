# 📅 Calculadora de Feriados e Fases Lunares (C)

Um utilitário robusto desenvolvido em **C** para o cálculo de calendários, abrangendo desde feriados fixos e móveis até a estimativa de fases lunares e verificação de anos bissextos.

## 🚀 Funcionalidades

* **Verificação de Ano Bissexto:** Identifica se o ano possui 365 ou 366 dias.
* **Cálculo da Páscoa:** Utiliza o algoritmo de *Meeus/Jones/Butcher* para determinar a data exata da Páscoa.
* **Feriados Móveis Automáticos:**
    * **Quarta-feira de Cinzas:** Calculada como 46 dias antes da Páscoa.
    * **Sexta-feira da Paixão:** Calculada como 2 dias antes da Páscoa.
* **Feriados Fixos:** Inclui Ano Novo (01/01), Natal (25/12) e feriados municipais (ex: São Bernardo do Campo).
* **Ciclo Lunar:** Algoritmo de aproximação astronômica para identificar dias de **Lua Cheia**.

## 🛠️ Funções Principais

| Função | Descrição |
| :--- | :--- |
| `isLeapYear` | Retorna `1` para anos bissextos e `0` para comuns. |
| `getEasterDay` | Implementa a matemática complexa para encontrar o Domingo de Páscoa. |
| `getMoonPhase` | Calcula a fase da lua (0-7) com base no ciclo sinódico médio (29.53 dias). |
| `getWeekDay` | Determina o dia da semana (Domingo a Sábado) para qualquer data. |
| `getYearHolidays` | Função mestre que gera o relatório completo do ano solicitado. |

## 💻 Como Compilar e Rodar

Para utilizar este código, você precisará de um compilador C (como o `gcc`).

1.  **Salve o arquivo** (ex: `main.c`).
2.  **Compile via terminal:**
    ```bash
    gcc -o gerenciador_datas main.c
    ```
3.  **Execute o programa:**
    ```bash
    ./gerenciador_datas
    ```

> **Nota:** Certifique-se de incluir a biblioteca `<stdio.h>` no topo do seu arquivo `.c` para o funcionamento da função `printf`.

## 📊 Exemplo de Saída

```text
Ano de 2024.
Ano bissexto, possui ao todo 366 dias.

-- Feriados --
> 1/1/2024 (Segunda-Feira): Ano Novo
> 14/2/2024 (Quarta-Feira): Quarta Feira de Cinzas
> 29/3/2024 (Sexta-Feira): Paixão de Cristo
> 31/3/2024 (Domingo): Pascoa
> 20/8/2024 (Terça-Feira): Aniversário da cidade São Bernardo do Campo
> 25/12/2024 (Quarta-Feira): Natal

-- Dias de Lua Cheia --
> 25/1/2024 (Quinta-Feira): Lua Cheia
...
