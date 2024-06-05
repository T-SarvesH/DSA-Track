#include<iostream>
#include<stdio.h>

using namespace std;


int main(int argc, char const *argv[])
{
    int amount;
    cin>>amount;

    int t = 1;

    switch(t)
    {

        case 1:
        {
            int n100 = amount/100;
            cout<<"No of 100 Rs notes would be: "<< n100<<endl;
            amount = amount - n100*100;
            if(amount==0)
            exit(0);
        }
        

        case 2:
        {
            int n50 = amount/50;
            cout<<"No of 50 Rs notes would be: "<< n50<<endl;
            amount = amount - n50*50;
            if(amount==0)
            exit(0);
        }
        

        case 3:
        {
            int n20 = amount/20;
            cout<<"No of 20 Rs notes would be: "<< n20<<endl;
            amount = amount - n20*20;
            if(amount==0)
            exit(0);
        }
        

        case 4:
        {
            int n10 = amount/10;
            cout<<"No of 10 Rs notes would be: "<< n10<<endl;
            amount = amount - n10*10;
            if(amount==0)
            exit(0);
        }
        

        case 5:
        {
            int n1 = amount/1;
            cout<<"No of 1 Rs notes would be: "<< n1<<endl;
            amount = amount - n1*1;
            if(amount==0)
            exit(0);
        }

    }
    return 0;
}
