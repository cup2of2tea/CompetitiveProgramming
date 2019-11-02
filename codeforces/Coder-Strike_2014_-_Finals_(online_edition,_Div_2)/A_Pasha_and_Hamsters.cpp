#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    vector<bool> v(n,false);
    for(int c=0;c<a;c++)
    {
        int z;
        cin>>z;
        v[z-1]=true;
    }
    for(int c=0;c<n;c++) 
    {
        cout<<(v[c]?1:2)<<" ";
    }
}