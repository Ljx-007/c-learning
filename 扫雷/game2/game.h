#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
#define BOMB 1
#define ROWS ROW+2
#define COLS COL+2
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void SetBoard(char board[ROWS][COLS], int row, int col);
void FindBoard(char board[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int get_bomb(char board[ROWS][COLS], int x, int y);
void unfold(char board[ROWS][COLS], char show[ROWS][COLS], int x, int y,int* p);