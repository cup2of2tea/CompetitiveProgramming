#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    #define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int c=0;c<n;c++)
    {
        cin>>v[c];
    }
    sort(v.begin(),v.end());
    vector<int> v2(m);
    for(int c=0;c<m;c++)
    {
        cin>>v2[c];
    }
    sort(v2.begin(),v2.end());
    int one = 0, two = 0;
    while(one < m && two < n)
    {
        if(v2[one] >= v[two])
        {
            two++;
        }
        one++;
    }
    cout<<n-two<<endl;
}