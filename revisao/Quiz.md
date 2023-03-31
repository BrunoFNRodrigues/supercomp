- Defina um problema difícil computacionalmente. 

    Um problema difícil computacionalmente é um problema que não pode ser resolvido de forma eficiente em tempo polinomial para todas as instâncias do problema. Em outras palavras, um problema difícil computacionalmente é um problema que não pode ser resolvido por algoritmos eficientes conhecidos em um tempo razoável. Problemas difíceis computacionalmente são de grande importância teórica e prática na ciência da computação, pois têm implicações para a segurança da informação, para a otimização de sistemas e para a análise de algoritmos. Alguns exemplos de problemas difíceis computacionalmente incluem o problema do caixeiro-viajante (TSP), o problema da mochila (Knapsack), o problema da soma de subconjuntos (Subset Sum), o problema do caminho mais curto em grafos (Shortest Path), o problema de coloração de grafos (Graph Coloring), o problema da satisfatibilidade booleana (SAT) e o problema de fatoração de inteiros (Integer Factorization).

- Qual o papel das heurísticas na abordagem de obter soluções para problemas computacionalmente difíceis?

    Heurísticas são métodos de solução de problemas que não garantem a obtenção da solução ótima, elas podem ser baseadas em técnicas de busca, como busca em profundidade ou busca em largura, ou podem envolver técnicas mais sofisticadas, como algoritmos genéticos, redes neurais ou sistemas especialistas.

    Embora as soluções encontradas por meio de heurísticas não sejam garantidamente ótimas, elas podem ser úteis na prática, especialmente quando é necessário encontrar soluções rapidamente ou quando a solução exata é impraticável de ser obtida.

    Em resumo, as heurísticas desempenham um papel importante na abordagem de obter soluções para problemas computacionalmente difíceis, fornecendo **soluções aceitáveis** em um **tempo razoável** e sendo uma abordagem complementar a outras técnicas mais complexas.

- A heurística gulosa tem alguma garantia de otimalidade?

    A heurística gulosa (também conhecida como abordagem gulosa ou algoritmo guloso) é uma técnica de solução de problemas que se baseia em fazer a escolha localmente ótima em cada etapa do algoritmo, na esperança de que isso leve a uma solução global ótima. No entanto, essa técnica não oferece garantias de otimalidade, isto é, não é garantido que a solução encontrada seja a melhor possível.

- Qual o papel que a aleatoriedade exerce em problemas de combinação discretos?

    Em problemas de combinação discretos, a aleatoriedade pode desempenhar um papel importante em várias etapas do processo de resolução, incluindo a geração de soluções iniciais, a exploração de diferentes regiões do espaço de solução e a introdução de variações nas soluções existentes.

- A heurística de busca local apresenta vantagens em relação à heurística gulosa?

    Sim, a heurística de busca local apresenta vantagens em relação à heurística gulosa em muitos casos. Enquanto a heurística gulosa faz escolhas locais ótimas em cada etapa, sem considerar a possibilidade de um resultado globalmente ótimo, a heurística de busca local tenta melhorar iterativamente uma solução inicial modificando-a localmente, buscando encontrar uma solução ótima globalmente.

    Uma das principais vantagens da heurística de busca local é que ela pode escapar de mínimos locais e explorar melhor o espaço de solução. Em problemas onde o espaço de solução é complexo e com muitos mínimos locais, a heurística de busca local pode encontrar uma solução melhor do que a heurística gulosa, que pode ficar presa em um mínimo local subótimo.

    Além disso, a heurística de busca local pode ser mais eficiente em termos de tempo computacional em alguns casos. Como a heurística gulosa faz escolhas ótimas locais em cada etapa, pode levar mais tempo para encontrar uma solução globalmente ótima, enquanto a heurística de busca local pode convergir rapidamente para uma solução próxima da ótima e melhorar essa solução de forma incremental.

    Em resumo, a heurística de busca local tem algumas vantagens em relação à heurística gulosa, incluindo a capacidade de escapar de mínimos locais e eficiência em termos de tempo computacional. No entanto, o desempenho da heurística de busca local depende das características específicas do problema em questão.

- No Valgrind, qual o papel do indicador IR?

    O indicador IR (Instruction Read) é usado para medir o número de instruções lidas durante a execução do programa.

- Se um problema é 30% sequencial, qual o speedup máximo que ele pode ter ao paralelizarmos?

    Se um problema é 30% sequencial, significa que 70% dele é paralelizável, ou seja, pode ser executado em paralelo em vários processadores ou núcleos de processamento.

    O speedup máximo que pode ser alcançado ao paralelizar um problema é limitado pelo tempo sequencial, ou seja, pelo tempo que leva para executar a parte não paralelizável do problema. Esse limite é conhecido como Lei de Amdahl.

    De acordo com a Lei de Amdahl, o speedup máximo que pode ser alcançado ao paralelizar um problema é dado pela fórmula:

    Speedup máximo = 1 / (tempo sequencial + tempo paralelo / número de processadores)

    Substituindo os valores do problema (tempo sequencial = 0.3, tempo paralelo = 0.7) e supondo que temos infinitos processadores, temos:

    Speedup máximo = 1 / (0.3 + 0.7 / infinito) = 1 / 0.3 = 3.33

    Portanto, o speedup máximo que pode ser alcançado ao paralelizar um problema que é 30% sequencial é de 3.33 vezes. Isso significa que, teoricamente, podemos reduzir o tempo de execução do problema em até 3.33 vezes usando um número suficientemente grande de processadores. No entanto, na prática, é improvável que possamos alcançar esse speedup máximo devido a sobrecarga de comunicação entre os processadores e outras limitações de hardware e software.

- Quais vantagens e desvantagens da passagem de parâmetros por referência?

    Algumas vantagens da passagem de parâmetros por referência incluem:

        Eficiência de memória: a passagem por referência é geralmente mais eficiente do que a passagem por valor, especialmente para tipos de dados grandes, porque não requer a criação de uma cópia da variável.

        Compartilhamento de dados: a passagem por referência permite que uma função compartilhe o mesmo espaço de memória com a função chamadora, o que pode ser útil em situações em que é necessário compartilhar dados entre funções.

    Algumas desvantagens da passagem de parâmetros por referência incluem:

        Efeito colateral: como a função pode modificar diretamente o valor da variável original, isso pode causar efeitos colaterais indesejados se a função não for cuidadosamente projetada para não modificar outros dados além dos esperados.

        Falta de clareza: em alguns casos, a passagem por referência pode tornar o código mais difícil de entender e depurar, especialmente se a função modificar muitas variáveis e o fluxo de controle não for claro.

- Na aula sobre valgrind, nós vimos formas diferentes de somar os números de uma matriz. Qual a razão para a diferença de performance?

    A diferença de performance se da pela forma que as linhas e colunas da matriz eram guardadas na memória, quando o programa escolia uma linha e soma o valor das colunas e depois soma esse resultado ao da proxima linha, o a leitura da memoria acontece de forma mais eficiente, pois os valores de uma linha ficam lado a lado na memória então elas são transferidas para a memória cache juntas, assim tornando o acesso mais rápido, já no caso de primeio somar as linhas e depois as culunas, é necessário que cache fique trocando o seu contéudo com mais frequência.

- Como se dá a heurística por algoritmos genéticos? Qual o papel da mutação?

    O processo geral de um algoritmo genético consiste em:

    1. Inicialização: geração de uma população inicial aleatória de indivíduos (soluções candidatas).

    2. Avaliação: cada indivíduo é avaliado com uma função de aptidão (fitness function), que mede a qualidade da solução.

    3. Seleção: alguns indivíduos são selecionados para sobreviver e se reproduzir na próxima geração, com base em sua aptidão.

    4. Operadores genéticos: novos indivíduos são criados a partir dos pais selecionados, usando operadores genéticos, como cruzamento (recombinação de características dos pais) e mutação (introdução aleatória de mudanças em um indivíduo).

    5. Repetição: os passos 2-4 são repetidos até que uma solução satisfatória seja encontrada ou um limite de geração seja atingido.

    O objetivo da mutação é introduzir variação aleatória em uma solução, permitindo que a busca explore novas regiões do espaço de solução que não seriam alcançadas pela seleção natural e pelo cruzamento. A mutação é aplicada a um indivíduo selecionado aleatoriamente na população e consiste em alterar aleatoriamente um ou mais genes (ou características) da solução.


- Na busca exaustiva, a profundidade de busca afeta consideravelmente o resultado obtido. Explique com suas palavras a importância de se buscar conhecer uma profundidade razoável de busca?

    Na busca exaustiva, a profundidade de busca se refere ao número de etapas ou passos que o algoritmo realiza antes de retornar uma solução ou uma aproximação para a solução. Quanto maior a profundidade de busca, maior o tempo de execução e a complexidade do algoritmo.

    Porém, uma profundidade muito baixa pode resultar em uma solução subótima ou mesmo na falta de uma solução viável.

    Por outro lado, uma profundidade muito alta pode levar a um aumento exponencial no tempo de execução e pode não trazer muitas melhorias significativas na solução. 
    
    Portanto, é importante buscar conhecer uma profundidade razoável de busca, que permita encontrar soluções aceitáveis em um tempo viável.