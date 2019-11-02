#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    int N;
    cin>>N;
    vector<int> v(N);
    for(int c=0;c<N;c++) cin>>v[c];
    sort(v.rbegin(),v.rend());
    int droite = N/2;
    int res = 0;
    for(int c=0;c<N/2;c++)
    {
        for(;v[droite]*2>v[c]&&droite<N;droite++);
        if(droite < N)
        {
            droite++;
            res++;
        }
    }
    cout<<N-res;
}