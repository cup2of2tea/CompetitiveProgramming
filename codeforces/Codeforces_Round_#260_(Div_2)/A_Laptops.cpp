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
    for(int c=0;c<n;c++) cin>>v[c].first>>v[c].second;
    sort(v.begin(),v.end());
    for(int c=1;c<n;c++)
    {
        if(v[c-1].first < v[c].first && v[c-1].second > v[c].second)
        {
            cout<<"Happy Alex";
            return 0;
        }
    }
    cout<<"Poor Alex";
}