#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    vector<int> v(26);
    for(int c=0;c<26;c++) cin>>v[c];
    int res = 0;
    for(int c=0;c<s.size();c++)
    {
        res += v[s[c]-'a']*(c+1);
    }
    int z = (*max_element(v.begin(),v.end()));
    for(int c=0;c<k;c++)
        res+=(c+1+s.size())*z;
    cout<<res;
}