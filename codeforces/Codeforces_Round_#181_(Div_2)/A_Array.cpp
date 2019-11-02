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
    vector<int> zero;
    vector<int> pos,neg;
    for(int c=0;c<n;c++)
    {
        cin>>v[c];
        if(v[c]==0||(v[c]>0&&pos.size()==1)||(v[c]<0&&neg.size()==1))
            zero.push_back(v[c]);
        else if(v[c]>0)
            pos.push_back(v[c]);
        else neg.push_back(v[c]);
    }
    sort(zero.begin(),zero.end());
    cout<<1<<" "<<neg[0]<<endl;
    if(pos.size()==0)
    {
        cout<<2<<" "<<zero[0]<<" "<<zero[1]<<endl;
    }
    else
        cout<<1<<" "<<pos[0]<<endl;
    cout<<zero.size()-(pos.size()==0?2:0)<<" ";
    for(int c=(pos.size()==0?2:0);c<zero.size();c++)
        cout<<zero[c]<<" ";
}