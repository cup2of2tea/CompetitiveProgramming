#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int,int> pi;
 
int main()
{
    int n,z;
    cin>>n;
    map<int,int> m;
    for(int c=0;c<n;c++)
    {
        cin>>z;
        m[z]++;
    }
    cout<<(all_of(m.begin(),m.end(),[](pi p) {return p.second<=2||p.first==0;})?
        count_if (m.begin(), m.end(),[](pi p){return p.second==2&&p.first!=0;})
        :-1);
}