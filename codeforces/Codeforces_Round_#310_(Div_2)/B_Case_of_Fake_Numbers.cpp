#include <bits/stdc++.h>
using namespace std;
 
int main()
{
#ifndef ONLINE_JUDGE
    #define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int n;
    cin>>n;
    vector<int> gears(n);
    for(int c=0;c<n;c++)
    {
        cin>>gears[c];
    }
    for(int c=0;c<n;c++)
    {
        for(int c2=0;c2<n;c2++)
        {
            if(gears[c2]!=c2) goto nop;
        }
        cout<<"Yes";
        return 0;
        nop:
        for(int c2=0;c2<n;c2++)
        {
            if(c2%2==0) gears[c2]++;
            else gears[c2]--;
            gears[c2]+=n;
            gears[c2]%=n;
        }
    }
    cout<<"No";
}