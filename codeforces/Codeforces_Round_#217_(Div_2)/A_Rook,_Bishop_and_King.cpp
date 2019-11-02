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
 
int bfsfou(int r1,int c1,int r2,int c2)
{
    queue<pair<pair<int,int>,int>  > to_do;
    to_do.push(make_pair(make_pair(r1,c1),0));
    int dx[4]={-1,-1,1,1};
    int dy[4]={1,-1,1,-1};
    vector<vector<bool> > visites(10,vector<bool>(10));
    visites[r1][c1]=true;
    while(to_do.size()!=0)
    {
        int x=to_do.front().first.first;
        int y=to_do.front().first.second;
        int cost=to_do.front().second;
        if(x==r2&&y==c2)
        {
            return cost;
        }
        to_do.pop();
        for(int c=0;c<4;c++)
        {
            for(int c2=1;c2<=10;c2++)
            {
                int x2=x+dx[c]*c2;
                int y2=y+dy[c]*c2;
                if(x2>=1&&y2>=1&&x2<=8&&y2<=8&&!visites[x2][y2])
                {
                    visites[x2][y2]=true;
                    to_do.push(make_pair(make_pair(x2,y2),cost+1));
                }
            }
        }
    }
    return 0;
}
 
int bfsroi(int r1,int c1,int r2,int c2)
{
    queue<pair<pair<int,int>,int>  > to_do;
    to_do.push(make_pair(make_pair(r1,c1),0));
    int dx[8]={1,1,1,0,0,-1,-1,-1};
    int dy[8]={1,0,-1,1,-1,1,0,-1};
    vector<vector<bool> > visites(10,vector<bool>(10));
    visites[r1][c1]=true;
    while(to_do.size()!=0)
    {
        int x=to_do.front().first.first;
        int y=to_do.front().first.second;
        int cost=to_do.front().second;
        if(x==r2&&y==c2)
        {
            return cost;
        }
        to_do.pop();
        for(int c=0;c<8;c++)
        {
                int x2=x+dx[c];
                int y2=y+dy[c];
                if(x2>=1&&y2>=1&&x2<=8&&y2<=8&&!visites[x2][y2])
                {
                    visites[x2][y2]=true;
                    to_do.push(make_pair(make_pair(x2,y2),cost+1));
                }
        }
    }
    return 0;
}
 
 
int main()
{
 
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    #define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    cout<<(r1!=r2?1:0)+(c1!=c2?1:0)<<" "<<bfsfou(r1,c1,r2,c2)<<" "<<bfsroi(r1,c1,r2,c2)<<endl;
}
 