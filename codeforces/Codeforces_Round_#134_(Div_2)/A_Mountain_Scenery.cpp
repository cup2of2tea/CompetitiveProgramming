#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstdio>
#include <set>
#include <ctime>
#include <queue>
#include <climits>
#include <iomanip>
#include <limits>
#include <iterator>
#include <stack>
#define LOCAL
#ifdef ONLINE_JUDGE
#undef LOCAL
#endif
#ifdef LOCAL
#define cin in
#define COUT(s) cout<<"----"<<s<<"----"<<endl
#endif
#ifndef LOCAL
#define COUT(s);
#endif
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
 
using namespace std;
 
const long long INFLL=numeric_limits<long long int>::max();
const int INF=numeric_limits<int>::max();
 
 
int main()
{
#ifdef LOCAL
    ifstream cin("input.txt");
#endif
    int n,k;
    cin>>n>>k;
    int nb_peaks=n*2+1;
    vector<int> v(nb_peaks);
    for(int c=0;c<nb_peaks;c++)
        cin>>v[c];
    for(int c=1;c<nb_peaks&&k>0;c+=2)
    {
        int z=v[c]-1;
        if(z>v[c-1]&&z>v[c+1]){k--;
            v[c]--;}
    }
    for(int c=0;c<nb_peaks;c++)
        cout<<v[c]<<" ";
}