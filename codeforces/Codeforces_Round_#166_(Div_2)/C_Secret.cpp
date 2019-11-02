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
 
 
vector<int> premiers;
 
void precompute()
{
    premiers.push_back(2);
    for(int c=3;c<100100;c+=2)
    {
        for(int c2=0;c2<premiers.size();c2++)
            if(c%premiers[c2]==0)
                goto fail;
        premiers.push_back(c);
        fail:;
    }
}
 
 
int main(int argc,char **argv)
{
#ifdef LOCAL
    ifstream in("input.txt");
    ofstream out("output.txt");
#endif
    int n,k;
    cin>>n>>k;
    if(k*3>n)
    {
        cout<<-1;
    }
    else
    {
        for(int c=1;c<=k;c++)
        {
            cout<<(c!=1?" ":"")<<c<<" "<<c;
        }
        for(int c=2*k;c<n;c++)
        {
            cout<<" "<<(c%k)+1;
        }
    }
}