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
#endif
    int n;
    cin>>n;
    vector<int> v(n);
    for(int c=0;c<n;c++)
        cin>>v[c];
    sort(v.begin(),v.end());
    for(int c=1;c<v.size();c++)
        if(v[c]%v[0]!=0)
        {
            cout<<-1;
            return 0;
        }
    cout<<v[0];
}