#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <list>
#include <stack>
#include <limits.h>
#define ll long long
using namespace std;
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    #define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int N,M;
    cin>>N>>M;
    vector<int> v(N);
    for(int c=0;c<N;c++) v[c]=c+1;
    int bla=0;
    int maxi=0;
    do{
        int truc = 0;
        for(int c=0;c<N;c++)
        {
            int act = v[c];
            for(int c2=c;c2<N;c2++)
            {
                act=min(act,v[c2]);
                truc+=act;
            }
        }
        maxi=max(maxi,truc);
        if(truc==maxi) bla++;
        if(bla==M)
        {
            for(int c=0;c<v.size();c++) cout<<v[c]<<" ";
            return 0;
        }
    }while(next_permutation(v.begin(),v.end()));
}