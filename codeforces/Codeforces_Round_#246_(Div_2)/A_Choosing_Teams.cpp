#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int c=0;c<n;c++) cin>>v[c];
    sort(v.begin(),v.end());
    int c;
    for(c=0;c<v.size()&&v[c]+k<=5;c++);
    cout<<c/3;
}