#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <ctime>
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
    int n;
    cin>>n;
    vector<long long int> compte((int)1e5+1,0);
    for(int c=0;c<n;c++)
    {
        long long int z;
        cin>>z;
        compte[z]+=z;
    }
    for(int c=0;c<compte.size();c++)
    {
 
        compte[c] = max((c-1>0?compte[c-1]:0LL),(c-2>0?compte[c-2]:0LL)+compte[c]);
    }
    cout<<compte[(int)1e5]<<endl;
}