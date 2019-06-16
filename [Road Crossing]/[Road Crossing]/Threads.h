#pragma once

#include <thread>
#include <iostream>
using namespace std;

bool IS_RUNNING = true;

void exitGame(thread* t);
void UpdateGameFrame();