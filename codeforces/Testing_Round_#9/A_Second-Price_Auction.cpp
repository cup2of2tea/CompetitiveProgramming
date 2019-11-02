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
    vector<pair<int,int> > v(n);
    for(int c=0;c<n;c++) {cin>>v[c].first;v[c].second=c+1;}
    sort(v.rbegin(),v.rend());
    cout<<v[0].second<<" "<<v[1].first;
}