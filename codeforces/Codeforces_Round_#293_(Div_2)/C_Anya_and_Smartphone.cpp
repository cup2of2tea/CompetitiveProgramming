#include <iostream>
#include <vector>
 
 
using namespace std;
 
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    
    vector<int> positions(n+1);
    vector<int> cases(n+1);
    for(int c=0;c<n;c++)
    {
        cin>>cases[c+1];
        positions[cases[c+1]] = c+1;
    }
    
    long long int res = 0;
    
    for(int c=0;c<m;c++)
    {
        int launch;
        cin>>launch;
        res+=(positions[launch]-1)/k+1;
        if(positions[launch] != 1)
        {
            swap(cases[positions[launch]-1],cases[positions[launch]]);
            positions[launch]--;
            positions[cases[positions[launch]+1]]=positions[launch]+1;
        }
    }
    cout<<res;
}
            
        