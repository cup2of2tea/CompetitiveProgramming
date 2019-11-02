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
    ofstream out("output2.txt");
#endif
    int n1,n2;
    cin>>n1>>n2;
    if(n1<n2||(n2==1&&n1!=1))
    {
        cout<<-1;
        return 0;
    }
    if(n2==1&&n1==1)
    {
        cout<<"a"; return 0;
       }
    for(int c=0;c<n1-(n2-2);c++)
    {
        cout<<(char)('a'+c%2);
    }
    for(int c=0;c<(n2-2);c++)
    {
        cout<<(char)('a'+c+2);
    }
}