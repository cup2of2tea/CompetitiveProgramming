#include <bits/stdc++.h>
using namespace std;
 
 
 
int main()
{
#ifndef ONLINE_JUDGE
//    #define cin in
//    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int n,h;
    cin>>n>>h;
    int res = 0;
    for(int c=0;c<n;c++) {
        int z;
        cin>>z;
        if(z>h)res++;
        res++;
    }
    cout<<res;
}