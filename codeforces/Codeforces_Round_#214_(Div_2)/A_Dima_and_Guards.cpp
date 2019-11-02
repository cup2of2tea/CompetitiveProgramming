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
    for(int c=0;c<4;c++)
    {
        vector<vector<int> > cost(2,vector<int>(2));
        for(int c2=0;c2<2;c2++)
            for(int c3=0;c3<2;c3++)
                cin>>cost[c2][c3];
        vector<int> mini(2);
        for(int c2=0;c2<2;c2++)
        {
            mini[c2]=(*min_element(cost[c2].begin(),cost[c2].end()));
        }
        if(mini[0]+mini[1]<=n)
        {
            cout<<c+1<<" ";
            cout<<mini[0]<<" "<<n-mini[0]<<endl;
            return 0;
        }
    }
    cout<<-1;
}