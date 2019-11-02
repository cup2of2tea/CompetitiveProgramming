#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> v(m);
    for(int c=0;c<m;c++)
    {
        cin>>v[c];
    }
    int player;
    cin>>player;
    int res=0;
    for(int c=0;c<m;c++)
    {
        int diff = 0;
        for(int c2=0;c2<n;c2++)
        {
            if(((1<<c2)&player)!= ((1<<c2)&v[c]))
                diff++;
        }
        if(diff<=k)
        {
            res++;
        }
    }
    cout<<res;
}