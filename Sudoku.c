#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include "will.h"

#define N 9
#define S ((int)sqrt(N))
#define K 50

typedef struct 
{
    int value;
    int isFixed;
} Cell;

Cell mat[N][N];

int CheckIfSafe(int i, int j, int num) 
{
    return (unUsedInRow(i, num) && unUsedInCol(j, num) && unUsedInBox(i - i % S, j - j % S, num));
}

int unUsedInRow(int i, int num) 
{
    for (int j = 0; j < N; j++) 
    {
        if (mat[i][j].value == num) 
        {
            return 0;
        }
    }
    return 1;
}

int unUsedInCol(int j, int num) 
{
    for (int i = 0; i < N; i++) 
    {
        if (mat[i][j].value == num) 
        {
            return 0;
        }
    }
    return 1;
}

int unUsedInBox(int rowStart, int colStart, int num) 
{
    for (int i = 0; i < S; i++) 
    {
        for (int j = 0; j < S; j++) 
        {
            if (mat[rowStart + i][colStart + j].value == num) 
            {
                return 0;
            }
        }
    }
    return 1;
}

void fillDiagonal() 
{
    for (int i = 0; i < N; i = i + S) 
    {
        fillBox(i, i);
    }
}

void fillBox(int row, int col) 
{
    int num;
    for (int i = 0; i < S; i++) 
    {
        for (int j = 0; j < S; j++) 
        {
            do 
            {
                num = 1 + rand() % N;
            } while (!CheckIfSafe(row + i, col + j, num));
            mat[row + i][col + j].value = num;
            mat[row + i][col + j].isFixed = 1;
            printSudoku(mat);
            Sleep(100);
            system("cls");
        }
    }
}

int fillRemaining(int i) 
{
    if (i >= N*N) 
    {
        return 1;
    }

    int row = i / N;
    int col = i % N;

    if (mat[row][col].value != 0) 
    {
        printSudoku(mat);
        Sleep(5);
        system("cls");
        return fillRemaining(i + 1);
    }

    for (int num = 1; num <= N; num++) 
    {
        if (CheckIfSafe(row, col, num)) 
        {
            mat[row][col].value = num;
            printSudoku(mat);
            Sleep(5);
            system("cls");
            if (fillRemaining(i + 1)) 
            {
                return 1;
            }
            mat[row][col].value = 0;
        }
    }
    return 0;
}

void removeKDigits() 
{
    for (int count = 0; count < K; ) 
    {
        int row = rand() % N;
        int col = rand() % N;
        if (mat[row][col].value != 0 && mat[row][col].isFixed == 0) 
        {
            count++;
            mat[row][col].value = 0;
            printSudoku(mat);
            Sleep(50);
            system("cls");
        }
    }
}

void printSudoku()
{
    for (int i = 0; i < N; i++)
    {
        if (i==0) 
        {
            printf("+-------+-------+-------+\n");
        }
        else if (i % 3 == 0 && i != 0)
        {
            printf("+-------+-------+-------+\n");
        }
        for (int j = 0; j < N; j++)
        {
            if (j==0)
            printf("| ");
            else if (j % 3 == 0 && j != 0)
                printf("| ");
            printf("%d ", mat[i][j]);
        }
        printf("|\n");
    }
    printf("+-------+-------+-------+\n");
}

int solve_sudoku(Cell mat[N][N], int row, int col) 
{
    if (row < N && col < N) 
    {
        if (mat[row][col].value != 0) 
        {
            if ((col + 1) < N)
            {
                return solve_sudoku(mat, row, col + 1);
            }
            else if 
            {
                ((row + 1) < N) return solve_sudoku(mat, row + 1, 0);
            }
            else 
            {
                return 1;
            }
        } 
        else 
        {
            for (int num = 1; num <= N; num++) 
            {
                if ((CheckIfSafe(row, col, num))) 
                {
                    mat[row][col].value = num;

                    if (solve_sudoku(mat, row, col)) 
                    {
                        return 1;
                    }
                    else 
                    {
                        mat[row][col].value = 0;
                    }
                }
            }
        }

        return 0;
    } 
    else 
    {
        return 1;
    }
}

int main() 
{
    char c=0, p='1';
    Cell copy[N][N];
    srand(time(NULL));
    wel();
    while (p=='1')
    {
        gen();
        fillDiagonal();
        fillRemaining(0);
        removeKDigits();
        for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < N; j++) 
            {
                copy[i][j] = mat[i][j];
            }
        }
        printSudoku(mat);
        printf("Giving you time to solve.\n");
        sleep(1);
        printf("Press 1 to see solution.");
        c = getch();
        while(c!='1')
        {
            c = getch();
        }
        sol();
        solve_sudoku(mat, 0, 0);
        printf("Generated Sudoku:\n");
        printSudoku(copy);
        printf("\n\nSolved Sudoku:\n");
        printSudoku(mat);
        printf("\n\n\tTHANK YOU!\n\n");
        printf("If you want to continue press 1\nor if you want to terminate press 0 : \n\n");
        p = getch();
        while(!(p=='1'||p=='0'))
        {
            p = getch();
        }
    }
    return 0;
}
