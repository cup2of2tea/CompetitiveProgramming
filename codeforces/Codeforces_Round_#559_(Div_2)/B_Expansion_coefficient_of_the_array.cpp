#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
    int N;
    cin>>N;
    vector<long long> v(N);
    for(int c=0;c<N;c++) cin>>v[c];
 
    long long mini = 1e15;
    for(int c=0;c<N;c++) {
        long long act = v[c];
        if(c>0)
            mini = min(mini, act / c);
        if(c+1<N)
            mini = min(mini, act/(N-1-c));
    }
    cout<<mini;
}