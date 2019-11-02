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
    int n,t,c;
    cin>>n>>t>>c;
    int deb = 0;
    int res = 0;
    for(int p=0;p<n;p++)
    {
        int z;
        cin>>z;
        if(z>t)
        {
            deb = p+1;
        }
        else if(p-deb+1 == c)
        {
            res++;
            deb++;
        }
    }
    cout<<res;
}