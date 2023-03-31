Uma possibilidade de busca exaustiva para o problema consiste em motar o roteiro para todas as atividades como sendo a primeira.

Ler N

Criar uma lista de atividades vazia
Criar uma lista de atividades vazia que servira como roteiro

Para i de 1 até N

    Ler <latitude da atividade> <longitude da atividade>

    Adicionar a atividade a lista de atividades

Cria uma variavel para guardar o melhor roteiro

Para cada atividade em atividades

    Escolhe a atividade como a primeira

    Para cada atividade em atividades que não foi escolhida

        Calcular a distância entra atividade escolhida e a atual

        Escolher a atividade com a menor distância com atividade escolhida

    Atualizar a atividade atual

    Repetir até não sobrarem atividades não escolhidas
