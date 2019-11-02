#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int N,M;
    cin>>N>>M;
    vector<int> v(N);
    for(int c=0;c<N;c++)
    {
        cin>>v[c];
    }
    int i=0,j=0;
    vector<bool> done(N,false);
    int compte = 0;
    int res = 0;
    while(compte != N)
    {
        int tmp = M;
        res++;
        for(int c=0;c<N;c++)
        {
            if(!done[c] && v[c] <= tmp)
            {
                done[c] = true;
                tmp -= v[c];
                compte++;
            }
            else if(!done[c]) break;
        }
   }
   cout<<res;
}