#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <ctime>
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
    int n;
    cin>>n;
    vector<int > v(n);
    for(int c=0;c<n;c++) {cin>>v[c];}
    sort(v.rbegin(),v.rend());
    int T;
    cin>>T;
    int i = 0, j = 0;
    int res = 0;
    for(;i<n;i++)
    {
        while(j<n&&v[i]-v[j]<=T) j++;
        j--;
        res=max(res,j-i+1);
    }
    cout<<res;
}