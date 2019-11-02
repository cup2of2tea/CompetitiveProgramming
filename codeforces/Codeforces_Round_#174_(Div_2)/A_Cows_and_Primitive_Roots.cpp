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
    int p,res=0;
    cin>>p;
    for(int c=1;c<p;c++)
    {
        int act=c;
        for(int c2=0;c2<p-2;c2++)
        {
            if((act-1+p)%p==0)
            {
                goto nop;
            }
            act*=c;
            act%=p;
        }
        if((act-1+p)%p==0)
            res++;
        nop:;
    }
    cout<<res;
}