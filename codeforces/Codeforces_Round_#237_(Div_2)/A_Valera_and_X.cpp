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
    vector<string> v(n);
    for(int c=0;c<n;c++) cin>>v[c];
    char car = v[0][0];
    char car2 =v[0][1];
    if(car==car2)
    {
        cout<<"NO";
        return 0;
    }
    for(int c=0;c<n;c++)
    {
        if(v[c][c]!=car||v[c][n-1-c]!=car||v[n-1-c][c]!=car||v[n-1-c][n-1-c]!=car)
        {
            cout<<"NO";
            return 0;
        }
        for(int c2=0;c2<n;c2++)
        {
            if(c==c2||c==n-1-c2) continue;
            if(v[c][c2]!=car2)
            {
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
}