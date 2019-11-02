#include <bits/stdc++.h>
using namespace std;
 
 
 
int main()
{
#ifndef ONLINE_JUDGE
//    #define cin in
//    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int a,n;
    cin>>n>>a;
    a--;
    vector<int> v(n);
    for(int c=0;c<n;c++) cin>>v[c];
    int res = 0;
    for(int c=1;c<n;c++) {
        int left = a-c;
        int right = a+c;
        if(left < 0 && right < n && v[right]) res++;
        if(right >= n && left >= 0 && v[left]) res++;
        if(left >= 0 & right < n && v[left] == v[right]) res+=2*v[left];
 
    }
    res+=v[a];
 
    cout<<res;
}