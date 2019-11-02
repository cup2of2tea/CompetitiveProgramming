#include <bits/stdc++.h>
using namespace std;
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    int N;
    cin>>N;
    int act = 0;
    int nact = -1;
    int res = 0;
    while(N--) {
        int z;
        cin>>z;
        if(z >= nact) {
            act++;
        } else {
            act = 1;
        }
        nact = z;
        res=max(res,act);
    }
    cout<<res;
}