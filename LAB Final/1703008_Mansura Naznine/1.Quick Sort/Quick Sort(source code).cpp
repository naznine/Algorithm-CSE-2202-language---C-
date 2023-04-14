/// Quick Sort
/// Author: 1703008_Mansura Naznine

#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

int arr[8000];
int StepCnt=0;

void GenerateInput()
{
    fstream in;
    int a=7621;
    int b=37;
    int mod=10007;
    in.open("quick.txt");
    for(int i=0; i<18000; i++)
    {
        in<<((i*a)%mod)+b<<endl;
    }
}
int Partition(int Start,int End)
{
    StepCnt+=2;
    int pivot=arr[End];

    int prt=Start;
    int i,t;

    for(i=Start; i<End; i++)
    {
        StepCnt+=1;
        if(arr[i]<=pivot)
        {
            StepCnt+=4;
            t=arr[i];
            arr[i]=arr[prt];
            arr[prt]=t;
            prt++;
        }
    }
    StepCnt+=4;
    t=arr[End];
    arr[End]=arr[prt];
    arr[prt]=t;

    return prt;
}
void QuickSort(int Start,int End)
{
    StepCnt+=1;
    if(Start<End)
    {
        StepCnt+=3;
        int prt=Partition(Start,End);
        QuickSort(Start,prt-1);
        QuickSort(prt+1,End);
    }
}
int main()
{
    GenerateInput();
    for(int i=2000;i<=6000;i+=1000)
    {
        auto start = high_resolution_clock::now();
        fstream in;
        in.open("quick.txt");
        StepCnt=0;
        for(int j=0;j<i;j++)
            in>>arr[j];
        in.close();
        QuickSort(0,i-1);
        StepCnt+=1;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "For "<<i<<" number time taken by Quick Sort function: "<< duration.count() << " microseconds" << endl;
        cout << "For "<<i<<" number number of steps: "<<StepCnt << endl;
        fstream out;
        out.open("AfterQuickSort.txt");
        out<<"After Quick Sort the array is:\n";
        for(int j=0; j<i; j++)
        {
            out<<arr[j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
