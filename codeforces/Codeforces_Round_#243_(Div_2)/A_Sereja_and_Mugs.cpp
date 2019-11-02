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
    int n,s;
    cin>>n>>s;
    vector<int> v(n);
    int res = 0;
    for(int c=0;c<v.size();c++) {cin>>v[c];res+=v[c];}
    res -= (*max_element(v.begin(),v.end()));
    if(res > s) cout<<"NO";
    else cout<<"YES";
}