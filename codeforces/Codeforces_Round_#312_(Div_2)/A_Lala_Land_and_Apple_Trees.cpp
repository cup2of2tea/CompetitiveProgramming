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
    vector<int> x(n),a(n);
    vector<pair<int,int> > pos;
    vector<pair<int,int> > neg;
    for(int c=0;c<n;c++)
    {
        cin>>x[c]>>a[c];
        if(x[c] > 0) pos.push_back(make_pair(x[c],a[c]));
        else neg.push_back(make_pair(-x[c],a[c]));
    }
    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end());
    int res = 0;
    for(int c=0;c<min(max(pos.size(),neg.size()),min(pos.size(),neg.size())+1);c++)
    {
        if(c < pos.size())
            res += pos[c].second;
        if(c < neg.size())
            res += neg[c].second;
    }
    cout<<res;
}