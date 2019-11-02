#include <iostream>
#include <map>
#include <vector>
#include <fstream>
using namespace std;
 
int main()
{
    int n,m,MOD;
    cin>>n>>m>>MOD;
    vector<int> v1(n);
    vector<int> v2(m);
    for(int c=0;c<n;c++)
        cin>>v1[c];
    for(int c2=0;c2<m;c2++)
        cin>>v2[c2];
    for(int c=0;c<=n-m;c++)
    {
        for(int c2=0;c2<m;c2++)
        {
            v1[c+c2]=(v1[c+c2]+v2[c2])%MOD;
        }
    }
    for(int c=0;c<n;c++)
        cout<<v1[c]<<" ";
}
 