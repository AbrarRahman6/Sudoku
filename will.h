#include<stdio.h>
#include<Windows.h>
void print() {
    printf("\n\n\n\n\t\t\t======================================================\n");
    printf("\t\t\t|   ######  ##   ## #####    #####  ##   ## ##   ##  |\n");
    printf("\t\t\t|  ##    ## ##   ## ##  ##  ##   ## ##  ##  ##   ##  |\n");
    printf("\t\t\t|  ##    ## ##   ## ##   ## ##   ## ## ##   ##   ##  |\n");
    printf("\t\t\t|   ###     ##   ## ##   ## ##   ## ###     ##   ##  |\n");
    printf("\t\t\t|      ###  ##   ## ##   ## ##   ## ###     ##   ##  |\n");
    printf("\t\t\t|  ##    ## ##   ## ##   ## ##   ## ## ##   ##   ##  |\n");
    printf("\t\t\t|  ##    ## ##   ## ##  ##  ##   ## ##  ##  ##   ##  |\n");
    printf("\t\t\t|   ######   #####  #####    #####  ##   ##  #####   |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t|  G E N E R A T O R       A N D       S O L V E R   |\n");
    printf("\t\t\t======================================================\n");
}

void wel() {
    system("color 1");
    print();
    sleep(1);
    system("cls");
    system("color 4");
    print();
    sleep(1);
    system("cls");
    system("color 3");
    print();
    sleep(1);
    system("cls");
    system("color 2");
    print();
    sleep(1);
}
void gen()
{
    system("cls");
    printf("Generating a sudoku puzzle.");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".");
    sleep(1);
    system("cls");
}

void sol() {
    system("cls");
    printf("Solving the puzzle.");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".");
    sleep(1);
    system("cls");
}

