#include <iostream>
 
using namespace std;
 
int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    int res = 0;
    for(int c=0;c<s.size();c++)
    {
        if((s.size()-c) <= k)
        {
            res = max(res,((int)s.size()-c+k)/2);
        }
        for(int c2=1;c2+c<=s.size();c2++)
        {
            string one = s.substr(c,min(c2,(int)s.size()-c-c2));
            string two = s.substr(c+c2,min(c2,(int)s.size()-c-c2));
            
            if(one == two && c+2*c2-((int)s.size()) <= k) res = max(res,c2);
        }
    }
    cout<<res*2;
}