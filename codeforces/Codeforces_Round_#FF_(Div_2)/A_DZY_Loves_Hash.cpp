#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main()
{
    int p,n;
    cin>>p>>n;
    vector<bool> used(p,false);
    for(int c=0;c<n;c++)
    {
        int z;
        cin>>z;
        if(used[z%p])
        {
            cout<<c+1;
            return 0;
        }
        used[z%p]=true;
    }
    cout<<-1;
   return 0;
}