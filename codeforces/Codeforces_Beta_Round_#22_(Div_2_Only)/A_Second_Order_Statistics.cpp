#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    set<int> s;
    int n;
    cin>>n;
    for(int c=0;c<n;c++){int a;cin>>a;s.insert(a);}
    vector<int> v;
    for(set<int>::iterator it=s.begin();it!=s.end();it++)
        v.push_back((*it));
    sort(v.begin(),v.end());
    if(v.size()>=2)
        cout<<v[1];
    else cout<<"NO";
}