#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
 
const double pi=3.14159265;
 
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int c=0;c<n;c++)
        cin>>v[c];
    sort(v.begin(),v.end());
    bool truc=true;
    double tot=0;
    for(int c=v.size()-1;c>=0;c--)
    {
        if(truc)
            tot+=(v[c]*v[c]);
        else
            tot-=(v[c]*v[c]);
        truc=(!truc);
    }
    cout<<fixed<<setprecision(8)<<tot*pi;
}