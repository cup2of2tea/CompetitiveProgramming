#include <bits/stdc++.h>
 
 
using namespace std;
 
 
 
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<string> grid(n);
    vector<int> res(m);
    for(int c=0;c<n;c++)
    {
        cin>>grid[c];
        for(int c2=0;c2<grid[c].size();c2++)
        {
            if(grid[c][c2] != '.')
            {
                if(grid[c][c2]=='U') {if(c%2==0) res[c2]++;}
                if(grid[c][c2]=='D') continue;
                if(grid[c][c2]=='R') {if(c2+c<m) res[c2+c]++;}
                if(grid[c][c2]=='L') {if(c2-c>=0) res[c2-c]++;}
            }
        }
    }
    copy(res.begin(),res.end(),ostream_iterator<int>(cout," "));
}