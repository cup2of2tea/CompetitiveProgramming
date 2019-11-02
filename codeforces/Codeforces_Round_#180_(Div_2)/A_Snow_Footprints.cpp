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
    int z;
    string s;
    cin>>z>>s;
    int c;
    for(c=0;c<s.size();c++)
        if(s[c]!='.')
        {
            break;
        }
    if(s[c]=='L')
    {
        cout<<c+1<<" "<<c;
        return 0;
    }
    else
    {
        cout<<c+1<<" ";
    }
    for(int c2=c;c2<s.size();c2++)
        if(s[c]!=s[c2])
        {
            if(s[c2]!='.')
                cout<<c2;
            else    cout<<c2+1;
            break;
        }
    return 0;
}