#include<bits/stdc++.h>
using namespace std;

int board[100][100];
int N,step=0;

void printSolution()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

bool isSafe(int row, int col)
{
    step=step+1;

    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int col)
{
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++)
    {
        if (isSafe(i, col))
        {
            board[i][col] = 1;
            if (solveNQUtil(col + 1))
                return true;
            board[i][col] = 0; // BACKTRACK
        }
    }
    return false;
}

bool solveNQ()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            board[i][j]=0;
        }
    }
    if (solveNQUtil(0) == false)
    {
        printf("Solution does not exist");
        return false;
    }

    printSolution();
    return true;
}

int main()
{
    int tc,n;
    ifstream input;
    input.open("NQueen.txt");
    input>>tc;
    for(int ca=1;ca<=tc;ca++)
    {
        step=0;
        input>>N;
        cout<<N<<endl;
        solveNQ();
        cout<<"Number of required permutation ="<<step<<endl<<endl;
    }
}
