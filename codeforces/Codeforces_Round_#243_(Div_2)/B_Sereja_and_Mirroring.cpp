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
    int n,m;
    cin>>n>>m;
    vector<vector<int> > v(n,vector<int>(m));
    for(int c=0;c<n;c++) for(int c2=0;c2<m;c2++) cin>>v[c][c2];
    int n2 = n;
    int c;
    for(c=0;n2>=1&&n2%2==0;c++)
    {
        for(int c2=0;c2<n2/2;c2++)
        {
            for(int c3=0;c3<m;c3++)
            {
                if(v[c2][c3]!=v[n2-1-c2][c3])
                {
                     goto end;
                }
            }
        }
        n2/=2;
    }
    end:
        cout<<n2<<endl;
 
}