#include<bits/stdc++.h>
using namespace std;
#include<fstream>
int arr[10000];
int cnt;

void GenerateInput(int it)
{
    fstream in;
    in.open("Quick.txt");
    for(int i=0; i<it; i++)
    {
        in<<rand()<<endl;
    }
    in.close();
}

int partision(int l,int h)
{
    cnt=cnt+1;
    int pivot=arr[h],tm;
    int i=l-1;
    for(int j=l; j<=h-1; j++)
    {
        cnt=cnt+1;
        if(arr[j]<=pivot)
        {
            i++;

            tm=arr[i];
            arr[i]=arr[j];
            arr[j]=tm;

            cnt=cnt+5;
        }
    }
    tm=arr[i+1];
    arr[i+1]=arr[h];
    arr[h]=tm;

    cnt=cnt+3;
    return (i+1);
}

void qs(int l,int h)
{
    cnt=cnt+1;
    if(l<h)
    {
        cnt=cnt+1;
        int p=partision(l,h);
        qs(l,p-1);
        qs(p+1,h);
    }
}

int main()
{
    for(int it=4000; it<=8500;it=it+500)
    {
        GenerateInput(it);
        fstream in;
        in.open("Quick.txt");
        for(int i=0; i<it; i++)
        {
            in>>arr[i];
        }
        in.close();
        cnt=0;
        qs(0,it-1);
        cout<<"Number of operation for "<<it<<" input "<<cnt<<endl;
        in.close();
        in.clear();
    }
}

