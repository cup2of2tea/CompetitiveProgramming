#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
 
    int n,k;
    cin>>n>>k;
    int res=0;
    for(int c=0;c<n;c++)
    {
        int z=k+1;
        string s;
        cin>>s;
        vector<bool> v(k+1,false);
        for(int c2=0;c2<s.size();c2++)
        {
            int tmp=s[c2]-'0';
            if(tmp<k+1&&v[tmp]==false)
            {
                v[tmp]=true;
                z--;
            }
        }
        if(z==0) res++;
   }
   cout<<res;
}