## Questão 2

    Não, a estratégia gulosa não garante uma solução ótima para todos os problemas. A estratégia gulosa é uma heurística que faz escolhas locais ótimas em cada etapa da solução, ou seja, escolhe a opção que parece ser a melhor no momento, sem considerar o impacto a longo prazo. Embora essa estratégia possa levar a uma solução razoavelmente boa em muitos casos, ela não garante a solução ótima em todos os casos.

    Uma desvantagem da estratégia gulosa é que ela pode ficar presa em um ótimo local, sem conseguir encontrar a solução global ótima. Além disso, em alguns problemas, a escolha local ótima em cada etapa pode levar a uma solução global que é pior do que uma solução que requer uma escolha subótima em uma ou mais etapas.

## Questão 3

Inicialize a solução com k centros de distribuição escolhidos aleatoriamente entre as n cidades.

Repita até que não haja mais melhora na solução:

    Para cada centro de distribuição:

        Para cada cidade que não é centro de distribuição:

            Calcule a distância entre a cidade e o centro de distribuição mais próximo.

            Selecione a cidade com a maior distância calculada no passo 5 e a adicione como novo centro de distribuição.

            Remova o centro de distribuição que está mais distante das suas cidades designadas.

            Verifique se houve melhora na solução. Caso sim, atualize a solução com a nova configuração de centros de distribuição.

## Questão 4

    O balanço entre exploration e exploitation é um conceito importante em problemas de otimização e busca, que se refere à escolha de como direcionar a busca por uma solução ideal. Exploration se refere a explorar novas regiões do espaço de busca em busca de soluções promissoras, enquanto exploitation se refere a utilizar informações já conhecidas para otimizar soluções conhecidas.

    Exploration é importante porque permite encontrar soluções que podem estar em regiões desconhecidas do espaço de busca, o que pode levar a soluções melhores e mais diversas. No entanto, a exploração pode ser muito custosa em termos de tempo e recursos, e pode levar a soluções subótima se a busca por novas regiões for muito ampla ou aleatória.

    Por outro lado, exploitation é importante porque permite utilizar informações já conhecidas sobre o problema para otimizar as soluções existentes. Isso pode levar a soluções melhores e mais eficientes em menos tempo. No entanto, o exploitation pode levar a soluções locais subótima se o espaço de busca for muito limitado ou se a busca por otimização for muito restrita.

    Por isso, é importante buscar um equilíbrio entre exploration e exploitation, de modo a explorar novas regiões do espaço de busca de forma eficiente e, ao mesmo tempo, utilizar informações já conhecidas para otimizar soluções existentes. Isso pode ser alcançado através do uso de técnicas heurísticas que permitem uma busca mais inteligente e direcionada, como a busca local, o simulated annealing e os algoritmos genéticos, entre outros.