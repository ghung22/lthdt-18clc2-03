#include "CGAME.h"

Vect2D::Vect2D() { x = y = 0; }

CPEOPLE CGAME::getPeople()
{
	return *p;
}