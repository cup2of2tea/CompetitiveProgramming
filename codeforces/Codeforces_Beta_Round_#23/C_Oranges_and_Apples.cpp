#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstdio>
#include <set>
#include <ctime>
#include <climits>
#include <iterator>
#define LOCAL
#ifdef ONLINE_JUDGE
#undef LOCAL
#endif
 
#ifdef LOCAL
#define cin in
#endif
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
 
using namespace std;
 
 
 
struct box
{
    long long int orange;
    long long int apple;
    int position;
};
 
bool comp(const box &b1,const box &b2)
{
    return b1.orange<b2.orange;
}
 
 
int main()
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
    int T;
    cin>>T;
    vector<box> v;
    for(int c=0;c<T;c++)
    {
        v.clear();
        int N;
        cin>>N;
        v.resize(2*N-1);
        long long  tot_apple=0;
        for(int c2=0;c2<v.size();c2++)
        {
            cin>>v[c2].apple>>v[c2].orange;
            v[c2].position=c2+1;
            tot_apple+=v[c2].apple;
        }
        sort(v.begin(),v.end(),comp);
        long long totapple[2]={0,0};
        for(int c2=0;c2<2;c2++)
        {
            for(int c3=c2;c3<v.size();c3+=2)
            {
                totapple[c2]+=v[c3].apple;
            }
        }
        if(totapple[0]>=totapple[1])
        {
            cout<<"YES"<<endl;
            for(int c2=0;c2<v.size();c2+=2)
                cout<<v[c2].position<<" ";
        }
        else
         {
            cout<<"YES"<<endl;
            for(int c2=1;c2<v.size();c2+=2)
                cout<<v[c2].position<<" ";
            cout<<v.back().position;
        }
        cout<<endl;
    }
}