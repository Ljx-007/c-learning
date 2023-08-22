#pragma once
#include <stdio.h>//把stdio.h头文件放在game.h头文件引入，这样测试文件引入game.h的时候相当于也引入了stdio.h
#define ROW 3
#define COL 3
//函数声明
//void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
int IsWin(char board[ROW][COL], int row,int col);
int isFull(char board[ROW][COL], int row, int col);