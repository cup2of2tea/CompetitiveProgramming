#include <iostream>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    int act = 0;
    int res = 0;
    for(int c=0;c<n;c++)
    {
        int z;
        cin>>z;
        if(z>0) act+=z;
        else if(act!=0){act--;}
        else res++;
    }
    cout<<res;
}