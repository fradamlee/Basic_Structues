
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <assert.h>
#include <math.h>

#define SIDE 5
vector<int> board(SIDE);

void configureBoard(int* lst)
{
   for (int i = 0; i < SIDE; i++)
   {
        board[i] = lst[i];
   }
}

void drawBoard(vector<int>& board)
{
    for (int i1 = 0; i1 < SIDE; i1++)
    {
        cout << "|";
        for (int i2 = 0; i2 < SIDE; i2++)
        {
            if (board[i1] == i2) cout << "X|";
            else cout << " |";
        }
        cout << "\n";
    }
}

bool individualValidation(vector<int>& board, int i1, int i2)
{
    int distance = 1;
    for (int i = i1+1; i < SIDE; i++)
    {   
        if (board[i] == (i2 - distance) || board[i] == i2 || board[i] == (i2 + distance)) return false;
        distance++;  
    }
    return true;
}

bool boardValidation(vector<int>& board)
{
    for (int i = 0; i < SIDE - 1; i++)
    {
        if (!individualValidation(board, i, board[i])) return false;
    }

    cout << "\n \n";
    drawBoard(board);
    return true;
}

void printIterations(vector<int>& board)
{
    for (int i = 0; i < SIDE; i++)
    {
        cout << board[i] << "\t";
    }
    cout << "\n";
}

void mapBoard(vector<int>& board)
{
    int j, lastNum, numSoluciones = 0;
    long long allIter = pow(SIDE, SIDE);
    for (long long i = 0; i < allIter; i++)
    {
        j = 0;
        lastNum = board[j];

        //
        numSoluciones += boardValidation(board);

        while (lastNum == SIDE-1)
        {
            board[j] = 0;
            lastNum = board[++j];
        }
        board[j]++;
    }
    cout << "Soluciones encontradas: " << numSoluciones << endl;
    cout << "Numero de iteraciones:  " << allIter << endl;
}

int main()
{
    int lst1[] = {0, 0, 0, 0, 0};

    configureBoard(lst1);

    mapBoard(board);

    return 0;
}