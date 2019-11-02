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
    int n;
    cin>>n;
 
    if(n%4>=2&&n%4<=3)
    {
        cout<<-1<<endl;return 0;
    }
    int un=2;
    int deux=n;
    for(int c=0;c<n/2;c++)
    {
        cout<<un<<" "<<deux<<" ";
        un+=2;
        deux-=2;
        c++;
    }
    if(n%2==1)
        cout<<(n+1)/2<<" ";
    un-=3;
    deux++;
    for(int c=0;c<n/2;c++)
    {
        cout<<un<<" "<<deux<<" ";
        un-=2;
        deux+=2;
        c++;
    }
}//