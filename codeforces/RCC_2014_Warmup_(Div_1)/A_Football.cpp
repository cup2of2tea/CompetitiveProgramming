#include <iostream>
#include <queue>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <set>
#include <sstream>
#include <iomanip>
using namespace std;
 
 
 
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    vector<vector<bool> > visites(n,vector<bool>(n,false));
    vector<pair<int,int> > res;
    for(int c=0;c<n;c++)
    {
        for(int c2=1;c2<=k;c2++)
        {
            if(visites[c][(c+c2)%n]||c==(c+c2)%n)
            {
                cout<<-1;
                return 0;
            }
            visites[c][(c+c2)%n]=true;
            visites[(c+c2)%n][c]=true;
            res.push_back(make_pair(c,(c+c2)%n));
        }
    }
    cout<<res.size()<<endl;
    for(int c=0;c<res.size();c++) cout<<res[c].first+1<<" "<<res[c].second+1<<endl;
}