#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <istream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <list>
#include <cstdio>
#include <set>
#include <iomanip>
#include <stack>
#include <ctime>
#include <climits>
#include <iterator>
 
#define LOCAL
#ifdef ONLINE_JUDGE
#define COUT(s)
#undef LOCAL
#endif
 
#ifdef LOCAL
#define cin in
 
#define COUT(s) cout<<"-----"<<s<<"-----"<<endl;
#endif
 
using namespace std;
 
 
 int BitCount(unsigned int u)
 {
         unsigned int uCount;
 
         uCount = u
                  - ((u >> 1) & 033333333333)
                  - ((u >> 2) & 011111111111);
         return
           ((uCount + (uCount >> 3))
            & 030707070707) % 63;
 }
 
 
int main(int argc,char **argv)
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
    int n;
    cin>>n;
    vector<vector<int> > v(4);
    for(int c=0;c<n;c++)
    {
        int z;
        cin>>z;
        if(z<1)
            v[0].push_back(z);
        else if(z<10)
            v[1].push_back(z);
        else if(z<100)
            v[2].push_back(z);
        else
            v[3].push_back(z);
 
    }
    for(int c=0;c<4;c++)
        sort(v[c].begin(),v[c].end());
    int res=0;
    vector<int> resultat;
    for(int c=0;c<(1<<4);c++)
    {
        vector<int> temp;
        for(int c2=0;c2<4;c2++)
        {
            if((1<<c2)&c)
            {
                for(int c3=0;c3<v[c2].size();c3++)
                {
                    int actuel=v[c2][c3];
                    for(int c4=1;c4<4;c4++,actuel/=10)
                    {
                        if(c4==c2)
                            continue;
                        if(actuel%10!=0&&((1<<c4)&c))
                            goto nop;
                    }
                    temp.push_back(v[c2][c3]);
                    break;
                    nop:;
                }
            }
        }        int bc=BitCount(c);
 
        if(temp.size()==bc&&res<bc)
        {
            res=bc;
            resultat.resize(temp.size());
            copy(temp.begin(),temp.end(),resultat.begin());
        }
    }
    cout<<res<<endl;
    for(int c=0;c<resultat.size();c++)
        cout<<resultat[c]<<" ";
}