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
#include <bitset>
 
 
#define LOCAL
#ifdef ONLINE_JUDGE
#define COUT(s)
#undef LOCAL
#endif
 
#ifdef LOCAL
#define cin in
 
#define COUT1(s) cout<<"----- "<<s<<" -----"<<endl;
#define COUT2(s,c) cout<<(string(7,c))<<" "<<s<<" "<<(string(7,c))<<endl;
 
#endif
 
using namespace std;
 
 
int main(int argc,char **argv)
{
 
#ifdef LOCAL
    ifstream in("input.txt");
#endif
    long long int N;
    cin>>N;
    long long z=1;
    while(N%z==0)
        z*=3;
    cout<<(N+z)/z;
}