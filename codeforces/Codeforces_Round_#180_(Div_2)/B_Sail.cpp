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
    int t,sx,sy,ex,ey;
    cin>>t>>sx>>sy>>ex>>ey;
    int z=0;
    string s;
    cin>>s;
    int i=0;
    while(i<s.size()&&(sx!=ex||sy!=ey))
    {
        if(s[i]=='E')
        {
            if(ex>sx)
                sx++;
        }
        if(s[i]=='W')
        {
            if(ex<sx)
                sx--;
        }
        if(s[i]=='N')
            if(ey>sy)
                sy++;
        if(s[i]=='S')
            if(ey<sy)
                sy--;
        i++;
    }
    if(sx!=ex||sy!=ey)
    {
        cout<<-1;
    }
    else cout<<i;
    return 0;
}