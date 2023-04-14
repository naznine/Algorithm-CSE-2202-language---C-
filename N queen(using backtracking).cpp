#include<bits/stdc++.h>
using namespace std;

int board[100][100];
int N,k;

void printSolution()
{
    if(k>2)
        return;
    printf("Soluion #%d:\n",k++);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if(board[i][j]==0)
                printf(" *");
            else
                printf(" Q");
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;
    for (i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int col)
{
    if (col == N)
    {
        printSolution();
        return true;
    }
    bool res = false;
    for (int i = 0; i < N; i++)
    {
        if ( isSafe(i, col) )
        {
            board[i][col] = 1;
            res = solveNQUtil(col + 1) || res;

            board[i][col] = 0; // BACKTRACK
        }
    }
    return res;
}

bool solveNQ(int N)
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
    }
}

int main()
{
    int tc,n;
    ifstream input;
    input.open("queen.txt");
    for(int ca=1;ca<=10;ca++)
    {
        k=1;
        input>>N;
        cout<<"Enter the number of queens:\n"<<N<<endl;
        solveNQ(N);
    }
}

