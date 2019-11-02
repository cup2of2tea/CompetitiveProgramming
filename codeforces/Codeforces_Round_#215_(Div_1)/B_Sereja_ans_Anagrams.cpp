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
 
    int n,m,p;
    cin>>n>>m>>p;
    vector< int> a(n);
    vector< int> b(m);
    set<int> s;
    for(int c=0;c<n;c++)
    {
        cin>>a[c];
    }
    map<int,int> to_find;
    for(int c=0;c<m;c++)
    {
        cin>>b[c];
        s.insert(b[c]);
        to_find[b[c]]++;
    }
    int diff=s.size();
    vector<int> res;
    for(int c=0;c<p;c++)
    {
        int valide=0;
        map<int,int> m2;
        for(int c2=c;c2<n;c2+=p)
        {
            if(c2/p>=m)
            {
                int to_delete=a[c2-m*p];
                m2[to_delete]--;
                if(to_find[to_delete]!=0)
                {
                    if(to_find[to_delete]==m2[to_delete]+1)
                    {
                        valide--;
                    }
                    else if(m2[to_delete]==to_find[to_delete])
                    {
                        valide++;
                    }
                }
 
            }
            m2[a[c2]]++;
            if(to_find[a[c2]]!=0)
            {
                if(to_find[a[c2]]==m2[a[c2]]-1)
                {
                    valide--;
                }
                else if(m2[a[c2]]==to_find[a[c2]])
                {
                    valide++;
                }
            }
 
            if(valide==diff)
            {
                res.push_back(c2-(m-1)*p+1);
            }
        }
    }
    cout<<res.size()<<endl;
    sort(res.begin(),res.end());
    for(int c=0;c<res.size();c++)
        cout<<res[c]<<" ";
}