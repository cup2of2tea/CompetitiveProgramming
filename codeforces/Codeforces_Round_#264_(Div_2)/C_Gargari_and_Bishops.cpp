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
    int n;
    cin>>n;
    vector<vector<int> > chessboard(n,vector<int>(n));
    vector<long long int> diag1(n*2,0);
    vector<long long int> diag2(n*2,0);
    for(int c=0;c<n;c++)
    {
        for(int c2=0;c2<n;c2++)
        {
            cin>>chessboard[c][c2];
            diag1[c2-c+n]+=chessboard[c][c2];
            diag2[(n-c2-1)-c+n]+=chessboard[c][c2];
        }
    }
    vector<long long> bests(2,-1);
    vector<pair<int,int> > res(2);
 
    for(int c=0;c<n;c++)
    {
        for(int c2=0;c2<n;c2++)
        {
            long long score=diag1[c2-c+n]+diag2[(n-c2-1)-c+n]-chessboard[c][c2];
            if(score>bests[abs(c-c2)%2])
            {
                bests[abs(c-c2)%2]=score;
                res[abs(c-c2)%2]=make_pair(c+1,c2+1);
            }
        }
    }
    cout<<bests[0]+bests[1]<<endl;
    for(int c=0;c<res.size();c++) cout<<res[c].first<<" "<<res[c].second<<" ";
}