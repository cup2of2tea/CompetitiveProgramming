#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;
 
long long mod = 1e9+7;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    int act = 0;
    int done = 0;
    for(int c=0;c<n;c++)
    {
        cin>>v[c];
    }
    vector<bool> vis(n,false);
    int dx = 1;
    int change = 0;
    while(done != n)
    {
        if(dx == 1)
        {
            for(int c=0;c<n;c++)
            {
                if(vis[c]) continue;
                if(v[c] <= act) {
                    act++;
                    done++;
                    vis[c]=true;
                }
            }
            dx*=-1;
        }
        else {
            for(int c=n-1;c>=0;c--)
            {
                if(vis[c]) continue;
                if(v[c] <= act) {
                    act++;
                    done++;
                    vis[c]=true;
                }
            }
            dx*=-1;
        }
        if(done == n) break;
        change++;
    }
    cout<<change;
}