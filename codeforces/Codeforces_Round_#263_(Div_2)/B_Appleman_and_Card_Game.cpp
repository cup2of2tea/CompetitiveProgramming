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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> v('Z'-'A'+1,0);
    for(int c=0;c<s.size();c++) v[s[c]-'A']++;
    sort(v.rbegin(),v.rend());
    int c=0;
    long long int res = 0;
    while(k)
    {
        int z = min(k,v[c]);
        k-=z;
        res+=static_cast<long long>(z)*static_cast<long long>(z);
        c++;
    }
    cout<<res;
}