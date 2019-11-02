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
    map<long long,long long> m;
    long long a;
    cin>>a;
    string s;
    cin>>s;
    vector<long long> sum(s.size(),0);
    sum[0]=s[0]-'0';
    for(int c=1;c<s.size();c++)
    {
        sum[c]=s[c]-'0'+sum[c-1];
    }
    for(int c=0;c<s.size();c++)
    {
        for(int c2=c;c2<s.size();c2++)
        {
            long long tmp=sum[c2]-(c==0?0:sum[c-1]);
            m[tmp]++;
        }
    }
    long long res=0;
    if(a==0)
    {
        res+=m[0]*((s.size()*(s.size()+1))/2);
    }
    for(map<long long,long long>::iterator it=m.begin();it!=m.end();it++)
    {
        if(it->first!=0&&a%it->first==0)
        {
            res+=(it->second*m[a/it->first]);
        }
    }
    cout<<res<<endl;
}