#include <iostream>
 
using namespace std;
 
int main()
{
    string s,s2;
    cin>>s>>s2;
    int tot = (s.size()+s2.size()-1);
    if(tot%2!=0)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    int c;
    for(c=0;s[c]!='|'&&c<s.size();c++);
    if(c>tot/2||s.size()-c-1>tot/2)
    {
        cout<<"Impossible";
        return 0;
    }
    int i =0;
    while(i<s2.size())
    {
        if(c>=tot/2)
        {
            s=s+s2[i];
        }
        else
        {
            c++;
            s=s2[i]+s;
        }
        i++;
   }
   cout<<s;
}