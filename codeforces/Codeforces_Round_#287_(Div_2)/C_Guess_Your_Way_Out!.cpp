#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
 
using namespace std;
 
 
long long lol(long long x,long long int exit,long long int depth,bool left)
{
    if(depth==x) return 0;
    if(((((exit-1)>>(depth-x-1))&1LL) == 0LL) == left)
    {
        return 1+lol(x+1,exit,depth,!left);
    }
    else
    {
        return (1LL<<(depth-x))+lol(x+1,exit,depth,left);
    }
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    #define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    long long int exit,depth;
    cin>>depth>>exit;
    cout<<lol(0,exit,depth,true);
}