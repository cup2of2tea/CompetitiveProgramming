#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
 
using namespace std;
 
int bourrin(vector<string> &v)
{
    int maxi=0;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    for(int c=0;c<v.size();c++)
    {
        for(int c2=0;c2<v[c].size();c2++)
        {
            if(v[c][c2]=='W')
            {
                v[c][c2]=' ';
                for(int c3=0;c3<4;c3++)
                {
                    int x2=c+dx[c3];
                    int y2=c2+dy[c3];
                    if(x2>=0&&y2>=0&&x2<v.size()&&y2<v[c].size()&&v[x2][y2]=='P')
                    {
                        v[x2][y2]=' ';
                        maxi=max(1+bourrin(v),maxi);
                        v[x2][y2]='P';
                    }
                }
                maxi=max(bourrin(v),maxi);
            }
        }
    }
    return maxi;
}
 
 
int main()
{
    int n,m;
    cin>>n>>m;
    vector<string> v(n);
    for(int c=0;c<n;c++)
        cin>>v[c];
    cout<<bourrin(v);
}