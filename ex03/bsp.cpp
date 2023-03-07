#include "Point.hpp"
#include "Fixed.hpp"

bool bsp(const Point A, const Point B, const Point C, const Point P) {
	Fixed totalArea = (((B.getFixedX() - A.getFixedX())) * ((C.getFixedY() - A.getFixedY()) - (C.getFixedX() - A.getFixedX())) * ((B.getFixedY() - A.getFixedY()))) / 2;

	if (totalArea < Fixed(0))
		totalArea = totalArea * -1;

	Fixed PABarea = (((B.getFixedX() - P.getFixedX())) * ((A.getFixedY() - P.getFixedY()) - (A.getFixedX() - P.getFixedX())) * ((B.getFixedY() - P.getFixedY()))) / 2;

	if (PABarea < Fixed(0))
		PABarea = PABarea * -1;

	Fixed PCBarea = (((C.getFixedX() - P.getFixedX())) * ((B.getFixedY() - P.getFixedY()) - (B.getFixedX() - P.getFixedX())) * ((C.getFixedY() - P.getFixedY()))) / 2;

	if (PCBarea < Fixed(0))
		PCBarea = PCBarea * -1;

	Fixed PACarea = (((C.getFixedX() - P.getFixedX())) * ((A.getFixedY() - P.getFixedY()) - (A.getFixedX() - P.getFixedX())) * ((C.getFixedY() - P.getFixedY()))) / 2;

	if (PCBarea < Fixed(0))
		PCBarea = PCBarea * -1;

	if ((PABarea + PCBarea + PACarea) == totalArea)
		return true;
	else
		return false;
}

/*
Para determinar si un punto dado pertenece a un triángulo dado por tres puntos en un eje
de coordenadas, puedes seguir los siguientes pasos:

Definir los tres puntos que forman el triángulo. Puedes llamarlos A, B y C.

Calcular las coordenadas del punto dado. Puedes llamarlo P y sus coordenadas (xP, yP).

Calcular el área total del triángulo ABC utilizando la fórmula del determinante:

áreaABC = |(xB-xA)(yC-yA) - (xC-xA)(yB-yA)| / 2

Donde |...| es la función valor absoluto.

Calcular el área de cada uno de los sub-triángulos formados por el punto P y dos vértices del triángulo
ABC utilizando la misma fórmula del determinante. Para hacer esto, simplemente debes reemplazar las coordenadas
del tercer vértice por las coordenadas del punto P. Por ejemplo, para calcular el área del sub-triángulo PAB:

áreaPAB = |(xB-xP)(yA-yP) - (xA-xP)(yB-yP)| / 2

Si la suma de las áreas de los tres sub-triángulos es igual al área total del triángulo ABC,
entonces el punto P está dentro del triángulo. En otras palabras, si se cumple la siguiente ecuación:

áreaABC = áreaPAB + áreaPBC + áreaPCA

Entonces el punto P está dentro del triángulo ABC.

De lo contrario, si la suma de las áreas de los sub-triángulos es mayor que el área total del triángulo ABC,
entonces el punto P está fuera del triángulo. Y si la suma de las áreas de los sub-triángulos es menor que
el área total del triángulo ABC, entonces el punto P está en una de las aristas o vértices del triángulo.
*/