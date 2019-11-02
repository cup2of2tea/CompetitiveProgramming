#include <iostream>
 
using namespace std;
 
int k;
 
int simulate(string s)
{
    char act = ' ';
    int count = 0 ;
    for(int c=0;c<=s.size();c++)
    {
        if(c<s.size() && s[c]==act)
        {
            count++;
        }
        else 
        {
            if(count >= 3)
            {
                return simulate(s.substr(0,c-count)+s.substr(c));
            }
            if(c == s.size()) break;
            act = s[c];
            count = 1;
        }
    }
    return s.size();
}
 
int main()
{
    string s;
    int n,x;
    cin>>n>>k>>x;
    string act = "";
    for(int c=0;c<n;c++)
    {
        int z;
        cin>>z;
        act = act+(char)(z+1);
    }
    int res = act.size();
    for(int c=0;c<=n;c++)
    {
        res = min(res,simulate(act.substr(0,c)+string(1,x+1)+(c!=n?act.substr(c):"")));
    }
    cout<<max(static_cast<int>(act.size())-res,0);
}
        