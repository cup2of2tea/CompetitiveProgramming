#include <iostream>
#include <cmath>
using namespace std;
 
int main()
{
    int n,x;
    cin>>n>>x;
    int act = 0;
    for(int c=0;c<n;c++)
    {
        int z;
        cin>>z;
        act+=z;
    }
    cout<<((int)abs(act)+x-1)/x;
}