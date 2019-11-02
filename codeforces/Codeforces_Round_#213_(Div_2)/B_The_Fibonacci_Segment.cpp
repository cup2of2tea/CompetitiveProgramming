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
    int n;
    cin>>n;
    int first,second;
    if(n<=2)
    {
        cout<<n;
        return 0;
    }
    int res=2;
    int act=2;
    cin>>first>>second;
    for(int c=2;c<n;c++)
    {
        int z;
        cin>>z;
        if(first+second==z)
        {
            act++;
        }
        else act=2;
        first=second;
        second=z;
        res=max(res,act);
    }
    cout<<res;
}