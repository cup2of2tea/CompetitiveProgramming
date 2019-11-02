#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
 
int main()
{
    int N;
    cin>>N;
    int res =0;
    vector<string> board(N);
    for(int c=0;c<N;c++)
    {
        cin>>board[c];
        int act = 0;
        for(int c2=0;c2<=c;c2++)
        {
            act+=(board[c2]==board[c]?1:0);
        }
        res = max(res,act);
    }
    cout<<res;
}