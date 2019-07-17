#include "CGAME.h"

CPEOPLE CGAME::getPeople()
{
	return *p;
}

CVEHICLE* CGAME::getVehicle() { return nullptr; }
CANIMAL* CGAME::getAnimal() { return nullptr; }

void CGAME::draw() { }
void CGAME::reset() { }
void CGAME::exit(thread::native_handle_type handle) { }
void CGAME::start() { }

void CGAME::load() { }
void CGAME::save() { }
void CGAME::pause(thread::native_handle_type handle) { }
void CGAME::resume(thread::native_handle_type handle) { }

void CGAME::updatePosPeople(char button) { }
void CGAME::updatePosVehicle() { }
void CGAME::updatePosAnimal() { }