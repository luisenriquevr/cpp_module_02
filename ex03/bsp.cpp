#include "Point.hpp"
#include "Fixed.hpp"

static Fixed absolute(Fixed nbr) {
	if (nbr < 0)
		return nbr * -1;
	return nbr;
}

static Fixed area(const Point A, const Point B, const Point C) {
	Fixed BAx = B.getFixedX() - A.getFixedX();
	Fixed CAy = C.getFixedY() - A.getFixedY();
	Fixed CAx = C.getFixedX() - A.getFixedX();
	Fixed BAy = B.getFixedY() - A.getFixedY();

	return absolute(((BAx * CAy) - (BAy * CAx))/2);
}

bool bsp(const Point A, const Point B, const Point C, const Point P) {
	Fixed ABCarea = area(A, B, C);
	Fixed PABarea = area(P, A, B);
	Fixed PCBarea = area(P, C, B);
	Fixed PACarea = area(P, A, C);

	if (ABCarea == 0 || PCBarea == 0 || PACarea == 0)
		return false;

	return (PABarea + PCBarea + PACarea) == ABCarea;
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