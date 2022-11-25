import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import seaborn as sns

def createLine(cor, label, metodo, dataframe, ax):
    ticks = [0.000001, 0.0001, 0.01, 0.1]
    x = list(range(len(ticks)))
    y = dataframe.loc[dataframe['metodo'] == metodo].sort_values(by = ['epsilon'])
    y = y['iteracoes']
    ax.plot(x, y, marker = 'o', color = cor, label = label)

def plotIteracoes():
    fig, ax = plt.subplots(figsize = (10,8))
    dataframe = pd.read_csv("./graficosMN/metodos.csv")
    dataframe = dataframe[['epsilon', 'iteracoes', 'metodo']]
    ticks = [0.000001, 0.0001, 0.01, 0.1] # Poderia fazer isso dinamicamente mas como é fixo vou manter
    x = list(range(len(ticks)))
    metodos = ('GaussSeidelInverso', 'GaussSeidelNormal', 'GaussJacobiInverso', 'GaussJacobiNormal')
    nomes = ("Gauss Seidel por Inversa", "Gauss Seidel", "Gauss Jacobi por Inversa", "Gauss Jacobi")
    cores = ("r", "b", "g", "k")
    for i in range(len(metodos)):
        createLine(cores[i], nomes[i], metodos[i], dataframe, ax)
    ax.set_xlabel('Epsilon')
    ax.set_ylabel('Número de Iterações')
    ax.set_title('Número de Iterações para os Diferentes Métodos')
    ax.set_xticks(x, ticks)
    ax.legend()
    ax.grid(which='both', color='grey', linewidth=1, linestyle='-', alpha=0.2)
    plt.show()




plotIteracoes()
#cheguei num resultado próximo ao desejado.