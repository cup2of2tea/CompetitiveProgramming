#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    long long a,b,w,x,c;
    long long res = 0;
    cin>>a>>b>>w>>x>>c;
    vector<pair<long long,long long> > cycles(1001,make_pair(-1,-1));
    while(c>a)
    {
        if(b<1001&&cycles[b].first!=-1)
        {
            long long longueur = res-cycles[b].first;
            long long diffa = cycles[b].second-a;
            if(diffa+longueur!=0)
            {
                long long x = (c-a)/(longueur+diffa);
                if(x!=0)
                {
                    res+=x*longueur;
                    c-=x*longueur;
                    a-=x*diffa;
                    continue;
                }
 
            }
        }
         if(b<1001)
        {
            cycles[b] = make_pair(res,a);
        }
         if(b<x)
        {
            res++;
            a--;
            b=w-(x-b);
            c--;
        }
        else
        {
            int to_add = min(c-a,b/x);
            res+=to_add;
            c-=to_add;
            b%=x;
        }
 
    }
    cout<<res;
}