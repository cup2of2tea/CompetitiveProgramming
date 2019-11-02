#include <iostream>
#include <map>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    map<int,int> Alice,Bob;
    for(int c=0;c<n;c++)
    {
        int type;
        cin>>type;
        Alice[type]++;
        Bob[type]=0;
    }
    for(int c=0;c<m;c++)
    {
        int type;
        cin>>type;
        Bob[type]++;
    }
    int sup = 0;
    for(map<int,int>::iterator it = Bob.begin(); it != Bob.end();it++)
    {
        sup += Alice[it->first] - (it->second);
        sup = max(sup,0);
    }
    cout<<(sup > 0? "YES":"NO");
}