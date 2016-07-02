# Inteligência de Enxames - Entrega 4

Entrega número 4 da cadeira de inteligência de enxames.

## Descrição

### Alunos
Geraldo e Iago

### Professor
Carmelo

### Tema
Alocação de doentes em um quarto.

#### Atributos

- Cada cama equivale a 1 indivíduo;
- Um indivíduo representa uma posição x e y no espaço de busca;
- Cada indivíduo terá sua respectiva doença;
- De acordo com a doença existirá uma área de contágio (raio);
- O fitness será:
  - |∑√(( xi− xk)²+ ( yi−xk)²) - (Ri+Rk)| onde k são todos os outros indivíduos, xi−xk ≠ 0 e yi−ik ≠ 0;
  - Desta forma, o fitness será:
    - 0 (zero) sempre que a distância estiver no limite das áreas de contágio;
    - Maior que 0 (zero) se a distância diferir da soma dos raios.
  - Ainda estamos considerando como colocar o valor da quantidade de camas para inflluenciar no fitness visto que queremos maximizar este valor.

#### Descrição do problema

* O objetivo é inserir o máximo de camas possíveis em um quarto de tal forma que não exista possibilidade de contágio (Problema de Maximização);
* Cada ciclo será testado o arranjo de indivíduos;
* Se em determinado ciclo for observado a possibilidade de melhorar, um indivíduo é adicionado;
* Critério de parada será quando o algoritmo não conseguir melhorar em **x** iterações.

#### Possíveis Algoritmos de Enxames

- *Particle Swarm Optimization* (PSO) e *Artificial Bee Colony* (ABC).

#### Linguagem escolhida

- Java para o algoritmo.
- ActionScript 3 caso o tempo permita criar uma animação.

#### Atividades

- Realizar pesquisa com âmbito literário para se adequar ao problema;
- Criar base de dados;
- Criar base de dados de referência:
  - Iguais áreas de contágio para ser possível de calcular manualmente. Ex.: Quarto de 20x20 m e áreas de raio de 2m (ou 4m de diâmetro) o que resulta em 25 camas no melhor caso.
- Adequar o algoritmo às especificações do problema;
- Desenvolver relatório;
- Desenvolver interface gráfica para melhorar visualização do problema;
- Desenvolver apresentação.

No caso de sobra de tempo, adicionar animação das iterações mostrando as posições das camas de acordo com as iterações.

#### Cronograma

| 1ª Semana         | 2ª Semana   | 3ª Semana   | 4ª Semana |
| :---------------: |:-----------:| :----------:| :-------: |
| Definir Modelagem | Implementar | Implementar | Desenvolver relatório formato IEEE |
| Pesquisa          | Criar base de dados | Testar | Desenvolver Apresentação |
| Acertar detalhes de Modelagem / Implementação | Testar | Mapear resultados preliminares | Apresentar resultados (30/6) |

![Projeto] (camas.jpg "Referência")


#### Base de dados

1 de cada doença + (100-doenças) <<<< random!!!!

id, nome, tipo (distância) <<<< N linhas

#### AS3

(x,y,r), (x,y,r), (x,y,r), (x,y,r), (x,y,r), (x,y,r)

(x,y,r), (x,y,r), (x,y,r), (x,y,r), (x,y,r), (x,y,r)

(x,y,r), (x,y,r), (x,y,r), (x,y,r), (x,y,r), (x,y,r)

(x,y,r), (x,y,r), (x,y,r), (x,y,r), (x,y,r), (x,y,r), (x,y,r), (x,y,r)

### FÓRMULA

/\ D ~ 1/F \/

Onde:

* D é a distância Euclidiana
* F é o fitness

D aumenta, F diminui (inversamente proporcional)

### Validação

* Somente caso de gotícula (1m).
* Ambos os casos.
