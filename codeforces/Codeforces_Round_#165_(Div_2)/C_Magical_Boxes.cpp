#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <istream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <list>
#include <cstdio>
#include <set>
#include <iomanip>
#include <stack>
#include <ctime>
#include <climits>
#include <iterator>
#define LOCAL
#ifdef ONLINE_JUDGE
#define COUT(s)
#undef LOCAL
#endif
#ifdef LOCAL
#define cin in
#define COUT(s) cout<<"-----"<<s<<"-----"<<endl;
#endif
using namespace std;
 
 
int main(int argc,char **argv)
{
#ifdef LOCAL
    ifstream in("input.txt");
    ofstream out("output.txt");
#endif
    int nb_sizes;
    cin>>nb_sizes;
    vector<pair<long long int,long long int> > v(nb_sizes);
    long long int maxi=-1;
    for(int c=0;c<v.size();c++)
    {
        cin>>v[c].first>>v[c].second;
        maxi=max(maxi,v[c].second);
    }
    sort(v.begin(),v.end());
    long long int res=v.back().first+1;
    long long int z=4;long long y=res-1;
    for(int c=v.size()-1; c>=0; c--) {
        while(y>v[c].first&&z<maxi)
        {
            z*=4;
            y--;
        }
        while(z<v[c].second)
        {
            z*=4;
            res++;
        }
    }
    cout<<res;
 
 
}