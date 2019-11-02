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
#include <queue>
#include <climits>
#include <iomanip>
#include <iterator>
#include <stack>
#define LOCAL
#ifdef ONLINE_JUDGE
#undef LOCAL
#endif
#ifdef LOCAL
#define cin in
#define COUT(s) cout<<"----"<<s<<"----"<<endl
#endif
#ifndef LOCAL
#define COUT(s);
#endif
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
 
using namespace std;
 
 
int main()
{
#ifdef LOCAL
    ifstream cin("input.txt");
#endif
    int n;
    int m;
    cin>>n>>m;
    long long res=0;
    for(int c=0;c<n;c++)
    {
        long long int t,T,x,cost;
        cin>>t>>T>>x>>cost;
        if(T<=t)
        {
            res+=(cost+x*m);
        }
        else
        {
            long long int min_car_tous_contents=m/(T-t)+(m%(T-t)==0?0:1);
            res+=min(cost+x*m,min_car_tous_contents*cost);
        }
        /*
        long long int mini=-1;
        for(long long int car=1;mini==-1||(car*cost<mini);car++)
        {
            long long cost_tot=cost*car;
            long long int m2=m;
            m2-=(car-1)*(T-t);
            m2=max((long long)0,m2);
            if(m2+t>T)
                cost_tot+=x*m2;
            if(mini==-1)
                mini=cost_tot;
            else
                mini=min(mini,cost_tot);
        }*/
        //res+=mini;
    }
    cout<<res;
}