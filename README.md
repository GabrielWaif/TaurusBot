# TaurusBot

## Introdução

O robô recebe um input em ASCII por meio da comunicação Bluetooth no ip: ..., e por meio da letra que é passada o robô faz a sua próxima ação.

## Comandos

| ASCII | Comando                                           |
| ----- | ------------------------------------------------- |
| 'S'   | O robô irá parar onde está                        |
| 'B'   | O robô vai para trás                              |
| 'L'   | O robô irá virar para a esquerda na próxima curva |
| 'R'   | O robô irá virar para a direita na próxima curva  |

## Bibliotecas necessárias

- SharpIr
- SoftwareSerial

## Como funciona

Os comandos da biblioteca SoftwareSerial foram adaptados em uma biblioteca adaptada "Moviment" com a velocidade adaptada para os motores do robô irem retos (já que não estavam indo reto com a mesma velocidade).

