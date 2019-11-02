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
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int mini = 100000000;
    for(int c=0;c<=n;c++)
    {
        mini = min(mini,a*c+(n-c+m-1)/m*b);
    }
    cout<<mini;
}