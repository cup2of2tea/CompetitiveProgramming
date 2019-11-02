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
 
 
bool comparaison(const int &a,const int &b)
{
    return abs(a)<abs(b);
}
 
 
int main(int argc,char **argv)
{
#ifdef LOCAL
    ifstream in("input.txt");
    ofstream out("output.txt");
#endif
    int n;
    cin>>n;
    int neg=0;
    vector<int> v(2*n-1);
    for(int c=0;c<v.size();c++)
        cin>>v[c];
    int sum=0;
    for(int c=0;c<v.size();c++)
        sum+=abs(v[c]);
    sort(v.begin(),v.end(),comparaison);
    for(int c=0;c<v.size();c++)
        if(v[c]<0)
            neg++;
    if(neg%2==0||n%2==1)
    {
        cout<<sum;
    }
    else cout<<sum-abs(2*v[0]);
}