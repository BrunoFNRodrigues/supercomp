Os princípais alvos de otimização são:

```
1,000,000 ( 5.86%)     x = (rand()%2) -1;
5,987,100 (35.07%)  => ???:0x00000000001090a0 (100,000x)
  900,000 ( 5.27%)     y = (rand()%2) -1;
5,987,096 (35.07%)  => ???:0x00000000001090a0 (100,000x)
```

Para otimizalos eu parelizaria  o loop, pois o resultdos de dele a a soma de todas as tentativas, portanto é possível que quebrar a quantidade total de tentativas em varias threds e depois somar os resultados obtido, isso não sería uma solução pior, porque não ordenação para o valor de pi, portanto não é necessário ordenar os resultados antes de concluir o cálculo.