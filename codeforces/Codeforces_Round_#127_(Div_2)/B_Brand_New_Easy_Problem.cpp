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
#include <iterator>
#include <stack>
#define LOCAL
#ifdef ONLINE_JUDGE
#undef LOCAL
#endif
 
 
 
#ifdef LOCAL
#define cin in
#endif
#define COUT(s) cout<<"----"<<s<<"----"<<endl
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
 
using namespace std;
 
 
int main()
{
#ifdef LOCAL
    ifstream cin("input.txt");
#endif
    int n;
    cin>>n;
    vector<string> v(n);
    for(int c=0;c<n;c++)
        cin>>v[c];
    vector<pair<string,int> > vcop(n);
    for(int c=0;c<n;c++)
        vcop[c]=make_pair(v[c],c);
    int p;
    cin>>p;
    vector<vector<string> > v2(p);
    for(int c=0;c<p;c++)
    {
        int z;
        cin>>z;
        v2[c].resize(z);
        for(int c2=0;c2<v2[c].size();c2++)
            cin>>v2[c][c2];
    }
    int mini=100000000;
    int indice_mini=-1;
    sort(vcop.begin(),vcop.end());
    do
    {
        int inversion=0;
        for(int c=0;c<vcop.size();c++)
            for(int c2=c+1;c2<vcop.size();c2++)
                if(vcop[c].second>vcop[c2].second)
                    inversion++;
        for(int c=0;c<v2.size();c++)
        {
            int indice=0;
            for(int c2=0;c2<vcop.size();c2++)
            {
                while(indice<v2[c].size()&&v2[c][indice]!=vcop[c2].first) indice++;
            }
            if(indice>=v2[c].size())
            {
                continue;
            }
            if(mini>inversion||(mini==inversion&&indice_mini>c))
            {
                mini=inversion;
                indice_mini=c;
            }
            break;
        }
    }while(next_permutation(vcop.begin(),vcop.end()));
    if(indice_mini==-1)
    {
        cout<<"Brand new problem!";
        return 0;
    }
    else
    {
        cout<<indice_mini+1<<endl;
        cout<<"[:";
        for(int c=0;c<(n*(n-1))/2-mini+1;c++)
            cout<<"|";
        cout<<":]";
    }
}