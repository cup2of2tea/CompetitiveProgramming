#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int x,k;
    cin>>x>>k;
    vector<pair<int,int> > v(k);
    v.push_back(make_pair(x,x));
    v.push_back(make_pair(0,0));
    for(int c=0;c<k;c++)
    {
        int id;
        cin>>id;
        if(id==2)
        {
            cin>>v[c].first;
            v[c].second=v[c].first;
        }
        else cin>>v[c].first>>v[c].second;
    }
    sort(v.begin(),v.end());
    int mini=0,maxi=0;
    for(int c=1;c<v.size();c++)
    {
        int diff = v[c].first-v[c-1].second;
        mini+=(diff)/2;
        maxi+=diff-1;
    }
    cout<<mini<<" "<<maxi;
}