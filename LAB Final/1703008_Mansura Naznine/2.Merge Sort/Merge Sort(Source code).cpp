/// Merge Sort
/// Author: 1703008_Mansura Naznine

#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

int StepCnt=0;

void GenerateInput()
{
    fstream in;
    int a=7621;
    int b=37;
    int mod=10007;
    in.open("merge.txt");
    for(int i=0; i<18000; i++)
    {
        in<<((i*a)%mod)+b<<endl;
    }
}
void Merge(int myarray[], int left, int mid, int right)
{
    StepCnt+=3;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int LeftArray[n1+5], RightArray[n2+5];
    for (int i = 0; i < n1; i++)
    {
        StepCnt+=1;
        LeftArray[i] = myarray[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        StepCnt+=1;
        RightArray[j] = myarray[mid + 1 + j];
    }
    StepCnt+=3;
    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        StepCnt+=2;
        if (LeftArray[i] <= RightArray[j])
        {
            StepCnt+=2;
            myarray[k] = LeftArray[i];
            i++;
        }
        else
        {
            StepCnt+=3;
            myarray[k] = RightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        StepCnt+=3;
        myarray[k] = LeftArray[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        StepCnt+=3;
        myarray[k] = RightArray[j];
        j++;
        k++;
    }
}

void MergeSort(int myarray[],int left,int right)
{
    StepCnt+=1;
    if(left>=right)
    {
        StepCnt+=1;
        return;
    }
    StepCnt+=4;
    int mid = (left+right-1)/2;
    MergeSort(myarray,left,mid);
    MergeSort(myarray,mid+1,right);
    Merge(myarray,left,mid,right);
}

int main()
{
    GenerateInput();
    for(int i=2000; i<=6000; i+=1000)
    {
        auto start = high_resolution_clock::now();
        fstream in;
        in.open("merge.txt");
        int myarray[9000];
        StepCnt=0;
        for(int j=0; j<i; j++)
            in>>myarray[j];
        in.close();

        MergeSort(myarray, 0, i - 1);

        StepCnt+=1;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "For "<<i<<" number time taken by Quick Sort function: "<< duration.count() << " microseconds" << endl;
        cout << "For "<<i<<" number number of steps: "<<StepCnt << endl;
        fstream out;
        out.open("AfterMergeSort.txt");
        out<<"After Merge Sort the array is:\n";
        for(int j=0; j<i; j++)
        {
            out<<myarray[j]<<endl;
        }
        cout<<endl;
    }
}
