#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

const int E_KOORD_VAARIN = 1;
const int E_SUCCESS = 0;
const int LAUDAN_KOKO = 7;

void Alusta(char[][LAUDAN_KOKO]);
void TulostaLauta(char[][LAUDAN_KOKO], int rows, int cols);
void PrintShots(char[][LAUDAN_KOKO], int, int);
void LoadGame(char[][LAUDAN_KOKO], char[][LAUDAN_KOKO]);
void SaveGame(char[][LAUDAN_KOKO], char[][LAUDAN_KOKO], int, int);
string PrintMenu();
bool LaillinenValinta(string, char);
int MuunnaKoordinaatti(string, int*, int*);
void DebugPrint(char[][LAUDAN_KOKO]);

