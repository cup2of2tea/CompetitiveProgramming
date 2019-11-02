#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <istream>
#include <algorithm>
#include <queue>
#include <cmath>
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
    int n,s,t;
    cin>>n>>s>>t;
    vector<int> transitions(n+1);
    vector<bool> visites(n,false);
    for(int c=0;c<n;c++)
        cin>>transitions[c+1];
    int act=s;
    int res=0;
    while(act!=t&&!visites[act])
    {
        visites[act]=true;
        act=transitions[act];
        res++;
    }
    if(act!=t)
    {
        cout<<-1;
    }
    else
    cout<<res;
}