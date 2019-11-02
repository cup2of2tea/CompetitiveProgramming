#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
 
using namespace std;
 
 
int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    #define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
 
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<bool> > blacks(n,vector<bool>(m,false));
    int dx[4][4]={{0,0,1,1},{0,0,-1,-1},{0,0,1,1},{0,0,-1,-1}};
    int dy[4][4]={{0,1,1,0},{0,1,0,1},{0,-1,0,-1},{0,-1,0,-1}};
 
    for(int c=0;c<k;c++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        blacks[x][y]=true;
        for(int c2=0;c2<4;c2++)
        {
            for(int c3=0;c3<4;c3++)
            {
                int x2 = x+dx[c2][c3];
                int y2 = y+dy[c2][c3];
                if(x2<0||y2<0||x2>=n||y2>=m||!blacks[x2][y2]) goto nop;
            }
            cout<<c+1<<endl;
            return 0;
            nop:;
        }
    }
    cout<<0;
 
}