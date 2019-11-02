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
    int N;
    cin>>N;
    vector<vector<int> > v(N);
    for(int c=0;c<N;c++)
    {
        int m;
        cin>>m;
        v[c].resize(m);
        for(int c2=0;c2<m;c2++) cin>>v[c][c2];
        sort(v[c].begin(),v[c].end());
    }
    for(int c=0;c<N;c++)
    {
        for(int c2=0;c2<N;c2++)
        {
            if(c2==c) continue;
            if(v[c2].size()<=v[c].size())
            {
                int i1 = 0, i2 =0;
                while(i1<v[c].size()&&i2<v[c2].size())
                {
                    if(v[c][i1]==v[c2][i2])
                        i2++;
                    i1++;
                }
                if(i2==v[c2].size())
                {
                    cout<<"NO"<<endl;
                    goto end;
                }
            }
        }
        cout<<"YES"<<endl;
        end:;
    }
}
 