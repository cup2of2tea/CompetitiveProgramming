#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int N;
    cin>>N;
    int i=1;
    vector<int> presents(N+1,0);
    vector<int> v(N);
    for(int c=0;c<N;c++)
    {
        cin>>v[c];
        if(v[c]<=N)
        presents[v[c]]++;
    }
    for(int c=0;c<N;c++)
    {
        if(v[c]>=1 && v[c] <= N && presents[v[c]] == 1) cout<<v[c]<<" ";
        else
        {
            if(v[c]<=N)presents[v[c]]--;
            while(presents[i] != 0) i++;
            cout<<i<<" ";
            i++;
        }
    }
}