#pragma once
#include "Helpers.h"

void SelectedMode(string, char[][LAUDAN_KOKO], char[][LAUDAN_KOKO], bool*);
void EnterShips(char[][LAUDAN_KOKO], char[][LAUDAN_KOKO], bool*);
bool CheckValidPlacement(char[][LAUDAN_KOKO],int, int, char, int);
void PlaceShip(char[][LAUDAN_KOKO], int, int, int, char);
void ShootingMode(char[][LAUDAN_KOKO], char[][LAUDAN_KOKO], bool*);
int CheckForSink(char[][LAUDAN_KOKO], char[][LAUDAN_KOKO], int, int, string);
bool CheckBoundaries(int, int, char, int);
bool CheckOverlap(char[][LAUDAN_KOKO], int, int, char, int);
void RandomPlacement(char[][LAUDAN_KOKO], char[][LAUDAN_KOKO], bool*);
void PlaceRandomly(char[][LAUDAN_KOKO], int, map<int, char>);
bool IsGameOver(char[][LAUDAN_KOKO], char[][LAUDAN_KOKO]);
