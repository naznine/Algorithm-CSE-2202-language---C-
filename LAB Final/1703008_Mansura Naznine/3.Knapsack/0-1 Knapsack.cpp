/// Fractional Knapsack Problem
/// Author: 1703008_Mansura Naznine


#include<bits/stdc++.h>
using namespace std;

int knapSack(int Size, int wt[], int val[], int n)
{
    int table[n+5][Size+5];

    for (int i = 0; i <= n; i++)
   {
       for (int j = 0; j <= Size; j++)
       {
           if (i==0 || j==0)
               table[i][j] = 0;
           else if (wt[i-1] <= j)
                 table[i][j] = max(val[i-1] + table[i-1][j-wt[i-1]],  table[i-1][j]);
           else
                 table[i][j] = table[i-1][j];
       }
   }

   cout<<"\tKnapsack Table:\t"<<endl;
   cout<<"\t---------------\t"<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=Size;j++)
        {
            cout<<"\t"<<table[i][j]<<" ";
        }
        cout<<endl;
    }

    return table[n][Size];
}

int main()
{
    ifstream input;
    input.open("input.txt");
    int n;
    input>>n;
    int val[n+5];
    int wt[n+5];
    for(int i=0;i<n;i++)
    {
        input>>val[i];
    }
    for(int i=0;i<n;i++)
    {
        input>>wt[i];
    }
    int  Size;
    input>>Size;
    cout<<"\nMaximum Value = "<<knapSack(Size, wt, val, n)<<endl;
    return 0;
}

