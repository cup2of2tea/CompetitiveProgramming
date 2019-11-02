#include <iostream>
using namespace std;
 
int main()
{
    int n,k;
    cin>>n>>k;
    int res=0;
    int z;
    for(int c=0;c<k;c++)
    {
        cin>>z;
        if(z>0)
            res++;
    }
    for(int c=k;c<n;c++)
    {
        int z2;
        cin>>z2;
        if(z2>0&&z2==z)
            res++;
     }
     cout<<res;
}