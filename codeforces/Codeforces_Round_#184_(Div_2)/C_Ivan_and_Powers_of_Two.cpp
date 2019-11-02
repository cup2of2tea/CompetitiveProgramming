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
 
 
 
 
 
int main(int argc,char **argv)
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
    int n;
    cin>>n;
    map<long long,int> m;
    for(int c=0;c<n;c++)
    {
        long long int z;
        cin>>z;
        m[z]++;
    }
    for(map<long long,int>::iterator it=m.begin();it!=m.end();it++)
    {
        long long int z=it->first;
        if(m[z]>1)
        {
            long long int pow_2=1;
            int i=0;
            while(pow_2<=m[z])
                pow_2*=2,i++;
            pow_2/=2;
            i--;
            while(m[z]>1)
            {
                if(pow_2&m[z])
                {
                    m[z+i]++;
                    m[z]%=pow_2;
                }
                pow_2/=2;
                i--;
            }
        }
    }
    long long int previous=-1;
    long long int res=0;
    for(map<long long,int>::iterator it=m.begin();it!=m.end();it++)
    {
        if(it->second>0)
        {
            res+=((it->first)-previous)-1;
            previous=it->first;
        }
    }
    cout<<res;
}