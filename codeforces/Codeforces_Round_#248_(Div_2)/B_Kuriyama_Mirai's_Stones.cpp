#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    vector<vector<long long int> > v(3,vector<long long int>(n));
    for(int c=0;c<n;c++) cin>>v[1][c];
    copy(v[1].begin(),v[1].end(),v[2].begin());
    sort(v[2].begin(),v[2].end());
    int m;
    cin>>m;
    vector<vector<long long int> > sum(3,vector<long long int>(n,0));
    for(int c=0;c<n;c++)
    {
        for(int c2=1;c2<=2;c2++)
        {
            sum[c2][c]+=v[c2][c];
            if(c>0)
            {
                sum[c2][c]+=sum[c2][c-1];
            }
         }
    }
    for(int c=0;c<m;c++)
    {
        int i,l,r;
        cin>>i>>l>>r;
        l--;
        r--;
        cout<<sum[i][r]-(l>0?sum[i][l-1]:0)<<endl;
    }
}