#include <iostream>
#include <cmath>
using namespace std;
 
int main()
{
    long long int a,b,a2=0,b2=0;
    cin>>a>>b;
    long long int total=a+b,total2=0;
    int c=0;
    while(a!=0)
    {
        if(a%10!=0)
        {
            a2+=(a%10)*(int)pow((float)10,c);
            c++;
        }
        a/=10;
    }
    c=0;
     while(b!=0)
    {
        if(b%10!=0)
        {
            b2+=(b%10)*(int)pow((float)10,c);
            c++;
        }
        b/=10;
    }
    c=0;
     while(total!=0)
     {
        if(total%10!=0)
        {
            total2+=(total%10)*(int)pow((float)10,c);
            c++;
        }
        total/=10;
     }
    if(a2+b2==total2)
        cout<<"YES";
    else
        cout<<"NO";
}