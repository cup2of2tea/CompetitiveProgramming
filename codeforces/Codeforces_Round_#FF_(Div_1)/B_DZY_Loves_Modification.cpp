#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
 
vector<long long> solve(vector<long long> &sums,int dim,int p,int k)
{
    vector<long long> res(k+1,0);
    priority_queue<long long int> q;
    for(int c=0;c<sums.size();c++) q.push(sums[c]);
    for(int c=0;c<k;c++)
    {
        long long int t = q.top();
        q.pop();
        res[c+1] = res[c]+t;
        t -= dim * p;
        q.push(t);
    }
    return res;
}
 
 
 
int main()
{
    int n,m,p,k;
    cin>>n>>m>>k>>p;
    vector<long long int> sumCol(m,0),sumRow(n,0);
    for(int c=0;c<n;c++)
        for(int c2=0;c2<m;c2++)
        {
            int z ;
            cin>>z;
            sumCol[c2]+=z;
            sumRow[c]+=z;
        }
    vector<long long> r1 = solve(sumCol,n,p,k);
    vector<long long> r2 = solve(sumRow,m,p,k);
 
    long long res = 0;
    for(int c=0;c<=k;c++)
    {
        long long tmp = r1[c]+r2[k-c]-1LL*c*(k-c)*p;
        if(c==0||tmp > res) res = tmp;
    }
    cout<<res;
}