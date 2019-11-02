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
    for(int c=0;c<N;c++)
    {
        string s;
        cin>>s;
        vector<int> res;
        for(int c2=1;c2<=12;c2++)
        {
            if(12%c2!=0) continue;
            vector<string> v(c2);
            for(int c3=0;c3<c2;c3++)
            {
                v[c3]=s.substr(c3*(12/c2),12/c2);
            }
            bool ok = false;
            for(int c3=0;c3<12/c2;c3++)
            {
                for(int c4=0;c4<c2;c4++)
                {
                    if(v[c4][c3]!='X')
                    {
                        goto nop;
                    }
                }
                ok = true;
                nop:;
            }
            if(ok)
            res.push_back(c2);
        }
        cout<<res.size()<<" ";
        for(int c2=0;c2<res.size();c2++) cout<<res[c2]<<"x"<<12/res[c2]<<" ";
        cout<<endl;
    }
}