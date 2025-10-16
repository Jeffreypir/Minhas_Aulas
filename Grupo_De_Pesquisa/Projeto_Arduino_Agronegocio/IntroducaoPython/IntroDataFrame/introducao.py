
# Importando bibliotecas 

import pandas as pd
import numpy as np 
import matplotlib.pyplot as plt 


# Criando o Data Frame 

dados = pd.DataFrame({
    "Nome":["Ana", "João", "Maria", "Pedro"],
    "Idade":[23,35,29,40],
    "Nota":[8.5, 7.0, 9.2, 6.8]
    })

# Imprimindo dados na tela do monitor 
print ("Tabela de dados criada:", "\n", dados, "\n")


# Salvando em um arquivo CSV 
dados.to_csv("alunos.csv", index=False, encoding="utf-8")

#Lendo dados do arquivo criado

df = pd.read_csv("alunos.csv")
print ("Tabela de dados do arquivo alunos:", "\n", df)






