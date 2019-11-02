#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
 
using namespace std;
 
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> > v(n);
    vector<int> res(n);
    for(int c=0;c<n;c++)
    {
        v[c].second = c;
        cin>>v[c].first;
    }
    sort(v.begin(),v.end());
    for(int c=0;c<v.size();c++) res[v[c].second]=c%2;
    copy(res.begin(),res.end(),ostream_iterator<int>(cout," "));
}