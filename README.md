# Puzzle solved using Monte Carlo simulation method using c++

N amigos estão sentados numa mesa redonda, onde cada cadeira é numerada de 1 a N no sentido horário.

Existe uma caneca de Kombucha na mesa que inicialmente se encontra com a pessoa sentada na cadeira 1. Sabe-se que toda vez que uma pessoa bebe um pouco do Kombucha, ela passa a caneca para a pessoa sentada à sua direita com probabilidade n/(N+1) e para a pessoa à sua esquerda com probabilidade (N-n+1)/(N+1), onde n é o número de sua cadeira.

Considere que o ato de uma pessoa passar uma caneca leva uma unidade de tempo.

a) Suponha que, caso a pessoa que recebe a caneca já tenha provado o Kombucha antes, ela apenas repassa a caneca no sentido em que recebeu. Calcule o número esperado de unidades de tempo passadas de forma que todos na mesa tenham provado o Kombucha para N=30 e N=500.

b) Suponha que, caso a pessoa que recebe a caneca já tenha provado o Kombucha antes, ela prova o Kombucha novamente e passa para a pessoa à sua direita com probabilidade n/(N+1) e para a pessoa à sua esquerda com probabilidade (N-n+1)/(N+1). Calcule o número esperado de unidades de tempo passadas de forma que todos na mesa tenham provado o Kombucha para N=10 e N=30.
