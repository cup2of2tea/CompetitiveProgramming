#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main()
{
    vector<int> v(4);
    cin>>v[0]>>v[1]>>v[2]>>v[3];
    sort(v.begin(),v.end());
    if(v[0]+v[1]>v[2]||v[1]+v[2]>v[3])
        cout<<"TRIANGLE";
    else if(v[0]+v[1]==v[2]||v[1]+v[2]==v[3])
        cout<<"SEGMENT";
    else
        cout<<"IMPOSSIBLE";
}