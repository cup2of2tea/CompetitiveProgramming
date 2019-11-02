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
    int n;
    stack<int> v;
    v.push(0);
    cin>>n;
    long long act=0;
    vector<long long> decalage(2,0);
    for(int c=0;c<n;c++)
    {
        int op;
        cin>>op;
        if(op==3)
        {
            act-=decalage.back()+v.top();
            decalage[decalage.size()-2]+=decalage.back();
            decalage.pop_back();
            v.pop();
        }
        else if(op==2)
        {
            int k;
            cin>>k;
            v.push(k);
            decalage.push_back(0);
            act+=k;
        }
        else
        {
            int a,x;
            cin>>a>>x;
            decalage[a]+=x;
            act+=a*x;
        }
        cout<<fixed<<setprecision(9)<<(double)act/(double)v.size()<<endl;
    }
}