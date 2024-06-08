#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

void powerOf2(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <= 30; j++)
        {
           if(array[i]/pow(2,j)==1)
           {
                cout<<"Power of 2"<<endl; 
                break;
           }
           
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    int size;
    cin>>size;

    int array[100];
    for(int i=0; i<size; i++)
    {
        cin>>array[i];
    }
    
    powerOf2(array, size);

    return 0;
}
