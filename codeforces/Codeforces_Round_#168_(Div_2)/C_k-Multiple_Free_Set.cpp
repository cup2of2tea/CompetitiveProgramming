#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <istream>
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
    int taille,k;
    cin>>taille>>k;
    if(k==1)
    {
        cout<<taille;
        return 0;
    }
    vector<int> v(taille);
    map<long long int,bool> present;
    for(int c=0;c<taille;c++)   cin>>v[c],present[v[c]]=true;
    sort(v.begin(),v.end());
    vector<vector<int> > suites;
    map<int,bool> traites;
    int res=0;
    for(int c=0;c<taille;c++)
    {
        if(traites[v[c]])
            continue;
        traites[v[c]]=true;
 
        if(present[static_cast<long long>(v[c])*static_cast<long long>(k)])
        {
            vector<int> add;
            long long int act=v[c];
            add.push_back(act);
            while(present[static_cast<long long>(act)*static_cast<long long>(k)])
            {
                act*=k;
                add.push_back(act);
                traites[act]=true;
            }
            suites.push_back(add);
        }
        else res++;
    }
    for(int c=0;c<suites.size();c++)
    {
        res+=(suites[c].size()+1)/2;
    }
    cout<<res<<endl;
}