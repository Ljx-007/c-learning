#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9
#define BOMB 10
#define ROWS ROW+2
#define COLS COL+2
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void setmine(char board[ROWS][COLS], int row, int col);
void findbomb(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int getbomb(char mine[ROWS][COLS], int x, int y);
void unfold(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y,int* p);
