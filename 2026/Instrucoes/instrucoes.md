# Instruções para Geração de Aulas - Copilot CLI

## Objetivo
Gerar automaticamente arquivos LaTeX para aulas de matemática seguindo um padrão estrutural consistente, baseado no template fornecido.

## Template Base
O template LaTeX a ser utilizado está definido no arquivo anexo. Todas as aulas geradas devem seguir EXATAMENTE a mesma estrutura:
- Cabeçalho com pacotes e configurações
- Layout em duas colunas (multicols)
- Títulos coloridos (azul para section, vermelho para subsection)
- Caixas destacadas para fórmulas (usando tikz)
- Seções organizadas: Conceitos Básicos → Tópicos Específicos → Comparações (opcional) → Exercícios

## Regras de Geração

### 1. Estrutura de Pastas
Para cada aula gerada, criar a seguinte hierarquia de diretórios:

└── [Assunto_da_aula]/
└── aula_assunto.tex
└── [Gabarito_comentado_assunto_da_aula]/
└── gabarito_assunto.tex


### 2. Localização do modelo latex
#### 2.1 Modelo da aula 
$HOME/Documentos/EREFEM_MJK/2026/ModeloAula/modelo.tex

#### 2.2 Modelo do gabarito
$HOME/Documentos/EREFEM_MJK/2026/ModeloAula/gabarito.tex

### 3. Parametros de entrada:

ASSUNTO: Função do Segundo Grau
TRIMESTRE: Primeiro Trimestre
PROFESSOR: Jefferson


### 4. Estrutura do arquivo gabarito_assunto
#### 4.1 Mesma do modelo utilizado com as questões resolvidas e comentadas no formato de questão e resposta.
#### 4.2 Questões resolvidas de forma didática de forma que o estundante entenda o conceito.
#### 4.3 Uso de cores quando for necessário para o entendimento na resolução.
#### 4.4 Deixar de forma elegante a matemática em latex

### 5. Quantidade de questões 
Os arquivos gerados devem possuir 30 questões ao todo 
