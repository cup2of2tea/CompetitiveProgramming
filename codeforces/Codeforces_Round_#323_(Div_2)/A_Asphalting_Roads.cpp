#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;
 
long long mod = 1e9+7;
int main()
{
    int N;
    cin>>N;
    vector<bool > done(N,false);
    vector<bool> done2(N,false);
    int i = 1;
    for(int c=0;c<N;c++)
        for(int c2=0;c2<N;c2++)
        {
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            if(!done[x] && !done2[y]){
                cout<<i<<" ";
                done[x] = done2[y]=true;
            }
            i++;
        }
}