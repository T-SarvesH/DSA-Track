#include<iostream>
#include<math.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;

    while (n>=0)
    cin>>n;

    n = -1*n;
    int answer = 0;
    int i = 0;
    while (n!=0)
    {
        int bit = n&1;
        answer = answer + (bit*pow(10, i));
        i++;
        n = n>>1;
    }

    answer = (~answer)+1;
    cout<<answer;
    
    
    return 0;
}
