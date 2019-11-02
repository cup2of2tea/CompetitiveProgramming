#include <iostream>
using namespace std;
 
int main()
{
    int n;
    int act=0;
    int maxi=0;
    cin>>n;
    for(int c=0;c<n;c++)
    {
        int a,b;
        cin>>a>>b;
        act=act+b-a;
        if(act>maxi)
            maxi=act;
    }
    cout<<maxi;
}