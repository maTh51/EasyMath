# EasyMath 

[![codecov](https://codecov.io/gh/maTh51/EasyMath/branch/main/graph/badge.svg?token=K7QRXSVW4Z)](https://codecov.io/gh/maTh51/EasyMath)

Trabalho prático 1 da disciplina de Testes de Software - Ciência da Computação UFMG 2021/1

## Integrantes

Luiz Felipe, Marcos Vinicius, Matheus Pimenta

## EasyMath

O sistemas desenvolvido é uma biblioteca de formas geométricas, sejam elas 2D ou 3D. As seguintes formas estão disponíveis:
- Quadrado
- Círculo
- Triângulo
- Hexagono
- Trapézio
- Retangulo
- Paralelogramo
- Pentágono
- Cilindro
- Prisma triangular
- Prisma Pentagonal
- Prisma Hexagonal
- Esfera
- Cubo
- Pirâmide
- Paralelepipedo

Para cada forma, temos funções que calculam algumas de suas propriedades. Como área, volume, perímetro, diagonal, etc.

### Tecnologias

O sistema foi desenvolvido em C++ em um ambiente Linux e o framework de teste utilizado foi o GTest.



## Codecov Steps

mkdir coverage
g++ -o coverage/cov -fprofile-arcs -ftest-coverage tests/EasyMath.cpp -lgtest -Ilib
./coverage/cov
cd coverage
mkdir reports
cd reports
gcov ../../tests/EasyMath.cpp -o ../cov-EasyMath.gc
lcov -d .. -c --directory . --output-file coverage.info
