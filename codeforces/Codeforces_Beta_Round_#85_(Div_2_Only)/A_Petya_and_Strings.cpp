#include <iostream>
using namespace std;
 
int main()
{
        string s1,s2;
        cin>>s1>>s2;
        for(int c=0;c<s1.size();c++)
                if(s1.at(c)>='A'&&s1.at(c)<='Z')
                        s1[c]=s1[c]-'A'+'a';
        for(int c=0;c<s2.size();c++)
                if(s2.at(c)>='A'&&s2.at(c)<='Z')
                        s2[c]=s2[c]-'A'+'a';
        for(int c=0;c<min(s1.size(),s2.size());c++)
                if(s1[c]>s2[c])
                {
                        cout<<1;
                        return 0;
                }
                else if(s1[c]!=s2[c])
                {
                        cout<<-1;
                        return 0;
                }
        if(s1.size()<s2.size())
                cout<<-1;
        else if(s1.size()!=s2.size())
                cout<<1;
        else
                cout<<0;
}