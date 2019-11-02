#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    string s;
    cin>>s;
    int c=0;
    while(s!="1")
    {
        c++;
        if(s[s.size()-1]=='0')
            s.erase(s.begin()+s.size()-1);
        else
        {
            int c;
            for(c=s.size()-1;c>=0&&s[c]=='1';c--) s[c]='0';
           if(c==-1)
            s='1'+s;
           else
            s[c]='1';
        }
        for(int c2=0;c2<10000000;c2++);
    }
    cout<<c;
}