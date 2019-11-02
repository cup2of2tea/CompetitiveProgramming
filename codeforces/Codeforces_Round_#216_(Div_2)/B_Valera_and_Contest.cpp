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
 
 
 
 
int main()
{
 
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    #define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int n,k,l,r,sall,sk;
    cin>>n>>k>>l>>r>>sall>>sk;
    for(int c=0;c<k;c++)
    {
        cout<<(sk/k+(c<(sk%k)?1:0))<<" ";
    }
    for(int c=k;c<n;c++)
    {
        cout<<((sall-sk)/(n-k)+(c-k<((sall-sk)%(n-k))?1:0))<<" ";
    }
}