#include <bits/stdc++.h>
using namespace std;
 
int main()
{
#ifndef ONLINE_JUDGE
//    #define cin in
//    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int n,s;
    cin>>n>>s;
    vector<int> maxi(s,0);
    for(int c=0;c<n;c++) {
        int a,b;
        cin>>a>>b;
        a--;
        maxi[a] = max(maxi[a],b);
    }
    int act = 0;
    for(int c=maxi.size()-1;c>=0;c--) {
        act = max(act+1,maxi[c]+1);
    }
    cout<<act;
}