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
    int n,ca;
    cin>>n>>ca;
    vector<int> v(n);
    for(int c=0;c<n;c++) cin>>v[c];
    int res = 0;
    for(int c=0;c<n-1;c++)
    {
        res=max(v[c]-(v[c+1]+ca),res);
    }
    cout<<res;
}