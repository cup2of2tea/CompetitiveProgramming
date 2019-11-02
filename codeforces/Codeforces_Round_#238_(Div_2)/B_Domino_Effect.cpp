#include <vector>
#include <iostream>
 
using namespace std;
 
int main()
{
    int N;
    cin>>N;
    string s;
    cin>>s;
    int res = 0;
    int deb = 0;
    for(deb=0;deb<s.size()&&s[deb]=='.';deb++);
    if(deb==s.size()) {cout<<s.size();return 0;}
    if(s[deb]=='R') res+=deb;
    int fin = s.size()-1;
    for(;fin>=0&&s[fin]=='.';fin--);
    if(s[fin]=='L') res+=s.size()-1-fin;
    for(int c=deb;c<=fin;c++)
    {
        if(s[c]=='R')
        {
            int c2;
            for(c2=c+1;c2<=fin&&s[c2]!='L';c2++);
            if((c2+c)%2==0)
            {
                res++;
            }
        }
    }
    bool oeilCyclone = (s[deb]=='L');
    for(int c=deb+1;c<=fin-1;c++)
    {
        if(s[c]=='R')
        {
            oeilCyclone=false;
        }
        else if(s[c]=='L')
        {
            oeilCyclone=true;
        }
        else if(oeilCyclone)
        {
            res++;
        }
   }
        
    cout<<res;
}
    
        