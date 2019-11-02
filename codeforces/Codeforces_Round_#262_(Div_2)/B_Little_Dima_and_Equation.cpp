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
 
int sumDigit(int n)
{
    int res=0;
    while(n!=0)
    {
        res+=n%10;
        n/=10;
    }
    return res;
}
 
int main()
{
ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
//#define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    long long a,b,c;
    cin>>a>>b>>c;
    vector<int> res;
    if(a>1)
    {
        for(int i=1;;i++)
        {
            long long z = 1;
            for(int bla=0;bla<a;bla++) z*=i;
            long long x = (z)*b+c;
            if(x >= (long long)1e9) break;
            if(x>0&&sumDigit(x)==i)
            {
                res.push_back(x);
            }
        }
 
    }
    else
    {
        for(int i=0;i<=81;i++)
        {
            int x = b*i+c;
            if(x>0&&x<(long long)1e9&&sumDigit(x)==i) res.push_back(x);
        }
    }
    cout<<res.size()<<endl;
    for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
 
}