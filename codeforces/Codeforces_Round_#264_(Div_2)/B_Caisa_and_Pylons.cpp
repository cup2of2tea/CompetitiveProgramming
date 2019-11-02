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
    int e = 0;
    int h = 0;
    int res = 0;
    for(int c=0;c<n;c++)
    {
        int z;
        cin>>z;
        if(h-z<0&&z-h>e)
        {
            res+=z-h-e;
            e=0;
        }
        else
        {
            e+=h-z;
        }
        h=z;
    }
    cout<<res;
}