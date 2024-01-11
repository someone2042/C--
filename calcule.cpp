#include<iostream>
#include <cmath>

using namespace std;
// unsigned long int power(int n,int p)
// {
//     unsigned long int sum=1;
//     for(int i=0;i<p;i++)
//     {
//         sum=sum*n;
//     }
//     return sum;
// }
int main(void)
{
    int t[64]={1,1,0,1,0,0,0,1,0,0,1,0,1,1,0,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0,0,0,1,1,0,1,0,0,1,0,0,0,0,1,0,0,0,0,1,1,0,1,0,0,1,0,0,0,1,0,0,1,0,0};
    int sum=0;

    for(int i=0;i<64;i++)
    {
        sum+=t[i]*i;
    }
    cout<<sum;
    cout<<'\n';
    cout<<sum%64;
}