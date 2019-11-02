#include <iostream>
#include <queue>
#include <cmath>
#include <iterator>
#include <algorithm>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<int> lights(n,1);
    vector<int> boutons(n,-1);
    for(int c=0;c<m;c++)
    {
        int z;
        cin>>z;
        for(int c2=n-1;c2>=z-1;c2--)
        {
            if(lights[c2]==1)
            {
                boutons[c2]=z;
                lights[c2]=0;
            }
        }
    }
    copy(boutons.begin(),boutons.end(),ostream_iterator<int>(cout," "));
}