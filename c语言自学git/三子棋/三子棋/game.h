#pragma once
#include <stdio.h>//��stdio.hͷ�ļ�����game.hͷ�ļ����룬���������ļ�����game.h��ʱ���൱��Ҳ������stdio.h
#define ROW 3
#define COL 3
//��������
//void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
int IsWin(char board[ROW][COL], int row,int col);
int isFull(char board[ROW][COL], int row, int col);