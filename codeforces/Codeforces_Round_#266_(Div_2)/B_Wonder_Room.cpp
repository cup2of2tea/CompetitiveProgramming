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
    long long int n,a,b;
    cin>>n>>a>>b;
    if(a*b >= n*6)
    {
        cout<<a*b<<endl<<a<<" "<<b;
        return 0;
    }
    long long int bestArea = 1e18;
    long long bestA = a;
    long long bestB = b;
    for(long long int c=min(a,b);c*c<=6*n;c++)
    {
        long long int c2 = (6*n+c-1)/c;
        if(c2 >= max(a,b))
        {
            if(bestArea > c2*c)
            {
                bestArea = c2*c;
                bestA = c;
                bestB = c2;
                if(a > b)
                {
                    swap(bestA,bestB);
                }
            }
        }
    }
    cout<<bestArea<<" "<<endl<<bestA<<" "<<bestB<<endl;
}