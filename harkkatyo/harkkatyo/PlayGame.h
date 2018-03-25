#pragma once
#include "Helpers.h"

void SelectedMode(string, char[][LAUDAN_KOKO], char[][LAUDAN_KOKO], bool*);
void EnterShips(char[][LAUDAN_KOKO], char[][LAUDAN_KOKO], bool*);
bool CheckBoundaries(int, int, char, int);
void PlaceShip(char[][LAUDAN_KOKO], int, int, int, char);
void ShootingMode(char[][LAUDAN_KOKO], char[][LAUDAN_KOKO], bool*);
int CheckForSink(char[][LAUDAN_KOKO], char[][LAUDAN_KOKO], int, int, string);
