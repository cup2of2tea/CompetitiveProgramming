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
 
 
 
int main(int argc,char **argv)
{
#ifdef LOCAL
    ifstream in("input.txt");
    ofstream out("output.txt");
#endif
    int n;
    cin>>n;
    vector<int> a(n);
    for(int c=0;c<n;c++)
        cin>>a[c];
    int m;
    cin>>m;
    long long taille_pile=0;
    for(int c=0;c<m;c++)
    {
        int w,h;
        cin>>w>>h;
        if(a[w-1]>taille_pile)
        {
            taille_pile=a[w-1]+h;
            cout<<a[w-1]<<endl;
        }
        else
        {
            cout<<taille_pile<<endl;
            taille_pile+=h;
        }
    }
}