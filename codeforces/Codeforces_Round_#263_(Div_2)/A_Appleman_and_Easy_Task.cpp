#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <ctime>
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
    int n;
    cin>>n;
    vector<string> v(n);
    for(int c=0;c<n;c++) cin>>v[c];
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    for(int c=0;c<n;c++)
    {
        for(int c2=0;c2<n;c2++)
        {
            int act = 0;
            for(int c3=0;c3<4;c3++)
            {
                int x2 = c+dx[c3];
                int y2 = c2+dy[c3];
                if(x2 >=0 && y2>=0&&x2<n&&y2<n&&v[x2][y2]=='o') act++;
            }
            if(act%2!=0)
            {
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
}