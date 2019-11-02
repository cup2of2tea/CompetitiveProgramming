#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int me;
    cin>>me;
    n--;
    vector<int> v(n);
    for(int c=0;c<n;c++) cin>>v[c];
    sort(v.rbegin(),v.rend());
    int i = 0;
    int res = 0;
    while(v[i] >= me){
        v[i]--;
        me++;
        res++;
        if(i+1<n && v[i] < v[i+1]){
            i = i + 1;
        }
        else if(v[i] < v[0]){
            i = 0;
        } 
    }
    cout<<res;
}