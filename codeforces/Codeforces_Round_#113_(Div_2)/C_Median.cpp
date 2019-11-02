#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
 
int main()
{
        int n,x;
    cin>>n>>x;
    vector<int> v(n);
    bool present=false;
    for(int c=0;c<n;c++)
    {
        cin>>v[c];
    if(x==v[c]) present=true;
    }    
    int res=0;
    if(!present) {v.push_back(x); res++;}
    sort(v.begin(),v.end());
    if(v[v.size()/2]>x)
    {
        reverse(v.begin(),v.end());
    while(v[(v.size())/2]!=x)
    {
        v.push_back(x);
        res++;
    }       cout<<res; 
    return 0;
   }
    while(v[(v.size()-1)/2]!=x)
    {
        v.push_back(x);
        res++;
    }       cout<<res;  
} 
 
 