#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstdio>
#include <set>
 
 
#ifdef LOCAL
#define cin in
#endif
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    vector<long long> v(n);
    long long int tot=0;
    for(int c=0;c<n;c++)
    {
        cin>>v[c];
        tot+=v[c];
    }
    if(tot%n!=0){cout<<0;return 0;}
    vector<long long int> res;
    for(int c=0;c<n;c++)
    {
        if(v[c]==tot/n)
        {
            res.push_back(c+1);
        }
    }
    cout<<res.size()<<endl;
    for(int c=0;c<res.size();c++)
        cout<<res[c]<<" ";
 
}