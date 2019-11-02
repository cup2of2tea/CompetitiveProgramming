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
    int z;
    cin>>z;
    string s;
    cin>>s;
    int nb_I=0,nb_A=0;
    for(int c=0;c<s.size();c++)
    {
        if(s[c]=='I')
        {
            nb_I++;
        }
        else if(s[c]=='A')
            nb_A++;
    }
    if(nb_I>1)
    {
        cout<<0;
    }
    else
    {
        cout<<nb_I+(nb_I==1?0:nb_A);
    }
}