#include<iostream>
#include<stdlib.h>

using namespace std;

int main(int argc, char const *argv[])
{
    while (1)
    {
        int trash;
        cin>>trash;

        switch(trash){

            case 1:
            trash++;
            break;

            default:
            exit(0);
        }
    }
    
    return 0;
}
