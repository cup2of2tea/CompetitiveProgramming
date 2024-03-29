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
    vector<long long int> v(n);
    for(int c=0;c<n;c++) cin>>v[c];
    sort(v.begin(),v.end());
    long long res = 0;
    if(n==1)
    {
        cout<<v[0]<<endl;
        return 0;
    }
 
    for(int c=0;c<n;c++)
    {
        res+=v[c]*min(n,c+2);
    }
    cout<<res;
}