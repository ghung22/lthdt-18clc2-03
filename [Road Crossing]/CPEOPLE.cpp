#include "CPEOPLE.h"

bool CPEOPLE::inContact(CVEHICLE v)
{
	return v.inContact(pos);
}
bool CPEOPLE::inContact(CANIMAL a)
{
	return a.inContact(pos);
}
CVEHICLE CPEOPLE::nowContact(const CVEHICLE*& v)
{
	for (int i = 0; i < MAX_TRUCK + MAX_CAR; i++)
	{
		if (inContact(v[i]))
			return v[i];
	}
}
CANIMAL CPEOPLE::nowContact(const CANIMAL*& a)
{
	for (int i = 0; i < MAX_DINO + MAX_BIRD; i++)
	{
		if (inContact(a[i]))
			return a[i];
	}
}