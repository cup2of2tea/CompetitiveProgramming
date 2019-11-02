#include <bits/stdc++.h>
using namespace std;
 
int main()
{
#ifndef ONLINE_JUDGE
    #define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int n,k;
    cin>>n>>k;
    int res = 0;
    int all = 0;
    for(int c=0;c<k;c++)
    {
        all++;
        int t;
        cin>>t;
        int prev = -1;
        cin>>prev;
        if(prev == 1)
        {
            bool ok = true;
            for(int c2=2;c2<=t;c2++)
            {
                int z;
                cin>>z;
                if(z != c2) ok = false;
                if(!ok)
                {
                    all++;
                    res++;
                }
            }
        }
        else
        {
            for(int c2=1;c2<t;c2++)
            {
                cin>>prev;
                all++;
                res++;
            }
        }
    }
    cout<<res+all-1;
}