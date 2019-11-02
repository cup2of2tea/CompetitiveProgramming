#include <iostream>
using namespace std;
 
int main()
{
    int a;
    cin>>a;
    while(a!=1)
    {
        cout<<a<<" ";
        int c;
        for(c=a-1;c>1;c--)
            if(a%c==0)
                break;
        a=c;
    }
    cout<<1;
}