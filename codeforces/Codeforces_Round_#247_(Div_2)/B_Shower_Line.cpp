#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int simulate(vector<int> &v,vector<vector<int> > &m)
{
    int res = 0;
    for(int c=0;c<v.size();c++)
    {
        for(int c2=c;c2+1<v.size();c2+=2)
        {
            res+=m[v[c2]][v[c2+1]]+m[v[c2+1]][v[c2]];
        }
    }
    return res;
}
 
 
int main()
{
    vector<vector<int> > m(5,vector<int>(5));
    for(int c=0;c<5;c++) for(int c2=0;c2<5;c2++) cin>>m[c][c2];
    vector<int> permut(5,0);
    for(int c=0;c<5;c++) permut[c]=c;
    int res = 0;
    do
    {
 
        res = max(res,simulate(permut,m));
    }while(next_permutation(permut.begin(),permut.end()));
    cout<<res;
}