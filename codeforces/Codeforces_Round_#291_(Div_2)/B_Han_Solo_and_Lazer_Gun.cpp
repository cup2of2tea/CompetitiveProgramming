#include <iostream>
#include <random>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstdlib>
 
using namespace std;
 
 
int main()
{
    int N;
    cin>>N;
    int x0,y0;
    cin>>x0>>y0;
    vector<int> x(N);
    vector<int> y(N);
    for(int c=0;c<N;c++)
    {
        cin>>x[c]>>y[c];
    }
 
    vector<bool> done(N,false);
 
    int res=0;
    for(int c=0;c<N;c++)
    {
        if(done[c]) continue;
        res++;
        for(int c2=c+1;c2<N;c2++)
        {
            if((x[c]-x0)*(y[c2]-y0)-(x[c2]-x0)*(y[c]-y0) == 0) done[c2]=true;
        }
    }
    cout<<res;
}