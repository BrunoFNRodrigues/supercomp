import sys
import os
import subprocess

# Define o caminho para o arquivo executável
heuristica = "./../heuristicas/maratona_"+sys.argv[1]

# Adiciona o nome das colunas ao arquivo de resposta
with open("./../resultados/"+sys.argv[1]+".csv", "w") as f:
    f.write("n_filmes,n_categorias,t_restante,t_execucao,n_filmes,\n")
    
    
for j in range(1000, (len(os.listdir("./../inputs"))*10)-1, 1000):
    # Executa o arquivo várias vezes uma vez para cada quantidade de categorias
    for i in range(1, 101):
        # Define os inputs que você deseja passar para o arquivo
        inputs = open("./../inputs/input_"+str(j)+"_"+str(i)+".txt")
        
        r = subprocess.Popen([heuristica], stdin = inputs)
        r.wait()
