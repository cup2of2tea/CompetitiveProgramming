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
    int m,t,r;
    cin>>m>>t>>r;
    int res = 0;
    vector<bool> light(610,false);
    for(int c=0;c<m;c++)
    {
        int w;
        cin>>w;
        w+=301;
        int rtmp=r;
        for(int c=1+w-t;c<=w;c++) if(light[c]) rtmp--;
        for(int c=w;rtmp>0&&c>w-t;c--)
        {
            if(light[c]) continue;
            light[c]=true;
            rtmp--;
            res++;
        }
        if(rtmp>0)
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<res;
}