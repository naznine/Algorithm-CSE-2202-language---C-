#include<bits/stdc++.h>
using namespace std;
#include<fstream>
int arr[100000];
int cnt;

void GenerateInput()
{
    fstream in1,in2,in3,in4,in5,in6,in7,in8,in9,in10;
    in1.open("Quick1.txt");
    for(int i=0;i<4000;i++)
    {
        in1<<rand()<<endl;
    }
    in1.close();

    in2.open("Quick2.txt");
    for(int i=0;i<4500;i++)
    {
        in2<<rand()<<endl;
    }
    in2.close();

    in3.open("Quick3.txt");
    for(int i=0;i<5000;i++)
    {
        in3<<rand()<<endl;
    }
    in3.close();

    in4.open("Quick4.txt");
    for(int i=0;i<5500;i++)
    {
        in4<<rand()<<endl;
    }
    in4.close();

    in5.open("Quick5.txt");
    for(int i=0;i<6000;i++)
    {
        in5<<rand()<<endl;
    }
    in5.close();

    in6.open("Quick6.txt");
    for(int i=0;i<6500;i++)
    {
        in6<<rand()<<endl;
    }
    in6.close();

    in7.open("Quick7.txt");
    for(int i=0;i<7000;i++)
    {
        in7<<rand()<<endl;
    }
    in7.close();

    in8.open("Quick8.txt");
    for(int i=0;i<7500;i++)
    {
        in8<<rand()<<endl;
    }
    in8.close();

    in9.open("Quick9.txt");
    for(int i=0;i<8000;i++)
    {
        in9<<rand()<<endl;
    }
    in9.close();

    in10.open("Quick10.txt");
    for(int i=0;i<8500;i++)
    {
        in10<<rand()<<endl;
    }
    in10.close();
}

int partision(int l,int h)
{
    cnt=cnt+1;
    int pivot=arr[h],tm;
    int i=l-1;
    for(int j=l;j<=h-1;j++)
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
    GenerateInput();
    fstream in1,in2,in3,in4,in5,in6,in7,in8,in9,in10;
    in1.open("Quick1.txt");
    for(int i=0;i<4000;i++)
    {
        in1>>arr[i];
    }
    in1.close();
    cnt=0;
    qs(0,4000-1);
    cout<<"Number of operation for 4000 input "<<cnt<<endl;

    ofstream out1("Quick1OUT.txt");
    for(int i=0;i<4000;i++)
    {
        out1<<arr[i]<<endl;
    }
    out1.close();

    in2.open("Quick2.txt");
    for(int i=0;i<4500;i++)
    {
        in2>>arr[i];
    }
    in2.close();
    cnt=0;
    qs(0,4500-1);
    cout<<"Number of operation for 4500 input "<<cnt<<endl;

    ofstream out2("Quick2OUT.txt");
    for(int i=0;i<4500;i++)
    {
        out2<<arr[i]<<endl;
    }
    out2.close();

    in3.open("Quick3.txt");
    for(int i=0;i<5000;i++)
    {
        in3>>arr[i];
    }
    in3.close();
    cnt=0;
    qs(0,5000-1);
    cout<<"Number of operation for 5000 input "<<cnt<<endl;

    ofstream out3("Quick3OUT.txt");
    for(int i=0;i<5000;i++)
    {
        out3<<arr[i]<<endl;
    }
    out3.close();

    in4.open("Quick4.txt");
    for(int i=0;i<5500;i++)
    {
        in4>>arr[i];
    }
    in4.close();
    cnt=0;
    qs(0,5500-1);
    cout<<"Number of operation for 5500 input "<<cnt<<endl;

    ofstream out4("Quick4OUT.txt");
    for(int i=0;i<5500;i++)
    {
        out4<<arr[i]<<endl;
    }
    out4.close();

    in5.open("Quick5.txt");
    for(int i=0;i<6000;i++)
    {
        in5>>arr[i];
    }
    in5.close();
    cnt=0;
    qs(0,6000-1);
    cout<<"Number of operation for 6000 input "<<cnt<<endl;

    ofstream out5("Quick5OUT.txt");
    for(int i=0;i<6000;i++)
    {
        out5<<arr[i]<<endl;
    }
    out5.close();

    in6.open("Quick6.txt");
    for(int i=0;i<6500;i++)
    {
        in6>>arr[i];
    }
    in6.close();
    cnt=0;
    qs(0,6500-1);
    cout<<"Number of operation for 6500 input "<<cnt<<endl;

    ofstream out6("Quick6OUT.txt");
    for(int i=0;i<6500;i++)
    {
        out1<<arr[i]<<endl;
    }
    out6.close();

    in7.open("Quick7.txt");
    for(int i=0;i<7000;i++)
    {
        in7>>arr[i];
    }
    in7.close();
    cnt=0;
    qs(0,7000-1);
    cout<<"Number of operation for 7000 input "<<cnt<<endl;

    ofstream out7("Quick7OUT.txt");
    for(int i=0;i<7000;i++)
    {
        out7<<arr[i]<<endl;
    }
    out7.close();

    in8.open("Quick8.txt");
    for(int i=0;i<7500;i++)
    {
        in8>>arr[i];
    }
    in8.close();
    cnt=0;
    qs(0,7500-1);
    cout<<"Number of operation for 7500 input "<<cnt<<endl;

    ofstream out8("Quick8OUT.txt");
    for(int i=0;i<7500;i++)
    {
        out8<<arr[i]<<endl;
    }
    out8.close();

    in9.open("Quick9.txt");
    for(int i=0;i<8000;i++)
    {
        in9>>arr[i];
    }
    in9.close();
    cnt=0;
    qs(0,8000-1);
    cout<<"Number of operation for 8000 input "<<cnt<<endl;

    ofstream out9("Quick9OUT.txt");
    for(int i=0;i<8000;i++)
    {
        out9<<arr[i]<<endl;
    }
    out9.close();

    in10.open("Quick10.txt");
    for(int i=0;i<8500;i++)
    {
        in10>>arr[i];
    }
    in10.close();
    cnt=0;
    qs(0,8500-1);
    cout<<"Number of operation for 8500 input "<<cnt<<endl;

    ofstream out10("Quick10OUT.txt");
    for(int i=0;i<8500;i++)
    {
        out10<<arr[i]<<endl;
    }
    out10.close();
}
