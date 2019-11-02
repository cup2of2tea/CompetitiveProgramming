#include <iostream>
 
using namespace std;
 
int main()
{
    int n;
    int res=0;
    cin>>n;
    int maxi=-1,mini=100000000;
    for(int c=0;c<n;c++)
    {
        int z;
        cin>>z;
        if(z>maxi)
        {
            if(maxi!=-1)
                res++;
            maxi=z;
        }
        if(z<mini)
        {
            if(mini!=100000000)
                res++;
            mini=z;
        }
    }
    cout<<res;
}