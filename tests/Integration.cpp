#include <gtest/gtest.h>
#include "Square.hpp"
#include "Triangle.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include <cmath>

const double ERR = 0.000000001;

/* 
Questão 20 - Dobrando papéis (OBMEP 2020):

A figura é um recorte de papel formado por um quadrado de lados medindo 10cm e dois
triângulos isósceles (triângulo isósceles são triângulos com dois lados de mesma medida).

(imagem meramente ilustrativa - altura dos triângulos é de 10cm)
   _______________
  /|             |\
 / |             | \
/  |             |  \
\  |             |  /
 \ |             | /
  \|_____________|/


a) Dobrando um dos triângulos sobre o quadrado, conforme a figura, qual a área do qua-
drado que fica visível?


b) Dobrando os dois triângulos sobre o quadrado, conforme a figura, qual a área do qua-
drado que fica visível?

*/

TEST(DobrandoPapeis, IntegrationTests) {
    // a)
    //A área visível é a diferença entre a área do quadrado e a área do triângulo, ou seja:
    Square<double> square = Square<double>(10);
    Triangle<double> triangle = Triangle<double>(10,sqrt(125),sqrt(125));
    double visibleArea = square.area() - triangle.area();
    ASSERT_NEAR(visibleArea, 50, ERR);

    // b)
    //Na figura resultante, sabemos que a área do quadrado visível forma dois triangulos
    // isósceles de base 10 e lados sqrt(125)/2. Portanto, a área resultante é:

    Triangle<double> newTriangle = Triangle<double>(10,sqrt(125)/2,sqrt(125)/2);
    double newVisibleArea = 2*newTriangle.area();
    ASSERT_NEAR(newVisibleArea, 25, ERR);
}



/* 
Questão 7 - Divisão do Terreno (OBMEP 2020):

Jonas dividiu um terreno quadrado em oito partes retangulares iguais, conforme a figura,
dando uma parte para cada um dos seus oito filhos. Para cercar sua parte, Antônia verifi-
cou que o seu perímetro era 120m.

_________________
|   |   |   |   |
|   |   |   |   |
|___|___|___|___|
|   |   |   |   |
|   |   |   |   |
|___|___|___|___|


Qual a área do terreno que Jonas dividiu?

*/

TEST(DivisaoDoTerreno, IntegrationTests) {
    
    // Como o terreno inicialmente era quadrado, após a divisão, o comprimento de cada
    // retângulo mede o dobro de sua largura. Sendo assim, a área do terreno de Jonas é:
    
    Rectangle<double> rectangle = Rectangle<double>(120/3, 120/6);

    // Como são 8 retângulos iguais, temos que a área do terreno original é:
    
    double rectanglesArea = 8*rectangle.area();
    
    ASSERT_NEAR(rectanglesArea, 6400, ERR);

    // Perceba que também podemos encontrar o lado do quadrado da área orignial, 
    // que é igual a duas vezes o comprimento. Dessa forma, podemos também encontrar a área:

    Square<double> square = Square<double>(2*(120/3));
    double areaSquare = square.area();
    ASSERT_NEAR(areaSquare, rectanglesArea, ERR);
}


/* 
Questão 25 - Os Triângulos Equiláteros (OBBMEP 2020)


Na figura a seguir, o perímetro do triângulo equilátero maior é 24cm e cada um dos triân-
gulos menores também são equiláteros. Qual a soma dos comprimentos de todos os seg-
mentos desenhados na figura?

         /_\
        /_\/_\
       /_\   /_\  
     /_\/_\/_\/_\
    /_\         /_\
   /_\/_\      /_\/_\
 /_\   /_\   /_\   /_\
/_\/_\/_\/_\/_\/_\/_\/_\


*/

TEST(OsTriangulosEquilateros, IntegrationTests) {
    
    // Como o perímetro do triângulo maior é 24cm, o lado de cada um dos triângulos
    // menores é 1cm. Para encontrar a soma de todos os segmentos, basta somar os perímetros
    // menores.Ao todo temos 27 triângulos, e portanto:
    
    Triangle<double> triangle = Triangle<double>(1,1,1);
    
    double segmentsLength = 27*triangle.perimeter();
    
    ASSERT_EQ(segmentsLength, 81);
}

/* 
Questão 11 - Cortando o Cubo (OBMEP - 2020)

No cubo ABCDEFGH, cuja aresta mede 6cm, o ponto M é ponto médio de EF.
    
     _______________________ G
   H/                       /
   /*                      /|
  / *  *                  / |
E/__*________*M__________/  |
 |  *        *          |F  |
 |  *       *           |   |
 | *      *             |   |
 | * D __*______________|___|C
 | * / *                |   /
 |* / *                 |  /
 | / *                  | /
 |/*____________________|/
A                        D

a) Determine a área do triângulo AM H.

b) Determine o volume da pirâmide AM HE. (O volume de uma pirâmide pode ser cal-
culado pela terça parte do produto entre a área da base e a altura relativa a esta base).

*/

TEST(CortandoOCubo, IntegrationTests) {
    // a)
    // AH é a diagonal de uma face, ou seja:

    Square<double> square = Square<double>(6);
    double AH = square.diagonal();


    // MH e AM são hipotenusas de triângulos cujos catetos medem 6cm e 3cmu, portanto:
    double AM = 3*sqrt(5);
    double MH = AM;
    Triangle<double> AHM = Triangle<double>(AH,MH,AM);
    
    double areaAHM = AHM.area();    
    ASSERT_NEAR(areaAHM, 9*sqrt(6), ERR);

    // b)

    // Sabemos todos os lados do triangulo EHM, e portanto conseguimos obter a base da pirâmide AHME:

    Triangle<double> EHM = Triangle<double>(6,3,MH);
    double baseAHME = EHM.area();

    // A altura dessa pirâmide é o segmento AE, que é a aresta do quadrado. Portando, o volume é:

    double volume = (baseAHME*6)/3;

    ASSERT_NEAR(volume, 18, ERR);

}


/*
Questão 72 - Círculo intermediário (OBMEP 2010 - adaptada)

Na figura, os três círculos são concêntricos, e a área do menor 
círculo coincide com a área do maior anel, destacado em cinza. 
O raio do menor círculo é 5 cm e do maior 13 cm. Qual é o raio 
(em cm) do círculo intermediário (raio inteiro)?

                      ,,ggddY""""Ybbgg,,
                 ,agd""'              `""bg,
              ,gdP"                       "Ybg,
            ,dP"                             "Yb,
          ,dP"         _,,ddP"""Ybb,,_         "Yb,
         ,8"         ,dP"'         `"Yb,         "8,
        ,8'        ,d"                 "b,        `8,
       ,8'        d"                     "b        `8,
       d'        d'        ,gPPRg,        `b        `b
       8         8        dP'   `Yb        8         8
       8         8        8)     (8        8         8
       8         8        Yb     dP        8         8
       8         Y,        "8ggg8"        ,P         8
       Y,         Ya                     aP         ,P
       `8,         "Ya                 aP"         ,8'
        `8,          "Yb,_         _,dP"          ,8'
         `8a           `""YbbgggddP""'           a8'
          `Yba                                 adP'
            "Yba                             adY"
              `"Yba,                     ,adP"'
                 `"Y8ba,             ,ad8P"'
                      ``""YYbaaadPP""''


*/

TEST(CirculoIntermediario, IntegrationTests) {
 
    // Vamos obter as áreas dos círculos

    Circle<double> largerCircle = Circle<double>(13);
    Circle<double> smallerCircle = Circle<double>(5);

    // Sabendo que o raio tem que estar entre 5 e 13, podemos passar por todas as possibilidades
    // e verificar se a área do círculo menor é igual a área do maior menos a do meio. Assim:
    
    // (apesar de possuir if's e for's, esse teste é totalmente determinístico, e o ASSERT executa de 
    // qualquer forma, sempre com o mesmo resultado)
    double r;
    for(double i=6; i<13; i++) {
        Circle<double> mediumCircle = Circle<double>(i);
        if(abs(smallerCircle.area() - (largerCircle.area() - mediumCircle.area())) <= ERR) {
            r = i;
            break;
        }
    }
    
    ASSERT_EQ(r, 12);

}